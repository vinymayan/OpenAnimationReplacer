#pragma once

/*
* For modders: Copy this file into your own project if you wish to use this API
*/
namespace OAR_API::Animations
{
	// Available Open Animation Replacer interface versions
	enum class InterfaceVersion : uint8_t
	{
		V1,

		Latest = V1
	};

	struct ReplacementAnimationInfo
	{
		RE::BSString animationPath{};
		RE::BSString projectName{};
		RE::BSString variantFilename{};
		RE::BSString subModName{};
		RE::BSString modName{};
	};

	class IAnimationsInterface1
	{
	public:
		/// <summary>
		///	Gets information about the current replacement animation for a clip generator.
		///	</summary>
		///	<param name="a_clipGenerator">The clip generator to get the information for.</param>
		///	<returns>The information about the current replacement animation.</returns>
		[[nodiscard]] virtual ReplacementAnimationInfo GetCurrentReplacementAnimationInfo(RE::hkbClipGenerator* a_clipGenerator) noexcept = 0;

		/// <summary>
		///	Clears all condition state data related to a clip generator.
		///	</summary>
		/// <param name="a_clipGenerator">The clip generator to clear related condition state data for.</param>
		virtual void ClearConditionStateData(RE::hkbClipGenerator* a_clipGenerator) noexcept = 0;

		/// <summary>
		///	Clears all condition state data related to a refr.
		///	</summary>
		/// <param name="a_refr">The refr to clear related condition state data for.</param>
		virtual void ClearConditionStateData(RE::TESObjectREFR* a_refr) noexcept = 0;

		/// <summary>
		///	Reloads all animations and mod configurations.
		///	</summary>
		virtual void ReloadAnimations() noexcept = 0;

	};

	using IAnimationsInterface = IAnimationsInterface1;

	using _RequestPluginAPI_Animations = IAnimationsInterface* (*)(InterfaceVersion a_interfaceVersion, const char* a_pluginName, REL::Version a_pluginVersion);

	/// <summary>
	/// Request the Open Animation Replacer Animations API interface.
	/// </summary>
	/// <param name="a_interfaceVersion">The interface version to request</param>
	/// <returns>The pointer to the API singleton, or nullptr if request failed</returns>
	IAnimationsInterface* GetAPI(InterfaceVersion a_interfaceVersion = InterfaceVersion::Latest);
}

extern OAR_API::Animations::IAnimationsInterface* g_oarAnimationsInterface;

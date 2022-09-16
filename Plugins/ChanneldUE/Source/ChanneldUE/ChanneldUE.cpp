#include "ChanneldUE.h"
#include "Developer/Settings/Public/ISettingsModule.h"
#include "ChanneldSettings.h"
#include "Components/SceneComponent.h"
#include "GameFramework/Character.h"
#include "Replication/ChanneldReplicatorBase.h"
#include "Replication/ChanneldCharacterReplicator.h"
#include "Replication/ChanneldSceneComponentReplicator.h"
#include "Replication/ChanneldReplication.h"
#include "Replication/ChanneldPlayerControllerReplicator.h"

#define LOCTEXT_NAMESPACE "FChanneldUEModule"

void FChanneldUEModule::StartupModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->RegisterSettings("Project", "Plugins", "ChanneldSettings",
			LOCTEXT("RuntimeSettingsName", "Channeld"), 
			LOCTEXT("RuntimeSettingsDesc", ""),
			GetMutableDefault<UChanneldSettings>());
	}

	REGISTER_REPLICATOR(FChanneldSceneComponentReplicator, USceneComponent);
	REGISTER_REPLICATOR(FChanneldCharacterReplicator, ACharacter);
	REGISTER_REPLICATOR(FChanneldPlayerControllerReplicator, APlayerController);
}

void FChanneldUEModule::ShutdownModule()
{
	if (ISettingsModule* SettingsModule = FModuleManager::GetModulePtr<ISettingsModule>("Settings"))
	{
		SettingsModule->UnregisterSettings("Project", "Plugins", "ChanneldSettings");
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FChanneldUEModule, ChanneldUE)
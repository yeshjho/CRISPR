// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacterBase.h"

// Sets default values
AEnemyCharacterBase::AEnemyCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemyCharacterBase::BeginPlay()
{
	Super::BeginPlay();

	if (DataAsset.IsNull())
	{
		UE_LOG(LogActor, Error, TEXT("DataAsset is not set for actor %s"), *GetActorLabel());
		GEngine->AddOnScreenDebugMessage(-1, FLT_MAX, FColor::Red, FString{ "DataAsset is not set for actor " } + *GetActorLabel());
	}
}

// Called every frame
void AEnemyCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AEnemyCharacterBase::OnConstruction(const FTransform& Transform)
{
    Super::OnConstruction(Transform);

    UE::Math::TVector<double> location = Transform.GetLocation();
	location.Y = 0;

	SetActorLocation(location);
}


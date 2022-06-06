// Fill out your copyright notice in the Description page of Project Settings.


#include "BlasterHUD.h"

void ABlasterHUD::DrawHUD()
{
	Super::DrawHUD();

	FVector2D ViewPortSize;
	if (GEngine)
	{
		GEngine->GameViewport->GetViewportSize(ViewPortSize);
		const FVector2D ViewPortCenter(ViewPortSize.X / 2.f, ViewPortSize.Y / 2.f);

		if (HUDPackage.CrosshairsCenter)
		{
			DrawCrosshair(HUDPackage.CrosshairsCenter, ViewPortCenter);
		}
		if (HUDPackage.CrosshairsLeft)
		{
			DrawCrosshair(HUDPackage.CrosshairsLeft, ViewPortCenter);
		}
		if (HUDPackage.CrosshairsRight)
		{
			DrawCrosshair(HUDPackage.CrosshairsRight, ViewPortCenter);
		}
		if (HUDPackage.CrosshairsTop)
		{
			DrawCrosshair(HUDPackage.CrosshairsTop, ViewPortCenter);
		}
		if (HUDPackage.CrosshairsBottom)
		{
			DrawCrosshair(HUDPackage.CrosshairsBottom, ViewPortCenter);
		}
	}
}

void ABlasterHUD::DrawCrosshair(UTexture2D* Texture, FVector2D ViewPortCenter)
{
	const float TextureWidth = Texture->GetSizeX();
	const float TextureHeight = Texture->GetSizeY();
	const FVector2D TextureDrawPoint(
		ViewPortCenter.X - (TextureWidth / 2.f),
		ViewPortCenter.Y - (TextureHeight / 2.f)
	);

	DrawTexture(
		Texture,
		TextureDrawPoint.X,
		TextureDrawPoint.Y,
		TextureWidth,
		TextureHeight,
		0.f,
		0.f,
		1.f,
		1.f,
		FLinearColor::White
	);
}

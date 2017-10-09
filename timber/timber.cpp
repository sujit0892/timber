// timber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include <SFML/Graphics.hpp>
using namespace sf;
int main()
{
	int playerScore = 0;
	char playerInitial = 'J';
	float valuePi = 3.14f;
	bool isAlive = true;


	VideoMode vm(1366,768);
	RenderWindow window(vm, "Timber!!!", Style::Fullscreen);
	View view(sf::FloatRect(0, 0, 1920, 1080));
	window.setView(view);

	Texture textureBackground;
	textureBackground.loadFromFile("graphics/background.png");
	Sprite spriteBackground;
	spriteBackground.setTexture(textureBackground);
	spriteBackground.setPosition(0, 0);

	Texture textureTree;
	textureTree.loadFromFile("graphics/tree.png");
	Sprite spriteTree;
	spriteTree.setTexture(textureTree);
	spriteTree.setPosition(810, 0);

	Texture textureBee;
	textureBee.loadFromFile("graphics/bee.png");
	Sprite spriteBee;
	spriteBee.setTexture(textureBee);
	spriteBee.setPosition(0, 800);
	bool activeBee = false;
	float bee_speed = 0.0f;

	Texture textureCloud;
	textureCloud .loadFromFile("graphics/cloud.png");
	Sprite spriteCloud1;
	Sprite spriteCloud2;
	Sprite spriteCloud3;
	spriteCloud1.setTexture(textureCloud);
	spriteCloud2.setTexture(textureCloud);
	spriteCloud3.setTexture(textureCloud);
	spriteCloud1.setPosition(0, 0);
	spriteCloud2.setPosition(0, 150);
	spriteCloud3.setPosition(0, 300);
	bool activeCloud1 = false;
	bool activeCloud2 = false;
	bool activeCloud3 = false;
	float cloud1_speed = 0.0f;
	float cloud2_speed = 0.0f;
	float cloud3_speed = 0.0f;

	Clock clock;
	bool paused = false;

	while (window.isOpen()) {
		/*
		****************************************
		Handle the players input
		****************************************
		*/
		if (Keyboard::isKeyPressed(Keyboard::Escape)) {
			window.close();
		}

		if (Keyboard::isKeyPressed(Keyboard::Return)) {
			paused = true;
		}
		/*
		****************************************
		Update the scene
		****************************************
		*/
		if (!paused)
		{
			Time dt = clock.restart();
			if (!activeBee)
			{
				srand((int)time(0) * 10);
				bee_speed = (rand() % 200) + 200;

				srand((int)time(0) * 10);
				float height = (rand() % 500) + 500;
				spriteBee.setPosition(2000, height);
				activeBee = true;

			}
			else
			{

				spriteBee.setPosition(spriteBee.getPosition().x - (bee_speed * dt.asSeconds()), spriteBee.getPosition().y);
				if (spriteBee.getPosition().x < -100)
					activeBee = false;
			}


			if (!activeCloud1)
			{
				srand((int)time(0) * 10);
				cloud1_speed = (rand() % 200);

				srand((int)time(0) * 10);
				float height = (rand() % 150);
				spriteCloud1.setPosition(-200, height);
				activeCloud1 = true;

			}
			else
			{

				spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1_speed * dt.asSeconds()), spriteCloud1.getPosition().y);
				if (spriteCloud1.getPosition().x > 1920)
				{
					activeCloud1 = false;
				}
			}

			if (!activeCloud2)
			{
				srand((int)time(0) * 10);
				cloud2_speed = (rand() % 200);

				srand((int)time(0) * 10);
				float height = (rand() % 300) - 150;
				spriteCloud2.setPosition(-200, height);
				activeCloud2 = true;
			}
			else
			{
				spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloud2_speed * dt.asSeconds()), spriteCloud2.getPosition().y);
				if (spriteCloud2.getPosition().x > 1920)
				{
					activeCloud2 = false;
				}

			}

			if (!activeCloud3)
			{
				srand((int)time(0) * 30);
				cloud3_speed = (rand() % 200);

				srand((int)time(0) * 30);
				float height = (rand() % 450) - 300;
				spriteCloud3.setPosition(-200, height);
				activeCloud3 = true;
			}
			else
			{
				spriteCloud3.setPosition(spriteCloud3.getPosition().x + (cloud3_speed * dt.asSeconds()), spriteCloud3.getPosition().y);
				if (spriteCloud3.getPosition().x > 1920)
				{
					activeCloud3 = false;
				}
			}
		}
		/*
		****************************************
		Draw the scene
		****************************************
		*/

		window.clear();


		
		window.draw(spriteBackground);
		window.draw(spriteBee);
		window.draw(spriteTree);
		window.draw(spriteCloud1);
		window.draw(spriteCloud2);
		window.draw(spriteCloud3);

		
		window.display();
	}


	return 0;
}
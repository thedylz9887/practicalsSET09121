#pragma once

#include <SFML/Graphics.hpp>
#include <memory>

class Entity
{
	protected:
		//smart pointer that deletes the memory stored for the shape when the shape is out of scope 
		std::unique_ptr<sf::Shape> _shape;
		//stores the position of the entity
		sf::Vector2f _position;
		//construct for entity class
		Entity(std::unique_ptr<sf::Shape> shp);
	
	public:
		//deconstructer for entity class
		Entity() = delete;
		virtual ~Entity() = default;
		
		//allowing the update and render parent classes to be overridden
		virtual void update(const double dt);
		virtual void render(sf::RenderWindow &window) const = 0;
		
		//getter and setter the positioning of the shape that will be moved
		const sf::Vector2f getPosition();
		void setPosition(const sf::Vector2f &pos);
		void move(const sf::Vector2f &pos);
};
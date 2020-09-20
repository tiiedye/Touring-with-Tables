#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

struct City {
    std::string name;
    long population;
    double cost;
};

// Assume each country has at least 1 city
struct Country {
    std::string name;
    std::vector<City> cities;
};

struct Tours {
    std::string title;
    std::vector<Country> countries;
};

int main() {
    Tours tours
    { "Tour Ticket Prices from Miami",
        {
            {
                "Colombia", {
                    { "Bogota", 8778000, 400.98 },
                    { "Cali", 2401000, 424.12 },
                    { "Medellin", 2464000, 350.98 },
                    { "Cartagena", 972000, 345.34 }
                },
            },
            {
                "Brazil", {
                    { "Rio De Janiero", 13500000, 567.45 },
                    { "Sao Paulo", 11310000, 975.45 },
                    { "Salvador", 18234000, 855.99 }
                },
            },
            {
                "Chile", {
                    { "Valdivia", 260000, 569.12 },
                    { "Santiago", 7040000, 520.00 }
            },
        },
            { "Argentina", {
                { "Buenos Aires", 3010000, 723.77 }
            }
        },
    }
    };

    // finds the length of the title
    int title_length = tours.title.length();
    // sets the total width of the table, and elements on the table
    const int total_width{ 70 };
    const int country_width{ 20 };
    const int city_width{ 20 };
    const int population_width{ 15 };
    const int cost_width{ 15 };


    // displays the title and a line to seperate the title of the table and the content of the table
    std::cout << std::setw((total_width - title_length) / 2) << "" << tours.title << std::endl;
    std::cout << std::setw(total_width) << std::setfill('=') << "" << std::endl;
    std::cout << std::setfill(' ') << std::endl; // resets setfil to a blank space.

    // displays the titles of the columns in the table
    std::cout << std::setw(country_width) << std::left << "Country"
        << std::setw(city_width) << std::left << "City"
        << std::setw(population_width) << std::left << "Population"
        << std::setw(cost_width) << std::right << "Cost" << std::endl;

    std::cout << std::setw(total_width) << std::setfill('-') << "" << std::endl;
    std::cout << std::setfill(' ');

    for (auto country : tours.countries) {   // loop through the countries
        std::cout << country.name << std::endl;
        for (auto city : country.cities) {       // loop through the cities for each country
            std::cout << "\t" << city.name
                << "\t" << city.population
                << "\t" << city.cost
                << std::endl;
        }
    }

    std::cout << std::endl << std::endl;
    return 0;
}
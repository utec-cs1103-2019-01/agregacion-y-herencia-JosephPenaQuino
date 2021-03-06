#include "catch.hpp"
#include "Library.h"
#include "Volume.h"
#include "Book.h"
#include "Magazine.h"
#include <iostream>
#include <string>

SCENARIO("Inheritance and Aggregation in CPP")
{

    GIVEN("Volume: Books and Magazines")
    {
        WHEN("Instance a Book")
        {
            Book * test_book = new Book(1, "Clean Architecture", 1);
            THEN("Show book details")
            {
                std::cout << "-------------------------------------------------------------------------------" << std::endl;
                std::cout << "Volume: Books and Magazines" << std::endl;
                std::cout << "-------------------------------------------------------------------------------" << std::endl;
                test_book->show();
            }
        }
        WHEN("Instance a Magazine")
        {
            Magazine * test_magazine = new Magazine(1, "Forbes", 2);
            THEN("Show magazine details")
            {
                test_magazine->show();
            }
        }
    }
    GIVEN("Library")
    {
        WHEN("Adding many Books and Magazines")
        {
            bool all_correct = true;
            Library my_library(5, 5);
            std::string names[] = {
                    "The Great Gatsby",
                    "People",
                    "To Kill a Mockingbird",
                    "Family Circle",
                    "Harry Potter and the Sorcerer's Stone",
                    "Time",
                    "The Catcher in the Rye",
                    "Better Homes",
                    "Every Other Harry Potter Book",
                    "Game in Former"
            };
            std::cout << "-------------------------------------------------------------------------------" << std::endl;
            std::cout << "Library" << std::endl;
            std::cout << "-------------------------------------------------------------------------------" << std::endl;
            for (int i = 1; i <= 10; i+=2)
            {
                Book * book = new Book(i/2 +1, names[i/2], i);
                Magazine * magazine = new Magazine(i/2+1, names[1+i/2], i+1);
                all_correct = all_correct && my_library.include(book);
                all_correct = all_correct && my_library.include(magazine);
            }

            THEN("Show Library details")
            {
                my_library.show_library();
                REQUIRE(all_correct);
            }
        }
    }
}
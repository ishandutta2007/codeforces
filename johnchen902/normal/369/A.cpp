#include <iostream>
#include <algorithm>

int main() {
    int days, bowls, plates, washes = 0;
    std::cin >> days >> bowls >> plates;
    while(days--) {
        int dish;
        std::cin >> dish;
        if(dish == 1) {
            if(bowls)
                bowls--;
            else
                washes++;
        } else {
            if(plates)
                plates--;
            else if(bowls)
                bowls--;
            else
                washes++;
        }
    }
    std::cout << washes << std::endl;
}
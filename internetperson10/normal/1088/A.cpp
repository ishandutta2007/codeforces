#include <iostream>

int main() {
    int x;
    std::cin >> x;
    if(x == 1) {
        std::cout << "-1\n";
    }
    else {
        std::cout << x << ' ' << x << '\n';
    }
}
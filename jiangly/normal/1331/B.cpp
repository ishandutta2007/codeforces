#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int a;
    std::cin >> a;
    for (int i = 2; ; ++i) {
        if (a % i == 0) {
            std::cout << i << a / i << "\n";
            return 0;
        }
    }
}
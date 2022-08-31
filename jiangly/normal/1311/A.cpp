// lg
#include <iostream>
int t, a, b;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> a >> b;
        if (a == b) {
            std::cout << 0 << "\n";
        } else if (b > a && (b - a) % 2 == 1 || b < a && (a - b) % 2 == 0) {
            std::cout << 1 << "\n";
        } else {
            std::cout << 2 << "\n";
        }
    }
    return 0;
}
#include <iostream>
int t, n;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> n;
        if (n % 2 == 0) {
            std::cout << std::string(n / 2, '1') << "\n";
        } else {
            std::cout << '7' + std::string((n - 3) / 2, '1') << "\n";
        }
    }
    return 0;
}
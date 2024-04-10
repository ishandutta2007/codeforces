#include <iostream>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        if (n == 1) {
            std::cout << -1 << "\n";
        } else {
            std::cout << std::string(n - 2, '7') + "57" << "\n";
        }
    }
    return 0;
}
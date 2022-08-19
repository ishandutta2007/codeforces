#include <iostream>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int a, b;
        std::cin >> a >> b;
        ++b;
        std::cout << 1LL * a * (std::to_string(b).length() - 1) << "\n";
    }
    return 0;
}
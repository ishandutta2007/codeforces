#include <iostream>
int t, n, x, y;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> n >> x >> y;
        std::cout << std::min(n, std::max(1, x + y - n + 1)) << " " << std::min(n, x + y - 1) << "\n";
    }
    return 0;
}
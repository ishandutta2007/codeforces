#include <iostream>
int t, x, y, a, b;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> t;
    while (t--) {
        std::cin >> x >> y >> a >> b;
        if ((y - x) % (a + b) != 0) {
            std::cout << -1 << "\n";
        } else {
            std::cout << (y - x) / (a + b) << "\n";
        }
    }
    return 0;
}
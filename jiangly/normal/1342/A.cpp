#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int x, y;
        std::cin >> x >> y;
        int a, b;
        std::cin >> a >> b;
        if (x > y)
            std::swap(x, y);
        std::cout << 1ll * std::min(2 * a, b) * x + 1ll * a * (y - x) << "\n";
    }
    return 0;
}
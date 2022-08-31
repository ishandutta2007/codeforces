#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int x, n, m;
        std::cin >> x >> n >> m;
        for (int i = 0; i < n; ++i)
            x = std::min(x, x / 2 + 10);
        x -= 10 * m;
        if (x <= 0) {
            std::cout << "YES" << "\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
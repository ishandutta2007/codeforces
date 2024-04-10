#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, x, m;
        std::cin >> n >> x >> m;
        int a = x, b = x;
        for (int i = 0; i < m; ++i) {
            int l, r;
            std::cin >> l >> r;
            if (l <= b && a <= r) {
                a = std::min(a, l);
                b = std::max(b, r);
            }
        }
        std::cout << b - a + 1 << "\n";
    }
    return 0;
}
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
        int n, pre = -1e9;
        std::cin >> n;
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            pre = std::max(pre, x);
            if (pre > x)
                ans = std::max(ans, std::__lg(pre - x) + 1);
        }
        std::cout << ans << "\n";
    }
    return 0;
}
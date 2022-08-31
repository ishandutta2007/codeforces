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
        int n;
        std::cin >> n;
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            if (i == n || i < n / 2) {
                ans += 1 << i;
            } else {
                ans -= 1 << i;
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <set>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int ans = std::__lg(n);
        std::cout << ans << "\n";
        for (int i = 0, j = 1; i < ans; ++i) {
            n -= j;
            int k = std::min(n / (ans - i), 2 * j);
            std::cout << k - j << " \n"[i == ans - 1];
            j = k;
        }
    }
    return 0;
}
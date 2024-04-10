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
        int n, k;
        std::cin >> n >> k;
        std::vector<int> a(n), b(n);
        for (int i = 0; i < n; ++i)
            std::cin >> a[i];
        for (int i = 0; i < n; ++i)
            std::cin >> b[i];
        std::sort(a.begin(), a.end());
        std::sort(b.begin(), b.end(), std::greater<>());
        int ans = std::accumulate(a.begin(), a.end(), 0);
        for (int i = 0; i < k; ++i) {
            if (a[i] > b[i])
                break;
            ans += b[i] - a[i];
        }
        std::cout << ans << "\n";
    }
    return 0;
}
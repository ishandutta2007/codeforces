#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }
        int64_t sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            sum += std::abs(a[i] - a[i + 1]);
        }
        int ans = std::max(std::abs(a[0] - a[1]), std::abs(a[n - 2] - a[n - 1]));
        for (int i = 1; i < n - 1; ++i) {
            ans = std::max(ans, std::abs(a[i] - a[i - 1]) + std::abs(a[i] - a[i + 1]) - std::abs(a[i - 1] - a[i + 1]));
        }
        std::cout << sum - ans << "\n";
    }
    
    return 0;
}
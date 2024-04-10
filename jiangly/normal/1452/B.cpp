#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        int mx = 0;
        int64_t sum = 0;
        for (int i = 0; i < n; ++i) {
            int x;
            std::cin >> x;
            mx = std::max(mx, x);
            sum += x;
        }
        int64_t ans = std::max<int64_t>((sum + n - 2) / (n - 1), mx) * (n - 1) - sum;
        std::cout << ans << "\n";
    }
    
    return 0;
}
#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    if (n > 60) {
        std::cout << 1 << "\n";
        return 0;
    }
    
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    
    int dp[61][61] {};
    int ans = n;
    for (int i = 0; i <= n; ++i) {
        int x = 0;
        for (int j = i + 1; j <= n; ++j) {
            x ^= a[j - 1];
            for (int t = 0; t <= i; ++t) {
                if (x < dp[i][t]) ans = std::min(ans, t + j - i - 1);
                else dp[j][t + j - i - 1] = std::max(dp[j][t + j - i - 1], x);
            }
        }
    }
    
    if (ans >= n) ans = -1;
    std::cout << ans << "\n";
    
    return 0;
}
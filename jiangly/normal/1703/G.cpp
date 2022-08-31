#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<i64> dp(n + 1);
    for (int i = 0; i < n; i++) {
        dp[i + 1] = dp[i] + a[i] - k;
    }
    i64 ans = *std::max_element(dp.begin(), dp.end());
    
    for (int x = 1; x <= 30; x++) {
        std::vector<i64> g(n + 1);
        for (int i = 1; i <= n; i++) {
            g[i] = std::max(g[i - 1] - k, dp[i - 1]) + (a[i - 1] >> x);
            ans = std::max(ans, g[i]);
        }
        dp = g;
    }
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
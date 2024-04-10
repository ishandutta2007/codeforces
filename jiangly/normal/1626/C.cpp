#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E18;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> k(n), h(n);
    for (int i = 0; i < n; i++) {
        std::cin >> k[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> h[i];
    }
    
    for (int i = n - 1; i > 0; i--) {
        h[i - 1] = std::max(h[i - 1], h[i] - k[i] + k[i - 1]);
    }
    
    std::vector<i64> dp(n + 1, inf);
    dp[0] = 0;
    for (int l = 0; l < n; l++) {
        int v = h[l] - k[l];
        for (int r = l; r < n; r++) {
            v = std::max(v, h[r] - k[r]);
            if (l == 0 || k[l] - h[l] >= k[l - 1]) {
                dp[r + 1] = std::min(dp[r + 1], dp[l] + 1LL * (v + k[r]) * (v + k[r] + 1) / 2);
            }
        }
    }
    
    std::cout << dp[n] << "\n";
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
#include <bits/stdc++.h>

using i64 = long long;

constexpr int N = 2000;

void solve() {
    int n;
    std::cin >> n;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int dp[N + 1] = {};
    for (int i = 0; i < n; i++) {
        int g[N + 1];
        std::fill(g, g + N + 1, 1E9);
        for (int j = 0; j <= N; j++) {
            int nj = std::max(0, j - a[i]);
            g[nj] = std::min(g[nj], a[i] + dp[j]);
            nj = j + a[i];
            if (nj <= N) {
                g[nj] = std::min(g[nj], std::max(0, dp[j] - a[i]));
            }
        }
        std::swap(dp, g);
    }
    
    int res = 1E9;
    for (int i = 0; i <= N; i++) {
        res = std::min(res, i + dp[i]);
    }
    
    std::cout << res << "\n";
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
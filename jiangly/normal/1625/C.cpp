#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = 1E9;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, l, k;
    std::cin >> n >> l >> k;
    
    std::vector<int> d(n + 1), a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> d[i];
    }
    d[n] = l;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector dp(n + 1, std::vector(n + 1, inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            for (int x = i + 1; x <= n; x++) {
                dp[x][j + 1] = std::min(dp[x][j + 1], dp[i][j] + a[i] * (d[x] - d[i]));
            }
        }
    }
    
    int ans = inf;
    for (int j = n - k; j <= n; j++) {
        ans = std::min(ans, dp[n][j]);
    }
    
    std::cout << ans << "\n";
    
    return 0;
}
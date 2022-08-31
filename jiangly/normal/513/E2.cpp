#include <bits/stdc++.h>
using i64 = long long;
constexpr int inf = 1e9;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    std::vector<int> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] + a[i];
    }
    std::vector dp(n + 1, std::vector<int>(2, -inf));
    dp[0][0] = 0;
    int mx[2][2];
    int g[2];
    int ans = 0;
    for (int t = 1; t <= k; t++) {
        for (int x = 0; x < 2; x++) {
            for (int y = 0; y < 2; y++) {
                mx[x][y] = -inf;
            }
            g[x] = -inf;
        }
        for (int i = 0; i <= n; i++) {
            auto temp = dp[i];
            dp[i][0] = dp[i][1] = -inf;
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    if (t == k) {
                        ans = std::max(ans, mx[x][y] + (x == 0 ? -1 : 1) * s[i]);
                    } else {
                        dp[i][y] = std::max(dp[i][y], ((t > 1) * (x == 0 ? -1 : 1) + (y == 0 ? 1 : -1)) * s[i] + mx[x][y]);
                    }
                }
            }
            for (int x = 0; x < 2; x++) {
                g[x] = std::max(g[x], temp[x]);
            }
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    mx[x][y] = std::max(mx[x][y], g[x] + ((t > 1) * (x == 0 ? 1 : -1) + (t < k) * (y == 0 ? -1 : 1)) * s[i]);
                }
            }
        }
    }
    std::cout << ans << "\n";
    return 0;
}
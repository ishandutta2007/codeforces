#include <bits/stdc++.h>

using i64 = long long;

constexpr int inf = std::numeric_limits<int>::max();

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector dp(3, std::vector<int>(16, -inf));
    dp[0][0] = dp[1][0] = 0;
    for (int i = 0; i < n; i++) {
        std::vector g(3, std::vector<int>(16, -inf));
        for (int j = 0; j <= 2; j++) {
            for (int s = 0; s < 16; s++) {
                if (dp[j][s] == -inf) {
                    continue;
                }
                for (int t = 0; t < 4; t++) {
                    int f = t << (j % 2 * 2);
                    if (s & f) {
                        continue;
                    }
                    int ns = s | f;
                    int val = (t & 1) * a[i] - (t >> 1 & 1) * a[i];
                    g[j][ns] = std::max(g[j][ns], dp[j][s] + val);
                    if (j < 2) {
                        g[j + 1][ns] = std::max(g[j + 1][ns], dp[j][s] + val);
                    }
                }
            }
        }
        dp = g;
    }
    
    std::cout << dp[2][15] << "\n";
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
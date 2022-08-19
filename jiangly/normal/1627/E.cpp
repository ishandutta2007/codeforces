#include <bits/stdc++.h>

using i64 = long long;

constexpr i64 inf = 1E18;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::vector<int> x(n);
    for (int i = 0; i < n; i++) {
        std::cin >> x[i];
    }
    
    std::vector<std::vector<int>> p(n);
    p[0].push_back(0);
    p[n - 1].push_back(m - 1);
    
    std::vector<std::vector<std::array<int, 4>>> e(n);
    for (int i = 0; i < k; i++) {
        int a, b, c, d, h;
        std::cin >> a >> b >> c >> d >> h;
        a--;
        b--;
        c--;
        d--;
        e[a].push_back({b, c, d, h});
        p[a].push_back(b);
        p[c].push_back(d);
    }
    
    for (int i = 0; i < n; i++) {
        std::sort(p[i].begin(), p[i].end());
        p[i].erase(std::unique(p[i].begin(), p[i].end()), p[i].end());
    }
    
    std::vector<std::vector<i64>> dp(n);
    for (int i = 0; i < n; i++) {
        dp[i].resize(p[i].size(), inf);
    }
    dp[0][0] = 0;
    
    for (int i = 0; i < n; i++) {
        int t = p[i].size();
        for (int j = 0; j + 1 < t; j++) {
            dp[i][j + 1] = std::min(dp[i][j + 1], dp[i][j] + 1LL * x[i] * (p[i][j + 1] - p[i][j]));
        }
        for (int j = t - 1; j > 0; j--) {
            dp[i][j - 1] = std::min(dp[i][j - 1], dp[i][j] + 1LL * x[i] * (p[i][j] - p[i][j - 1]));
        }
        for (auto [b, c, d, h] : e[i]) {
            int x = std::lower_bound(p[i].begin(), p[i].end(), b) - p[i].begin();
            int y = std::lower_bound(p[c].begin(), p[c].end(), d) - p[c].begin();
            dp[c][y] = std::min(dp[c][y], dp[i][x] - h);
        }
    }
    
    i64 ans = dp[n - 1].back();
    if (ans > 1E17) {
        std::cout << "NO ESCAPE\n";
    } else {
        std::cout << ans << "\n";
    }
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
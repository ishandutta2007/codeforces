#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    int a[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::sort(a, a + n);
    
    std::vector<std::pair<int, int>> seg[n + 1];
    
    for (int i = 0; i < m; i++) {
        int l, r;
        std::cin >> l >> r;
        int j = std::lower_bound(a, a + n, l) - a;
        if (j < n && r >= a[j]) {
            continue;
        }
        seg[j].emplace_back(l, r);
    }
    
    for (int i = 0; i <= n; i++) {
        std::sort(seg[i].begin(), seg[i].end());
        
        std::vector<std::pair<int, int>> temp;
        for (auto [l, r] : seg[i]) {
            if (!temp.empty() && temp.back().first == l) {
                continue;
            }
            while (!temp.empty() && temp.back().second >= r) {
                temp.pop_back();
            }
            temp.emplace_back(l, r);
        }
        
        seg[i] = temp;
    }
    
    for (int i = 0; i < n; i++) {
        seg[i].emplace_back(a[i], a[i]);
        seg[i + 1].insert(seg[i + 1].begin(), std::make_pair(a[i], a[i]));
    }
    
    i64 dp[2] = {};
    dp[0] = a[0] - seg[0][0].second;
    dp[1] = 2 * dp[0];
    
    i64 res = 1E18;
    
    for (int i = 1; i < n; i++) {
        i64 g[2];
        g[0] = g[1] = 1E18;
        for (int j = 0; j < int(seg[i].size()) - 1; j++) {
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    g[x] = std::min(g[x], dp[y] + (2LL - y) * (seg[i][j].first - a[i - 1]) + (1LL + x) * (a[i] - seg[i][j + 1].second));
                }
            }
        }
        dp[0] = g[0];
        dp[1] = g[1];
    }
    
    for (int y = 0; y < 2; y++) {
        res = std::min(res, dp[y] + (2LL - y) * (seg[n].back().first - a[n - 1]));
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
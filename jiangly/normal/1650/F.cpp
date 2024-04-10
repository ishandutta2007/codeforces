#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> lim(n);
    for (int i = 0; i < n; i++) {
        std::cin >> lim[i];
    }
    
    std::vector<std::vector<std::array<int, 3>>> a(n);
    for (int i = 0; i < m; i++) {
        int e, t, p;
        std::cin >> e >> t >> p;
        e--;
        a[e].push_back({t, p, i});
    }
    
    std::vector<int> ans;
    
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int N = a[i].size();
        std::vector dp(N + 1, std::vector<int>(101, 1E9 + 1));
        dp[0][0] = 0;
        for (int j = 0; j < N; j++) {
            dp[j + 1] = dp[j];
            auto [t, p, _] = a[i][j];
            for (int k = 0; k <= 100; k++) {
                int nk = std::min(100, k + p);
                dp[j + 1][nk] = std::min(dp[j + 1][nk], dp[j][k] + t);
            }
        }
        
        cur += dp[N][100];
        
        if (cur > lim[i]) {
            std::cout << "-1\n";
            return;
        }
        
        int nd = 100;
        for (int j = N - 1; j >= 0; j--) {
            auto [t, p, id] = a[i][j];
            if (dp[j + 1][nd] == dp[j][nd]) {
                continue;
            }
            ans.push_back(id);
            for (int k = 0; k <= 100; k++) {
                int nk = std::min(100, k + p);
                if (nk == nd && dp[j][k] + t == dp[j + 1][nk]) {
                    nd = k;
                    break;
                }
            }
        }
    }
    
    std::cout << ans.size() << "\n";
    for (int i = 0; i < int(ans.size()); i++) {
        std::cout << ans[i] + 1 << " \n"[i == int(ans.size()) - 1];
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
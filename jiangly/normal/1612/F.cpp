#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    int q;
    std::cin >> q;
    
    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < q; i++) {
        int x, y;
        std::cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
    }
    
    for (int i = 0; i < n; i++) {
        std::sort(adj[i].begin(), adj[i].end());
    }
    
    std::vector<int> cur(n);
    
    std::vector<int> dp(n, -1);
    dp[0] = 0;
    int ans = 0;
    
    std::vector<int> f(n), g(m);
    for (int i = n - 2; i >= 0; i--) {
        f[i] = 1 + f[std::min(n - 1, i + m + std::binary_search(adj[i].begin(), adj[i].end(), m - 1))];
    }
    for (int i = m - 2; i >= 0; i--) {
        g[i] = 1 + g[std::min(m - 1, i + n + std::binary_search(adj[n - 1].begin(), adj[n - 1].end(), i))];
    }
    
    int res = 1E9;
    for (int _ = 0; _ < 40; _++) {
        std::vector<int> ndp(dp);
        for (int i = 0; i < n; i++) {
            if (dp[i] == m - 1) {
                res = std::min(res, _ + f[i]);
            }
            if (dp[i] == -1) {
                continue;
            }
            while (cur[i] < int(adj[i].size()) && adj[i][cur[i]] < dp[i]) {
                cur[i]++;
            }
            int k = i + dp[i] + 1;
            if (cur[i] < int(adj[i].size()) && adj[i][cur[i]] == dp[i]) {
                k++;
            }
            int nj = std::min(k, m - 1);
            ndp[i] = std::max(ndp[i], nj);
            int ni = std::min(k, n - 1);
            ndp[ni] = std::max(ndp[ni], dp[i]);
        }
        if (dp[n - 1] != -1) {
            res = std::min(res, _ + g[dp[n - 1]]);
        }
        dp = ndp;
    }
    
    std::cout << res << '\n';
    
    return 0;
}
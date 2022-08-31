#include <bits/stdc++.h>

constexpr int P = 1000000007;

constexpr int M = 4000;
int dp[2][2][8001];
void add(int &a, int b) {
    a += b;
    if (a >= P) a -= P;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    std::vector<int> len;
    std::vector<bool> vis(n);
    for (auto x : e[0]) {
        if (vis[x]) continue;
        int lst = 0;
        int l = 1;
        while (x != 0) {
            vis[x] = true;
            ++l;
            int tmp = x;
            x = e[x][0] ^ e[x][1] ^ lst;
            lst = tmp;
        }
        len.push_back(l);
    }
    dp[0][0][M] = 1;
    int cur = 0;
    for (auto l : len) {
        cur ^= 1;
        std::memset(dp[cur], 0, sizeof(dp[cur]));
        for (int t = 0; t < 2; ++t) {
            for (int i = 0; i <= 2 * M; ++i) {
                if (dp[!cur][t][i] != 0) {
                    int v = dp[!cur][t][i];
                    add(dp[cur][t][i], v);
                    add(dp[cur][t][i + l], v);
                    add(dp[cur][t][i - l], v);
                }
            }
        }
        for (int i = 1; i <= 2 * M; ++i) add(dp[!cur][0][i], dp[!cur][0][i - 1]);
        for (int i = 0; i <= 2 * M; ++i) {
            add(dp[cur][1][i], 2 * dp[!cur][0][std::min(2 * M, i + l - 2)] % P);
            if (i - l + 2 > 0) add(dp[cur][1][i], 2 * (P - dp[!cur][0][i - l + 1]) % P);
        }
    }
    int ans = dp[cur][1][M];
    cur = 0;
    std::memset(dp, 0, sizeof(dp));
    dp[0][0][M] = 1;
    for (auto l : len) {
        cur ^= 1;
        std::memset(dp[cur], 0, sizeof(dp[cur]));
        for (int t = 0; t < 2; ++t) {
            for (int i = 0; i <= 2 * M; ++i) {
                if (dp[!cur][t][i] != 0) {
                    int v = dp[!cur][t][i];
                    add(dp[cur][t][i + l], v);
                    add(dp[cur][t][i - l], v);
                }
            }
        }
        for (int i = 0; i <= 2 * M; ++i) {
            if (dp[!cur][0][i] != 0) {
                int v = 2 * dp[!cur][0][i] % P;
                add(dp[cur][1][i + l - 1], v);
                add(dp[cur][1][i - l + 1], v);
            }
        }
    }
    ans = (ans + dp[cur][0][M]) % P;
    ans = (ans + dp[cur][1][M]) % P;
    std::cout << ans << "\n";
    
    return 0;
}
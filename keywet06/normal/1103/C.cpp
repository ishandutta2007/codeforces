#include <bits/stdc++.h>

const int N = 250000;

bool vis[N + 1], lf[N + 1];

int dp[N + 1], pa[N + 1];

std::vector<int> g[N + 1];

void Dfs(int v = 1) {
    vis[v] = true;
    lf[v] = true;
    for (int i = 0; i < g[v].size(); ++i) {
        int u = g[v][i];
        if (vis[u]) continue;
        lf[v] = false, dp[u] = dp[v] + 1, pa[u] = v, Dfs(u);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr), std::cout.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    for (int i = 0, a, b; i < m; ++i) {
        std::cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dp[1] = 1;
    Dfs();
    int need = (n + k - 1) / k;
    for (int i = 1; i <= n; ++i) {
        if (dp[i] >= need) {
            std::cout << "PATH\n" << dp[i] << ' ' << i;
            int v = pa[i];
            while (v) std::cout << ' ' << v, v = pa[v];
            std::cout << '\n';
            return 0;
        }
    }
    std::vector<int> c;
    for (int i = 1; i <= n; ++i) {
        if (lf[i] && (int)c.size() < k) c.push_back(i);
    }
    std::cout << "CYCLES\n";
    for (int i = 0; i < c.size(); ++i) {
        int v = c[i], u = -1;
        for (int j = 0; j < g[v].size(); ++j) {
            if (g[v][j] != pa[v] && (dp[v] - dp[g[v][j]] + 1) % 3 != 0) {
                u = g[v][j];
                break;
            }
        }
        if (u == -1) {
            std::vector<int> sad;
            for (int j = 0; j < g[v].size(); ++j) {
                if (g[v][j] != pa[v] && (int)sad.size() < 2) sad.push_back(g[v][j]);
            }
            if (dp[sad[0]] > dp[sad[1]]) std::swap(sad[0], sad[1]);
            pa[v] = sad[1], dp[v] = dp[sad[1]] + 1, u = sad[0];
        }
        std::cout << dp[v] - dp[u] + 1 << '\n' << v;
        while (v != u) v = pa[v], std::cout << ' ' << v;
        std::cout << '\n';
    }
    return 0;
}
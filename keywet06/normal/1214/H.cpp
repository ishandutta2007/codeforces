#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    std::vector<std::vector<int>> g(n);
    std::vector<int> Fa(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, Co;
        std::cin >> u >> Co, --u, --Co;
        g[u].push_back(Co);
        g[Co].push_back(u);
    }
    std::vector<int> Col(n);
    if (k == 2) {
        std::function<void(int)> Dfs = [&](int u) {
            for (int Co : g[u]) {
                if (Co == Fa[u]) continue;
                Fa[Co] = u;
                Col[Co] = Col[u] ^ 1;
                Dfs(Co);
            }
        };
        Fa[0] = -1;
        Dfs(0);
    } else {
        std::vector<std::vector<int>> down(n, std::vector<int>(3));
        std::vector<int> up(n);
        std::function<void(int)> dfs1 = [&](int u) {
            for (int Co : g[u]) {
                if (Co == Fa[u]) continue;
                Fa[Co] = u;
                dfs1(Co);
                int x = down[Co][0] + 1;
                for (int i = 0; i < 3; ++i) {
                    if (x > down[u][i]) std::swap(x, down[u][i]);
                }
            }
        };
        std::function<void(int)> dfs2 = [&](int u) {
            for (int Co : g[u]) {
                if (Co == Fa[u]) continue;
                up[Co] = std::max(up[u], down[u][0] != down[Co][0] + 1
                                             ? down[u][0]
                                             : down[u][1]) +
                         1;
                dfs2(Co);
            }
        };
        Fa[0] = -1;
        dfs1(0);
        dfs2(0);
        for (int i = 0; i < n; ++i) {
            int x = up[i];
            for (int j = 0; j < 3; ++j) {
                if (x > down[i][j]) std::swap(x, down[i][j]);
            }
            if (g[i].size() >= 3 && down[i][1] + down[i][2] >= k - 1) {
                std::cout << "NO" << std::endl;
                return 0;
            }
        }
        std::vector<int> dep(n);
        std::function<void(int)> Dfs = [&](int u) {
            for (int Co : g[u]) {
                if (Co == Fa[u]) continue;
                Fa[Co] = u;
                dep[Co] = dep[u] + 1;
                Dfs(Co);
            }
        };
        Dfs(0);
        int s = 0;
        for (int i = 1; i < n; ++i) {
            if (dep[i] > dep[s]) s = i;
        }
        Fa[s] = 0;
        dep[s] = 0;
        Dfs(s);
        int t = 0;
        for (int i = 1; i < n; ++i) {
            if (dep[i] > dep[t]) t = i;
        }
        int len = dep[t] + 1;
        if (len >= k) {
            for (int i = 0; i < len / 2 - 1; ++i) t = Fa[t];
            s = Fa[t];
            Fa[s] = t;
            Col[s] = 1;
            std::function<void(int, int)> dfs3 = [&](int u, int delta) {
                for (int Co : g[u]) {
                    if (Co == Fa[u]) continue;
                    Fa[Co] = u;
                    Col[Co] = (Col[u] + delta + k) % k;
                    dfs3(Co, delta);
                }
            };
            dfs3(s, 1);
            dfs3(t, -1);
        }
    }
    std::cout << "YES" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cout << Col[i] + 1;
        if (i < n - 1) std::cout << ' ';
    }
    std::cout << std::endl;
    return 0;
}
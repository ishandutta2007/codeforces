#include <bits/stdc++.h>

struct DisjointSetUnion {
    std::vector<int> fa, e, siz;
    DisjointSetUnion(int n) : fa(n), e(n), siz(n) {
        std::iota(fa.begin(), fa.end(), 0);
    }
    int find(int x) {
        while (x != fa[x]) x = fa[x] = fa[fa[x]];
        return x;
    }
    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        siz[x] += siz[y];
        e[x] += e[y];
        fa[y] = x;
        return true;
    }
};

const int P = 998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0), std::cout.tie(0);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> a(n, std::vector<int>(n));
    std::vector<std::tuple<int, int, int>> edges;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> a[i][j];
            if (i < j) edges.emplace_back(a[i][j], i, j);
        }
    }
    DisjointSetUnion dsu(2 * n);
    std::sort(edges.begin(), edges.end());
    int cur = n;
    std::vector<int> lc(2 * n, -1), rc(2 * n, -1), siz(2 * n);
    std::vector<std::vector<int>> dp(2 * n, std::vector<int>(n + 1));
    for (int i = 0; i < n; ++i) dsu.siz[i] = siz[i] = 1;
    std::vector<bool> good(2 * n);
    for (auto [w, u, v] : edges) {
        u = dsu.find(u), v = dsu.find(v);
        if (u != v) {
            dsu.merge(cur, u), dsu.merge(cur, v);
            lc[cur] = u, rc[cur] = v;
            siz[cur++] = siz[u] + siz[v];
        }
        u = dsu.find(u), ++dsu.e[u];
        if (dsu.e[u] == dsu.siz[u] * (dsu.siz[u] - 1) / 2) good[u] = true;
    }
    auto dfs = [&](auto dfs, int u) {
        if (u < n) {
            dp[u][1] = 1;
            return;
        }
        if (good[u]) dp[u][1] = 1;
        dfs(dfs, lc[u]), dfs(dfs, rc[u]);
        for (int i = 1; i <= siz[lc[u]]; ++i) {
            for (int j = 1; j <= siz[rc[u]]; ++j) {
                dp[u][i + j] =
                    (dp[u][i + j] + 1ll * dp[lc[u]][i] * dp[rc[u]][j]) % P;
            }
        }
    };
    dfs(dfs, cur - 1);
    for (int i = 1; i <= n; ++i) std::cout << dp[cur - 1][i] << " \n"[i == n];
    return 0;
}
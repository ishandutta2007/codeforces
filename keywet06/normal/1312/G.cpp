#include <bits/stdc++.h>

int n, clk;

std::vector<int> parent, dep, dfn, f, dp;
std::vector<char> c;
std::vector<bool> chosen;
std::vector<std::vector<int>> e;

void dfs(int u) {
    if (chosen[u]) f[u] = dfn[u] = clk++;
    for (int v : e[u]) {
        dep[v] = dep[u] + 1;
        dfs(v);
        if (f[u] == -1) f[u] = f[v];
    }
}

void dfs1(int u) {
    for (int v : e[u]) {
        dp[v] = dp[u] + 1;
        if (chosen[v]) dp[v] = std::min(dp[v], f[u] + dfn[v]);
        f[v] = std::min(dp[v] - f[v] + 1, f[u]);
        dfs1(v);
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    parent.resize(n + 1);
    dep.resize(n + 1);
    dfn.resize(n + 1);
    e.resize(n + 1);
    parent[0] = -1;
    c.resize(n + 1);
    chosen.resize(n + 1);
    for (int i = 1; i <= n; ++i) {
        std::cin >> parent[i] >> c[i];
        e[parent[i]].push_back(i);
    }
    for (int i = 0; i <= n; ++i) {
        std::sort(e[i].begin(), e[i].end(),
                  [&](int i, int j) { return c[i] < c[j]; });
    }
    f.assign(n + 1, -1);
    int k;
    std::cin >> k;
    std::vector<int> a(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> a[i];
        chosen[a[i]] = true;
    }
    dp.resize(n + 1);
    f[0] = 1;
    dfs(0);
    dfs1(0);
    for (int i = 0; i < k; ++i) std::cout << dp[a[i]] << " \n"[i == k - 1];
    return 0;
}
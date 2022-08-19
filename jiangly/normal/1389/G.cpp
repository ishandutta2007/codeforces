#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> ver(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> ver[i];
        --ver[i];
    }
    std::vector<int> c(n);
    for (int i = 0; i < n; ++i)
        std::cin >> c[i];
    std::vector<int> w(m);
    for (int i = 0; i < m; ++i)
        std::cin >> w[i];
    std::vector<int> x(m), y(m);
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < m; ++i) {
        std::cin >> x[i] >> y[i];
        --x[i];
        --y[i];
        e[x[i]].push_back(y[i]);
        e[y[i]].push_back(x[i]);
    }
    int cnt = 0, now = 0;
    std::vector<int> dfn(n, -1), low(n), belong(n, -1);
    std::vector<int> stk;
    std::function<void(int, int)> tarjan = [&](int u, int p) {
        dfn[u] = low[u] = now++;
        stk.push_back(u);
        for (auto v : e[u]) {
            if (v == p)
                continue;
            if (dfn[v] == -1) {
                tarjan(v, u);
                low[u] = std::min(low[u], low[v]);
            } else if (belong[v] == -1) {
                low[u] = std::min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            int v;
            do {
                v = stk.back();
                belong[v] = cnt;
                stk.pop_back();
            } while (v != u);
            ++cnt;
        }
    };
    tarjan(0, -1);
    std::vector<int64_t> val(cnt);
    for (int i = 0; i < n; ++i)
        val[belong[i]] += c[i];
    std::vector<std::vector<std::pair<int, int>>> e1(cnt);
    for (int i = 0; i < m; ++i) {
        if (belong[x[i]] != belong[y[i]]) {
            e1[belong[x[i]]].emplace_back(belong[y[i]], w[i]);
            e1[belong[y[i]]].emplace_back(belong[x[i]], w[i]);
        }
    }
    std::vector<int> key(cnt);
    for (auto u : ver)
        key[belong[u]] = 1;
    std::vector<int> top(cnt);
    std::function<void(int, int)> dfs = [&](int u, int p) {
        for (auto &[v, w] : e1[u]) {
            if (v == p)
                continue;
            dfs(v, u);
            key[u] |= key[v];
        }
    };
    std::function<void(int, int)> dfs0 = [&](int u, int p) {
        if (key[u])
            top[u] = u;
        for (auto &[v, w] : e1[u]) {
            if (v == p)
                continue;
            top[v] = top[u];
            dfs0(v, u);
            if (key[v] == 0)
                v = p;
        }
    };
    int root = belong[ver[0]];
    dfs(root, -1);
    dfs0(root, -1);
    for (int i = 0; i < cnt; ++i)
        if (key[i] == 0)
            val[top[i]] += val[i];
    for (int i = 0; i < n; ++i)
        if (key[belong[i]] == 0)
            belong[i] = top[belong[i]];
    std::vector<int64_t> dp(cnt);
    std::function<void(int, int)> dfs1 = [&](int u, int p) {
        dp[u] = val[u];
        for (auto [v, w] : e1[u]) {
            if (v == p)
                continue;
            dfs1(v, u);
            dp[u] += std::max(0ll, dp[v] - w);
        }
    };
    std::function<void(int, int)> dfs2 = [&](int u, int p) {
        for (auto [v, w] : e1[u]) {
            if (v == p)
                continue;
            dp[v] += std::max(0ll, dp[u] - std::max(0ll, dp[v] - w) - w);
            dfs2(v, u);
        }
    };
    dfs1(root, -1);
    dfs2(root, -1);
    for (int i = 0; i < n; ++i)
        std::cout << dp[belong[i]] << " \n"[i == n - 1];
    return 0;
}
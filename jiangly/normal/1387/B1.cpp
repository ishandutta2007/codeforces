#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    std::vector<int> isroot(n), parent(n);
    std::function<void(int)> dfs1 = [&](int u) {
        for (auto v : e[u]) {
            if (v == parent[u])
                continue;
            parent[v] = u;
            dfs1(v);
            if (!isroot[v])
                isroot[u] = 1;
        }
        if (u == 0 && !isroot[u]) {
            isroot[u] = 1;
            isroot[e[u][0]] = 0;
        }
    };
    parent[0] = -1;
    dfs1(0);
    std::vector<int> ans(n), a;
    std::function<void(int)> dfs2 = [&](int u) {
        a.push_back(u);
        for (auto v : e[u]) {
            if (v == parent[u] || isroot[v])
                continue;
            dfs2(v);
        }
    };
    int length = 2 * n;
    for (int i = 0; i < n; ++i) {
        if (isroot[i] == 1) {
            length -= 2;
            a.clear();
            dfs2(i);
            for (int j = 0; j < int(a.size()); ++j)
                ans[a[j]] = a[(j + 1) % a.size()];
        }
    }
    std::cout << length << "\n";
    for (int i = 0; i < n; ++i)
        std::cout << ans[i] + 1 << " \n"[i == n - 1];
    return 0;
}
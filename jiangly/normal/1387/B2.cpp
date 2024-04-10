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
    std::vector<int> sz(n);
    std::vector<int> a;
    int64_t length = 0;
    std::function<void(int, int)> dfs = [&](int u, int p) {
        sz[u] = 1;
        a.push_back(u);
        for (auto v : e[u]) {
            if (v == p)
                continue;
            dfs(v, u);
            sz[u] += sz[v];
        }
        length += 2 * std::min(sz[u], n - sz[u]);
    };
    dfs(0, -1);
    std::function<int(int, int)> find = [&](int u, int p) {
        for (auto v : e[u]) {
            if (v == p)
                continue;
            if (2 * sz[v] > n)
                return find(v, u);
        }
        return u;
    };
    int x = find(0, -1);
    a.clear();
    length = 0;
    dfs(x, -1);
    std::vector<int> ans(n);
    for (int i = 0; i < n; ++i)
        ans[a[i]] = a[(i + n / 2) % n];
    std::cout << length << "\n";
    for (int i = 0; i < n; ++i)
        std::cout << ans[i] + 1 << " \n"[i == n - 1];
    return 0;
}
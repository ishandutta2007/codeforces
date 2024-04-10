#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int m, n;
    std::cin >> n >> m;
    std::vector<int> t(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> t[i];
        --t[i];
    }
    std::vector<std::multiset<int>> e(m);
    std::vector<std::set<int>> s(m);
    for (int i = 0; i < m; ++i)
        s[i].insert(i);
    int ans = 0;
    for (int i = 0; i < n - 1; ++i) {
        if (t[i] != t[i + 1]) {
            e[t[i]].insert(t[i + 1]);
            e[t[i + 1]].insert(t[i]);
            ++ans;
        }
    }
    std::cout << ans << "\n";
    for (int i = 0; i < m - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        bool sw = false;
        if (e[u].size() + s[u].size() < e[v].size() + s[v].size()) {
            std::swap(u, v);
            sw = true;
        }
        for (auto x : e[v])
            if (s[u].count(x))
                --ans;
        e[u].insert(e[v].begin(), e[v].end());
        s[u].insert(s[v].begin(), s[v].end());
        if (sw) {
            std::swap(e[u], e[v]);
            std::swap(s[u], s[v]);
        }
        std::cout << ans << "\n";
    }
    return 0;
}
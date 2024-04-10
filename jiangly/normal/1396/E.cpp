#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    int64_t k;
    std::cin >> k;
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    std::vector<int> siz(n), w(n);
    std::function<void(int, int)> dfs = [&](int u, int p) {
        siz[u] = 1;
        for (auto v : e[u]) {
            if (v == p)
                continue;
            dfs(v, u);
            siz[u] += siz[v];
        }
    };
    dfs(0, -1);
    int64_t L = 0, R = 0;
    for (int i = 1; i < n; ++i) {
        L += siz[i] % 2;
        R += w[i] = std::min(siz[i], n - siz[i]);
    }
    if (k < L || k > R || (k - L) % 2 == 1) {
        std::cout << "NO\n";
        return 0;
    }
    std::cout << "YES\n";
    int l = 0, r = n;
    while (l < r) {
        int m = (l + r) / 2;
        int64_t s = 0;
        for (int i = 1; i < n; ++i) {
            if (w[i] >= m) {
                s += m + (w[i] - m) % 2;
            } else {
                s += w[i];
            }
        }
        if (s >= k) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    int64_t s = 0;
    for (int i = 1; i < n; ++i) {
        if (w[i] > l)
            w[i] = l + (w[i] - l) % 2;
        s += w[i];
    }
    for (int i = 1; i < n; ++i) {
        if (w[i] == l + 1 && s > k) {
            s -= 2;
            w[i] -= 2;
        }
    }
    std::vector<std::vector<int>> t(n);
    std::function<void(int, int)> solve = [&](int u, int p) {
        int tot = 1;
        t[u].push_back(u);
        std::set<std::pair<int, int>> s;
        s.emplace(1, u);
        for (auto v : e[u]) {
            if (v == p)
                continue;
            solve(v, u);
            tot += t[v].size();
            s.emplace(t[v].size(), v);
        }
        int need = (tot - w[u]) / 2;
        while (need--) {
            int u = s.rbegin() -> second;
            s.erase(*s.rbegin());
            int v = s.rbegin() -> second;
            s.erase(*s.rbegin());
            std::cout << t[u].back() + 1 << " " << t[v].back() + 1 << "\n";
            t[u].pop_back();
            t[v].pop_back();
            s.emplace(t[u].size(), u);
            s.emplace(t[v].size(), v);
        }
        for (auto v : e[u]) {
            if (v == p)
                continue;
            if (t[v].size() > t[u].size())
                std::swap(t[u], t[v]);
            t[u].insert(t[u].end(), t[v].begin(), t[v].end());
        }
    };
    solve(0, -1);
    return 0;
}
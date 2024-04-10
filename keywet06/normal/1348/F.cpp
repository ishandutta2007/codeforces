#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    std::vector<std::vector<std::pair<int, int>>> t(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i] >> b[i], --a[i];
        t[a[i]].emplace_back(b[i], i);
    }
    std::vector<int> p(n), sec(n, -1), parent(n, -1), q(n);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<>>
        h;
    for (int i = 0; i < n; ++i) {
        for (auto x : t[i]) h.push(x);
        p[i] = h.top().second, q[p[i]] = i, h.pop();
        if (!h.empty()) sec[i] = h.top().second;
    }
    for (int i = 0; i < n; ++i) {
        if (sec[i] != -1) sec[i] = q[sec[i]];
    }
    std::vector<int> stk;
    for (int i = n - 1; i >= 0; --i) {
        while (!stk.empty() && b[p[stk.back()]] < b[p[i]]) stk.pop_back();
        if (!stk.empty() && stk.back() < b[p[i]]) parent[i] = stk.back();
        stk.push_back(i);
    }
    auto output = [&](auto p) {
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) a[p[i]] = i;
        for (int i = 0; i < n; ++i) std::cout << a[i] + 1 << " \n"[i == n - 1];
    };
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < n; ++i) {
        if (parent[i] != -1) e[parent[i]].push_back(i);
    }
    std::vector<bool> ok(n);
    std::function<void(int)> dfs = [&](int u) {
        if (sec[u] != -1 && ok[sec[u]]) {
            auto q = p;
            for (int i = u; i != sec[u]; i = parent[i]) q[parent[i]] = p[i];
            q[u] = p[sec[u]];
            std::cout << "NO\n";
            output(p), output(q);
            std::exit(0);
        }
        ok[u] = true;
        for (auto v : e[u]) dfs(v);
        ok[u] = false;
    };
    for (int i = 0; i < n; ++i) {
        if (parent[i] == -1) dfs(i);
    }
    std::cout << "YES\n";
    output(p);
    return 0;
}
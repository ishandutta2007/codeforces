#include <bits/stdc++.h>

std::mt19937 rnd(std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> e(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u;
            --v;
            e[u].push_back(v);
        }
        std::vector<int> p(n);
        std::iota(p.begin(), p.end(), 0);
        std::random_shuffle(p.begin(), p.end(),
                            [&](int n) { return rnd() % n; });
        int u = -1;
        for (int i = 0; i < std::min(n, 100); ++i) {
            std::vector<int> dep(n, -1);
            bool ok = true;
            std::vector<bool> ins(n);
            std::function<void(int)> dfs = [&](int u) {
                ins[u] = true;
                for (auto v : e[u]) {
                    if (dep[v] == -1) {
                        dep[v] = dep[u] + 1;
                        dfs(v);
                    } else if (!ins[v]) {
                        ok = false;
                    }
                }
                ins[u] = false;
            };
            dep[p[i]] = 0;
            dfs(p[i]);
            if (ok) {
                u = p[i];
                break;
            }
        }
        if (u == -1) {
            std::cout << -1 << "\n";
            continue;
        }
        std::vector<int> a(n), x(n);
        std::vector<int> dep(n, -1);
        std::function<void(int)> dfs = [&](int u) {
            x[u] = u;
            for (auto v : e[u]) {
                if (dep[v] == -1) {
                    dep[v] = dep[u] + 1;
                    dfs(v);
                    if (dep[x[v]] < dep[x[u]]) x[u] = x[v];
                } else {
                    ++a[u], --a[v];
                    if (dep[v] < dep[x[u]]) x[u] = v;
                }
            }
        };
        dep[u] = 0;
        dfs(u);
        std::function<void(int)> dfs1 = [&](int u) {
            for (auto v : e[u]) {
                if (dep[v] == dep[u] + 1) {
                    dfs1(v);
                    a[u] += a[v];
                }
            }
        };
        dfs1(u);
        std::vector<bool> good(n);
        good[u] = true;
        std::function<void(int)> dfs2 = [&](int u) {
            if (dep[u] && a[u] == 1) good[u] = good[x[u]];
            for (auto v : e[u]) {
                if (dep[v] == dep[u] + 1) dfs2(v);
            }
        };
        dfs2(u);
        std::vector<int> ver;
        for (int i = 0; i < n; ++i) {
            if (good[i]) ver.push_back(i);
        }
        if (5 * int(ver.size()) < n) {
            std::cout << -1 << "\n";
        } else {
            for (int i = 0; i < int(ver.size()); ++i) {
                std::cout << ver[i] + 1 << " \n"[i == int(ver.size()) - 1];
            }
        }
    }
    return 0;
}
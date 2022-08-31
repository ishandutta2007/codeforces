#include <bits/stdc++.h>
using i64 = long long;
int query(int x) {
    std::cout << "? " << x + 1 << std::endl;
    int res;
    std::cin >> res;
    res--;
    return res;
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        u--;
        v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if (n == 1) {
        std::cout << 0 << std::endl;
        std::cout << "! 1 1" << std::endl;
        return 0;
    }
    std::vector<int> parent(n, -1);
    std::vector<int> dp1(n), dp2(n), best1(n), best2(n);
    auto precalc = [&](int s) {
        std::fill(dp1.begin(), dp1.end(), 0);
        std::fill(dp2.begin(), dp2.end(), 0);
        parent[s] = -1;
        std::function<void(int)> dfs1 = [&](int u) {
            if (parent[u] != -1) {
                std::swap(*std::find(e[u].begin(), e[u].end(), parent[u]), e[u].back());
            }
            best1[u] = u;
            for (auto v : e[u]) {
                if (v == parent[u]) {
                    continue;
                }
                parent[v] = u;
                dfs1(v);
            }
            std::sort(e[u].begin(), e[u].end(), [&](int i, int j) {
                return dp1[i] > dp1[j];
            });
            int d = e[u].size() - (parent[u] != -1);
            if (!d) {
                return;
            }
            best1[u] = best1[e[u][0]];
            dp1[u] = d;
            for (int i = 0; i < d; i++) {
                dp1[u] = std::max(dp1[u], i + dp1[e[u][i]]);
            }
        };
        std::function<void(int)> dfs2 = [&](int u) {
            if (e[u].size() - (parent[u] != -1) == 0) {
                return;
            }
            best2[u] = parent[u];
            if (e[u].size() >= 2) {
                int d = e[u].size() - 1;
                std::vector<std::pair<int, int>> a;
                for (auto v : e[u]) {
                    if (v == parent[u]) {
                        a.emplace_back(dp2[u], v);
                    } else {
                        a.emplace_back(dp1[v], v);
                    }
                }
                std::sort(a.begin(), a.end(), std::greater<>());
                assert(int(a.size()) == d + 1);
                std::vector<int> pre(d + 1), suf(d + 1);
                suf[d] = d;
                for (int i = 1; i <= d; i++) {
                    pre[i] = std::max(pre[i - 1], a[i - 1].first + i - 1);
                }
                for (int i = d - 1; i >= 0; i--) {
                    suf[i] = std::max(suf[i + 1], a[i + 1].first + i);
                }
                for (int i = 0; i <= d; i++) {
                    int v = a[i].second;
                    if (v == parent[u]) {
                        continue;
                    }
                    dp2[v] = std::max(pre[i], suf[i]);
                    int x = a[i == 0].second;
                    best2[v] = x == parent[u] ? best2[u] : best1[x];
                }
            }
            for (auto v : e[u]) {
                if (v == parent[u]) {
                    continue;
                }
                dfs2(v);
            }
        };
        dfs1(s);
        dfs2(s);
    };
    int ans = 0;
    precalc(0);
    for (int i = 0; i < n; i++) {
        std::vector<int> a;
        for (auto v : e[i]) {
            if (v == parent[i]) {
                a.push_back(dp2[i]);
            } else {
                a.push_back(dp1[v]);
            }
        }
        std::sort(a.begin(), a.end(), std::greater<>());
        if (a.size() == 1) {
            ans = std::max({1, ans, a[0]});
        } else {
            int res = a.size();
            for (int j = 1; j < int(a.size()); j++) {
                res = std::max(res, j + a[j]);
            }
            res += std::max(0, a[0] - 1);
            ans = std::max(ans, res);
        }
    }
    std::cout << ans << std::endl;
    int f;
    std::cin >> f;
    f--;
    precalc(f);
    std::function<int(int, int)> solve = [&](int u, int x) {
        for (auto v : e[u]) {
            if (v == x || v == parent[u]) {
                continue;
            }
            v = best1[v];
            int y = query(v);
            if (y != u) {
                if (y == v) {
                    return solve(v, -1);
                } else {
                    while (parent[v] != y) {
                        v = parent[v];
                    }
                    return solve(y, v);
                }
            }
        }
        return u;
    };
    std::vector<int> pts;
    for (auto u : e[f]) {
        u = best1[u];
        int x = query(u);
        if (x != f) {
            if (x == u) {
                pts.push_back(solve(u, -1));
            } else {
                while (parent[u] != x) {
                    u = parent[u];
                }
                pts.push_back(solve(x, u));
            }
        }
        if (pts.size() == 2) {
            break;
        }
    }
    while (pts.size() < 2) {
        pts.push_back(f);
    }
    std::cout << "! " << pts[0] + 1 << " " << pts[1] + 1 << std::endl;
    return 0;
}
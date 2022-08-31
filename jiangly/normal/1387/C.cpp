#include <bits/stdc++.h>
struct Automaton {
    int tot, nbad;
    int nxt[100][2], bad[100], id[100], link[100];
    Automaton() : tot(1), nxt{}, bad{}, link{} {}
    void add(std::vector<int> s) {
        int p = 1;
        for (auto c : s) {
            if (!nxt[p][c])
                nxt[p][c] = ++tot;
            p = nxt[p][c];
        }
        bad[p] = 1;
    }
    void build() {
        for (int i = 1; i <= tot; ++i)
            if (bad[i])
                bad[nxt[i][0]] = bad[nxt[i][1]] = 1;
        std::queue<int> que;
        que.push(1);
        nxt[0][0] = nxt[0][1] = 1;
        bad[0] = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            bad[u] |= bad[link[u]];
            for (int c = 0; c < 2; ++c) {
                if (nxt[u][c]) {
                    link[nxt[u][c]] = nxt[link[u]][c];
                    que.push(nxt[u][c]);
                } else {
                    nxt[u][c] = nxt[link[u]][c];
                }
            }
        }
        nbad = 0;
        for (int i = 1; i <= tot; ++i)
            if (!bad[i])
                id[i] = nbad++;
    }
};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int g, n, m;
    std::cin >> g >> n >> m;
    std::vector<std::vector<std::tuple<int, int, int>>> e(g);
    int tot = g;
    auto add = [&](int x, int a, int b) {
        e[a].emplace_back(x, b, 0);
        e[b].emplace_back(x, a, 1);
    };
    for (int i = 0; i < n; ++i) {
        int u;
        std::cin >> u;
        int k;
        std::cin >> k;
        std::vector<int> v(k);
        for (int j = 0; j < k; ++j)
            std::cin >> v[j];
        if (k == 1) {
            e[v[0]].emplace_back(u, -1, -1);
            continue;
        }
        for (int j = 0; j < k - 1; ++j) {
            if (j == k - 2) {
                add(u, v[j], v[j + 1]);
            } else {
                e.emplace_back();
                add(u, v[j], tot);
                u = tot++;
            }
        }
    }
    Automaton am;
    for (int i = 0; i < m; ++i) {
        int l;
        std::cin >> l;
        std::vector<int> a(l);
        for (int j = 0; j < l; ++j)
            std::cin >> a[j];
        am.add(a);
    }
    am.build();
    std::vector<std::vector<std::vector<uint64_t>>> dp(tot);
    for (auto &v : dp)
        v.assign(am.nbad, std::vector<uint64_t>(am.nbad, 1ull << 63));
    std::priority_queue<std::tuple<uint64_t, int, int, int>, std::vector<std::tuple<uint64_t, int, int, int>>, std::greater<>> h;
    for (int c = 0; c < 2; ++c) {
        for (int i = 1; i <= am.tot; ++i) {
            if (!am.bad[i] && !am.bad[am.nxt[i][c]]) {
                dp[c][am.id[i]][am.id[am.nxt[i][c]]] = 1;
                h.emplace(1, c, am.id[i], am.id[am.nxt[i][c]]);
            }
        }
    }
    while (!h.empty()) {
        auto [d, u, x, y] = h.top();
        h.pop();
        if (d != dp[u][x][y])
            continue;
        for (auto [t, v, p] : e[u]) {
            if (p == -1) {
                if (dp[t][x][y] > d) {
                    dp[t][x][y] = d;
                    h.emplace(d, t, x, y);
                }
            } else if (p == 0) {
                for (int z = 0; z < am.nbad; ++z) {
                    if (dp[t][x][z] > d + dp[v][y][z]) {
                        dp[t][x][z] = d + dp[v][y][z];
                        h.emplace(dp[t][x][z], t, x, z);
                    }
                }
            } else {
                for (int z = 0; z < am.nbad; ++z) {
                    if (dp[t][z][y] > d + dp[v][z][x]) {
                        dp[t][z][y] = d + dp[v][z][x];
                        h.emplace(dp[t][z][y], t, z, y);
                    }
                }
            }
        }
    }
    for (int u = 2; u < g; ++u) {
        uint64_t ans = 1ull << 63;
        for (int i = 0; i < am.nbad; ++i)
            if (ans > dp[u][0][i])
                ans = dp[u][0][i];
        if (ans == (1ull << 63)) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO " << ans << "\n";
        }
    }
    return 0;
}
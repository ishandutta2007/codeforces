#include <bits/stdc++.h>
int main() {
    std::mt19937 rnd(time(0));
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<int> w(n);
    for (int &i : w)
        std::cin >> i;
    std::vector<std::vector<int>> deg(n);
    for (auto &i : deg)
        i.resize(k);
    std::vector<std::pair<int, int>> edges(m);
    std::vector<int> col(m);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        edges[i] = {u, v};
        col[i] = rnd() % k;
        ++deg[u][col[i]];
        ++deg[v][col[i]];
    }
    std::vector<std::vector<std::pair<int, int>>> adj(n + 1);
    std::vector<int> degree(n), cyc;
    std::vector<bool> used;
    std::function<void(int, int)> findEulerTour = [&](int u, int in) {
        for (auto [v, id] : adj[u])
            if (!used[id]) {
                used[id] = true;
                findEulerTour(v, id);
            }
        if (in != -1)
            cyc.push_back(in);
    };
    auto recolor = [&](int a, int b) {
        for (int i = 0; i < m; ++i) {
            auto [u, v] = edges[i];
            if (col[i] == a || col[i] == b) {
                --deg[u][col[i]];
                --deg[v][col[i]];
                adj[u].emplace_back(v, i);
                adj[v].emplace_back(u, i);
                ++degree[u];
                ++degree[v];
            }
        }
        int cnt = m;
        for (int i = 0; i < n; ++i) {
            adj[n].emplace_back(i, cnt);
            adj[i].emplace_back(n, cnt++);
            if (degree[i] % 2 == 0) {
                adj[n].emplace_back(i, cnt);
                adj[i].emplace_back(n, cnt++);
            }
        }
        used.assign(cnt, false);
        findEulerTour(n, -1);
        int cur = 0;
        for (int i : cyc) {
            if (i < m) {
                col[i] = cur == 1 ? b : a;
                auto [u, v] = edges[i];
                ++deg[u][col[i]];
                ++deg[v][col[i]];
            }
            cur ^= 1;
        }
        fill(degree.begin(), degree.end(), 0);
        used.clear();
        cyc.clear();
        for (auto &i : adj)
            i.clear();
    };
    while (true) {
        bool satisfy = true;
        for (int i = 0; i < n; ++i) {
            auto [a, b] = std::minmax_element(deg[i].begin(), deg[i].end());
            if (*b - *a > 2) {
                satisfy = false;
                recolor(a - deg[i].begin(), b - deg[i].begin());
            }
        }
        if (satisfy)
            break;
    }
    for (int i : col)
        std::cout << i + 1 << "\n";
    return 0;
}
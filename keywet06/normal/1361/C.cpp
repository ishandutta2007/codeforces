#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i] >> b[i];
    for (int k = 20; k >= 0; --k) {
        int s = 1 << k;
        std::vector<std::vector<std::pair<int, int>>> e(s + n);
        for (int i = 0; i < n; ++i) {
            e[a[i] & (s - 1)].emplace_back(s + i, 2 * i);
            e[s + i].emplace_back(a[i] & (s - 1), 2 * i);
            e[b[i] & (s - 1)].emplace_back(s + i, 2 * i + 1);
            e[s + i].emplace_back(b[i] & (s - 1), 2 * i + 1);
        }
        bool ok = true;
        for (int i = 0; i < s; ++i)
            if (e[i].size() & 1) ok = false;
        if (!ok) continue;
        std::vector<bool> vis(2 * n);
        std::vector<int> p, cur(s + n);
        std::function<void(int, int)> dfs = [&](int u, int i) {
            while (cur[u] < int(e[u].size())) {
                int v = e[u][cur[u]].first;
                int j = e[u][cur[u]].second;
                ++cur[u];
                if (!vis[j]) {
                    vis[j] = true;
                    dfs(v, j);
                }
            }
            if (i != -1) p.push_back(i);
        };
        dfs(s, -1);
        if (int(p.size()) < 2 * n) continue;
        if ((p[0] ^ p[1]) != 1) p.insert(p.begin(), p.back());
        std::cout << k << "\n";
        for (int i = 0; i < 2 * n; ++i)
            std::cout << p[i] + 1 << " \n"[i == 2 * n - 1];
        return 0;
    }
    return 0;
}
#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, k;
        std::cin >> n >> k;
        std::vector<std::vector<int>> e(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u;
            --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if (k == 1) {
            std::cout << n - 1 << "\n";
            continue;
        }
        int ans = 0;
        std::vector<int> deg(n), leaf(n);
        for (int i = 0; i < n; ++i) {
            deg[i] = e[i].size();
            if (deg[i] == 1)
                ++leaf[e[i][0]];
        }
        std::vector<int> inque(n);
        std::queue<int> que;
        for (int i = 0; i < n; ++i) {
            if (leaf[i] >= k) {
                que.push(i);
                inque[i] = 1;
            }
        }
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            ++ans;
            leaf[u] -= k;
            deg[u] -= k;
            inque[u] = 0;
            if (leaf[u] >= k) {
                que.push(u);
                inque[u] = 1;
            }
            if (deg[u] == 1) {
                deg[u] = 0;
                for (auto v : e[u]) {
                    if (deg[v]) {
                        ++leaf[v];
                        if (leaf[v] >= k && !inque[v]) {
                            que.push(v);
                            inque[v] = 1;
                        }
                    }
                }
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}
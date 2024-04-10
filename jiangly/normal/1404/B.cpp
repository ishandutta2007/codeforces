#include <bits/stdc++.h>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, a, b, da, db;
        std::cin >> n >> a >> b >> da >> db;
        --a;
        --b;
        std::vector<std::vector<int>> e(n);
        for (int i = 0; i < n - 1; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u;
            --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        if (db <= 2 * da) {
            std::cout << "Alice\n";
            continue;
        }
        std::vector<int> d(n);
        auto bfs = [&](int s) {
            std::fill(d.begin(), d.end(), -1);
            d[s] = 0;
            std::queue<int> que;
            que.push(s);
            while (!que.empty()) {
                int u = que.front();
                que.pop();
                for (auto v : e[u]) {
                    if (d[v] == -1) {
                        d[v] = d[u] + 1;
                        que.push(v);
                    }
                }
            }
            return std::max_element(d.begin(), d.end()) - d.begin();
        };
        int c = bfs(a);
        if (d[b] <= da) {
            std::cout << "Alice\n";
            continue;
        }
        int x = bfs(c);
        if (d[x] <= 2 * da) {
            std::cout << "Alice\n";
        } else {
            std::cout << "Bob\n";
        }
    }
    return 0;
}
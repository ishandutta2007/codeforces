#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::vector<int>> e(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    std::vector<int> dep(n, -1), parent(n, -1);
    std::function<void(int, int)> dfs = [&](int u, int p) {
        for (auto v : e[u]) {
            if (v == p)
                continue;
            if (dep[v] == -1) {
                dep[v] = dep[u] + 1;
                parent[v] = u;
                dfs(v, u);
            } else if (dep[v] < dep[u] && dep[u] - dep[v] <= k - 1) {
                std::cout << 2 << "\n";
                std::cout << dep[u] - dep[v] + 1 << "\n";
                for (int i = u; i != parent[v]; i = parent[i])
                    std::cout << i + 1 << " \n"[i == v];
                exit(0);
            }
        }
    };
    dep[0] = 0;
    dfs(0, -1);
    int l = (k + 1) / 2;
    std::vector<int> c;
    if (m == n - 1) {
        for (int x = 0; x < 2; ++x) {
            c.clear();
            for (int i = 0; i < n; ++i)
                if ((dep[i] & 1) == x && int(c.size()) < l)
                    c.push_back(i);
            if (int(c.size()) == l)
                break;
        }
    } else {
        int u = 0;
        while (dep[u] + 1 < 2 * l - 1)
            ++u;
        for (int i = 0; i < l; ++i, u = parent[parent[u]])
            c.push_back(u);
    }
    std::cout << 1 << "\n";
    for (int i = 0; i < l; ++i)
        std::cout << c[i] + 1 << " \n"[i == l - 1];
    return 0;
}
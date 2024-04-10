#include <bits/stdc++.h>

int n, m, r;

std::vector<int> dep, parent, cnt;
std::vector<std::vector<int>> e;

void dfs(int u) {
    ++cnt[dep[u] % (r - 1)];
    for (int v : e[u]) {
        if (v == parent[u]) continue;
        if (dep[v] == -1) {
            dep[v] = dep[u] + 1;
            parent[v] = u;
            dfs(v);
        } else if (dep[u] - dep[v] + 1 >= r) {
            std::cout << 2 << "\n";
            std::cout << dep[u] - dep[v] + 1 << "\n";
            for (int i = u; i != parent[v]; i = parent[i])
                std::cout << i + 1 << " \n"[i == v];
            exit(0);
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    dep.resize(n, -1);
    parent.assign(n, -1);
    e.resize(n);
    while (r * r < n) ++r;
    cnt.resize(r - 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dep[0] = 0;
    parent[0] = -1;
    dfs(0);
    std::cout << 1 << "\n";
    for (int i = 0; i < r - 1; ++i) {
        if (cnt[i] >= r) {
            int k = r;
            for (int j = 0; j < n; ++j) {
                if (dep[j] % (r - 1) == i) {
                    std::cout << j + 1 << " "[--k == 0];
                    if (k == 0) return 0;
                }
            }
        }
    }
    return 0;
}
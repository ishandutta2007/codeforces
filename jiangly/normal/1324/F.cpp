#include <iostream>
#include <vector>
#include <algorithm>
int n;
std::vector<int> a;
std::vector<std::vector<int>> e;
void dfs1(int u, int p) {
    for (int v : e[u]) {
        if (v != p) {
            dfs1(v, u);
            a[u] += std::max(0, a[v]);
        }
    }
}
void dfs2(int u, int p) {
    for (int v : e[u]) {
        if (v != p) {
            a[v] += std::max(0, a[u] - std::max(0, a[v]));
            dfs2(v, u);
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    e.resize(n);
    a.resize(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> a[i];
        if (a[i] == 0)
            a[i] = -1;
    }
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    for (int i = 0; i < n; ++i)
        std::cout << a[i] << " \n"[i == n - 1];
    return 0;
}
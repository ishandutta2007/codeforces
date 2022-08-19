#include <iostream>
#include <vector>
int n;
std::vector<std::vector<int>> e;
std::vector<int> deg;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    e.resize(n);
    deg.resize(n);
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
        ++deg[u];
        ++deg[v];
    }
    int res = n;
    while (res > 1) {
        int u, v;
        for (u = 0; deg[u] != 1; ++u)
            ;
        for (v = u + 1; deg[v] != 1; ++v)
            ;
        std::cout << "? " << u + 1 << " " << v + 1 << std::endl;
        int w;
        std::cin >> w;
        --w;
        if (w == u || w == v) {
            std::cout << "! " << w + 1 << std::endl;
            return 0;
        }
        deg[u] = deg[v] = -1;
        for (int x : e[u])
            --deg[x];
        for (int x : e[v])
            --deg[x];
        res -= 2;
    }
    int u;
    for (u = 0; deg[u] != 0; ++u)
        ;
    std::cout << "! " << u + 1 << std::endl;
    return 0;
}
#include <iostream>
#include <vector>
#include <set>
int n, m, cnt;
std::vector<std::multiset<int>> e;
std::vector<int> odd;
void dfs(int u) {
    while (!e[u].empty()) {
        int v = *e[u].begin();
        e[u].erase(e[u].begin());
        e[v].erase(e[v].find(u));
        dfs(v);
        if (cnt % 2 == 0) {
            std::cout << u + 1 << " " << v + 1 << "\n";
        } else {
            std::cout << v + 1 << " " << u + 1 << "\n";
        }
        ++cnt;
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    e.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].insert(v);
        e[v].insert(u);
    }
    for (int i = 0; i < n; ++i)
        if (e[i].size() % 2 == 1)
            odd.push_back(i);
    for (int i = 0; i < int(odd.size()); i += 2) {
        e[odd[i]].insert(odd[i + 1]);
        e[odd[i + 1]].insert(odd[i]);
        ++m;
    }
    if (m % 2 == 1) {
        e[0].insert(0);
        e[0].insert(0);
        ++m;
    }
    std::cout << m << "\n";
    dfs(0);
    return 0;
}
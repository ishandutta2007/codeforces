#include <iostream>
#include <vector>
#include <queue>
int n, m, k;
std::vector<std::vector<int>> e, e1;
std::vector<int> p, dis;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    e.resize(n);
    e1.resize(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e1[v].push_back(u);
    }
    std::cin >> k;
    p.resize(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> p[i];
        --p[i];
    }
    dis.assign(n, -1);
    dis[p.back()] = 0;
    std::queue<int> que;
    que.push(p.back());
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v : e1[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
    }
    int min = 0, max = 0;
    for (int i = 0; i < k - 1; ++i) {
        if (dis[p[i]] != dis[p[i + 1]] + 1)
            ++min;
        for (int v : e[p[i]]) {
            if (v != p[i + 1] && dis[p[i]] == dis[v] + 1) {
                ++max;
                break;
            }
        }
    }
    std::cout << min << " " << max << "\n";
    return 0;
}
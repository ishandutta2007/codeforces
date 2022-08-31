#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
int n, m, k, ans, max;
std::vector<std::vector<int>> e;
std::vector<int> a, dis1, dis2;
void bfs(int s, std::vector<int> &dis) {
    dis.assign(n, -1);
    dis[s] = 0;
    std::queue<int> que;
    que.push(s);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v : e[u]) {
            if (dis[v] == -1) {
                dis[v] = dis[u] + 1;
                que.push(v);
            }
        }
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> k;
    e.resize(n);
    a.resize(k);
    for (int i = 0; i < k; ++i) {
        std::cin >> a[i];
        --a[i];
    }
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e[v].push_back(u);
    }
    bfs(0, dis1);
    bfs(n - 1, dis2);
    ans = dis1[n - 1];
    std::sort(a.begin(), a.end(), [&](int i, int j) {
        return dis1[i] - dis2[i] < dis1[j] - dis2[j];
    });
    int tmp = dis1[a[0]];
    for (int i = 1; i < k; ++i) {
        max = std::max(max, tmp + 1 + dis2[a[i]]);
        tmp = std::max(tmp, dis1[a[i]]);
    }
    ans = std::min(ans, max);
    std::cout << ans << "\n";
    return 0;
}
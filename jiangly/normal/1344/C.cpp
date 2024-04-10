#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> e(n), e1(n);
    std::vector<int> deg(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u;
        --v;
        e[u].push_back(v);
        e1[v].push_back(u);
        ++deg[v];
    }
    std::queue<int> que;
    int cnt = 0;
    for (int i = 0; i < n; ++i)
        if (deg[i] == 0)
            que.push(i);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        ++cnt;
        for (auto v : e[u])
            if (--deg[v] == 0)
                que.push(v);
    }
    if (cnt < n) {
        std::cout << -1 << "\n";
        return 0;
    }
    std::vector<bool> vis(n), vis1(n);
    std::string s;
    auto bfs = [&](int s, auto &e, auto &vis) {
        que.push(s);
        while (!que.empty()) {
            int u = que.front();
            que.pop();
            if (vis[u])
                continue;
            vis[u] = true;
            for (auto v : e[u])
                que.push(v);
        }
    };
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        if (vis[i] || vis1[i]) {
            s += 'E';
        } else {
            ++ans;
            s += 'A';
        }
        bfs(i, e, vis);
        bfs(i, e1, vis1);
    }
    std::cout << ans << "\n";
    std::cout << s << "\n";
    return 0;
}
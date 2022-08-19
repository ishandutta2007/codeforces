#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::vector<int>> e(n);
    std::vector<int> deg(n);
    
    int self = 0;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v;
        --u, --v;
        deg[u]++;
        deg[v]++;
        if (u == v) {
            ++self;
        } else {
            e[u].push_back(v);
            e[v].push_back(u);
        }
    }
    
    std::vector<bool> vis(n);
    std::queue<int> que;
    int s = 0;
    while (deg[s] == 0) {
        ++s;
    } 
    que.push(s);
    vis[s] = true;
    int cnt = 0;
    while (!que.empty()) {
        int u = que.front();
        cnt += deg[u];
        que.pop();
        for (auto v : e[u]) {
            if (!vis[v]) {
                vis[v] = true;
                que.push(v);
            }
        }
    }
    if (cnt < 2 * m) {
        std::cout << 0 << "\n";
        return 0;
    }
    
    int64_t ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += int64_t(e[i].size()) * (e[i].size() - 1) / 2;
    }
    
    ans += int64_t(self) * (self - 1) / 2 + int64_t(self) * (m - self);
    
    std::cout << ans << "\n";
    
    return 0;
}
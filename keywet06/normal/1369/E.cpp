#include <bits/stdc++.h>

const int N = 100005;
const int M = 200005;

int n, m;
int w[N], sum[N], vis[M];

std::vector<std::pair<int, int>> e[N];

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    for (int i = 0; i < n; ++i) std::cin >> w[i];
    std::vector<int> ans;
    for (int i = 0; i < m; ++i) {
        int u, v;
        std::cin >> u >> v, --u, --v;
        e[u].emplace_back(v, i);
        e[v].emplace_back(u, i);
        ++sum[u], ++sum[v];
    }
    std::queue<int> que;
    for (int i = 0; i < n; ++i) {
        if (sum[i] <= w[i]) que.push(i);
    }
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (auto [v, i] : e[u]) {
            if (vis[i]) continue;
            vis[i] = 1;
            ans.push_back(i);
            if (--sum[v] == w[v]) que.push(v);
        }
    }
    if (int(ans.size()) < m) {
        std::cout << "DEAD\n";
        return 0;
    }
    std::cout << "ALIVE\n";
    std::reverse(ans.begin(), ans.end());
    for (int i = 0; i < m; ++i) std::cout << ans[i] + 1 << " \n"[i == m - 1];
    return 0;
}
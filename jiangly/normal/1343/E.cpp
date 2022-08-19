#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <queue>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m, a, b, c;
        std::cin >> n >> m >> a >> b >> c;
        --a;
        --b;
        --c;
        std::vector<int> p(m);
        for (int i = 0; i < m; ++i)
            std::cin >> p[i];
        std::vector<long long> sum(m + 1);
        std::sort(p.begin(), p.end());
        for (int i = 0; i < m; ++i)
            sum[i + 1] = sum[i] + p[i];
        std::vector<std::vector<int>> e(n);
        for (int i = 0; i < m; ++i) {
            int u, v;
            std::cin >> u >> v;
            --u;
            --v;
            e[u].push_back(v);
            e[v].push_back(u);
        }
        auto bfs = [&](int s) {
            std::vector<int> dis(n, -1);
            std::queue<int> que;
            dis[s] = 0;
            que.push(s);
            while (!que.empty()) {
                int u = que.front();
                que.pop();
                for (auto v : e[u]) {
                    if (dis[v] == -1) {
                        dis[v] = dis[u] + 1;
                        que.push(v);
                    }
                }
            }
            return dis;
        };
        auto da = bfs(a), db = bfs(b), dc = bfs(c);
        long long ans = 1e18;
        for (int i = 0; i < n; ++i) {
            if (da[i] + db[i] + dc[i] > m)
                continue;
            ans = std::min(ans, sum[db[i]] + sum[da[i] + db[i] + dc[i]]);
        }
        std::cout << ans << "\n";
    }
    return 0;
}
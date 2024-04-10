#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);

    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> e(n, std::vector<int>(n, -2));

    for (int i = 0; i < m; ++i) {
        int u, v, x;
        std::cin >> u >> v >> x;
        --u, --v;
        e[u][v] = x;
        e[v][u] = -x;
    }

    std::vector<int> color(n, -1);
    std::queue<int> que;
    color[0] = 0;
    que.push(0);
    while (!que.empty()) {
        int u = que.front();
        que.pop();
        for (int v = 0; v < n; ++v) {
            if (e[u][v] != -2) {
                if (color[v] == color[u]) {
                    std::cout << "NO\n";
                    return 0;
                }
                if (color[v] == -1) {
                    color[v] = !color[u];
                    que.push(v);
                }
            }
        }
    }

    auto solve = [&]() {
        std::vector<std::vector<int>> dis(n, std::vector<int>(n, 1e9));
        for (int i = 0; i < n; ++i) {
            dis[i][i] = 0;
        }

        for (int i = 0; i < n; ++i) {
            if (color[i] == 0) {
                for (int j = 0; j < n; ++j) {
                    if (e[i][j] != -2) {
                        if (e[i][j] == 1) {
                            dis[i][j] = dis[j][i] = 0;
                        } else if (e[i][j] == -1) {
                            dis[i][j] = -1;
                            dis[j][i] = 1;
                        } else {
                            dis[i][j] = 0;
                            dis[j][i] = 1;
                        }
                    }
                }
            }
        }

        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    dis[i][j] = std::min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }

        std::vector<int> ans;
        int val = -1;

        for (int i = 0; i < n; ++i) {
            if (dis[i][i] < 0) {
                return std::make_pair(-1, std::vector<int>());
            }
            std::vector<int> x(n);
            for (int j = 0; j < n; ++j) {
                x[j] = 2 * dis[i][j] + color[j];
            }
            int res = 0;
            for (int j = 0; j < n; ++j) {
                if (x[j] < x[i]) {
                    res = -1;
                    break;
                }
                res = std::max(res, x[j] - x[i]);
            }
            if (res > val) {
                val = res;
                ans = x;
            }
        }

        return std::make_pair(val, ans);
    };

    auto [val, ans] = solve();
    if (ans.empty()) {
        std::cout << "NO\n";
        return 0;
    }
    std::cout << "YES\n";
    std::cout << val << "\n";
    for (int i = 0; i < n; ++i) {
        std::cout << ans[i] << " \n"[i == n - 1];
    }

    return 0;
}
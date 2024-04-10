#include <bits/stdc++.h>

const std::vector<std::pair<int, int>> moves{{0, -1}, {-1, 0}, {0, 1}, {1, 0}};

int n, m, k, q;

std::vector<bool> vis;
std::vector<std::vector<int>> a, pos, dis;

std::deque<int> que;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m >> k;
    a.assign(n, std::vector<int>(m));
    pos.resize(k);
    dis.assign(k, std::vector<int>(n * m + k, std::numeric_limits<int>::max()));
    vis.resize(n * m + k);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
            --a[i][j];
            pos[a[i][j]].push_back(i * m + j);
        }
    }
    for (int c = 0; c < k; ++c) {
        dis[c][n * m + c] = 0;
        que.push_back(n * m + c);
        std::fill(vis.begin(), vis.end(), false);
        while (!que.empty()) {
            int u = que.front();
            que.pop_front();
            if (vis[u]) continue;
            vis[u] = true;
            if (u >= n * m) {
                for (int p : pos[u - n * m]) {
                    if (dis[c][p] > dis[c][u]) {
                        dis[c][p] = dis[c][u];
                        que.push_front(p);
                    }
                }
            } else {
                int x = u / m, y = u % m;
                for (auto [dx, dy] : moves) {
                    int x1 = x + dx, y1 = y + dy, v = x1 * m + y1;
                    if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m &&
                        dis[c][v] > dis[c][u] + 1) {
                        dis[c][v] = dis[c][u] + 1;
                        que.push_back(v);
                    }
                }
                if (dis[c][n * m + a[x][y]] > dis[c][u] + 1) {
                    dis[c][n * m + a[x][y]] = dis[c][u] + 1;
                    que.push_back(n * m + a[x][y]);
                }
            }
        }
    }
    std::cin >> q;
    for (int i = 0; i < q; ++i) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        --x1, --y1, --x2, --y2;
        int ans = std::abs(x1 - x2) + std::abs(y1 - y2);
        int u = x1 * m + y1, v = x2 * m + y2;
        for (int c = 0; c < k; ++c) {
            ans = std::min(ans, dis[c][u] + dis[c][v] + 1);
        }
        std::cout << ans << "\n";
    }
    return 0;
}
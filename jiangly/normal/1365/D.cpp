#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
constexpr int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::string> a(n);
        int cg = 0;
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            for (int j = 0; j < m; ++j)
                if (a[i][j] == 'G')
                    ++cg;
        }
        if (!cg) {
            std::cout << "Yes\n";
            continue;
        }
        a[n - 1][m - 1] = 'G';
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 'B') {
                    for (int k = 0; k < 4; ++k) {
                        int x = i + dx[k], y = j + dy[k];
                        if (0 <= x && x < n && 0 <= y && y < m) {
                            if (a[x][y] == 'G')
                                ok = false;
                            if (a[x][y] == '.')
                                a[x][y] = '#';
                        }
                    }
                }
            }
        }
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m));
        vis[n - 1][m - 1] = true;
        std::queue<std::pair<int, int>> que;
        que.emplace(n - 1, m - 1);
        while (!que.empty()) {
            auto [i, j] = que.front();
            que.pop();
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k], y = j + dy[k];
                if (0 <= x && x < n && 0 <= y && y < m && a[x][y] != '#' && !vis[x][y]) {
                    vis[x][y] = true;
                    que.emplace(x, y);
                }
            }
        }
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (a[i][j] == 'G' && !vis[i][j])
                    ok = false;
        if (ok) {
            std::cout << "Yes\n";
        } else {
            std::cout << "No\n";
        }
    }
    return 0;
}
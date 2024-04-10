#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <functional>
#include <queue>
constexpr int dx[] = {-1, 1, 0, 0}, dy[] = {0, 0, -1, 1};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m;
    std::cin >> n >> m;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; ++i)
        std::cin >> a[i];
    int wRow = 0, wCol = 0;
    for (int i = 0; i < n; ++i) {
        int cntB = 0, lB = -1, rB = -1;
        for (int j = 0; j < m; ++j) {
            if (a[i][j] == '#') {
                ++cntB;
                if (lB == -1)
                    lB = j;
                rB = j;
            }
        }
        if (lB != -1 && rB - lB + 1 != cntB) {
            std::cout << -1 << "\n";
            return 0;
        }
        if (lB == -1)
            ++wRow;
    }
    for (int i = 0; i < m; ++i) {
        int cntB = 0, lB = -1, rB = -1;
        for (int j = 0; j < n; ++j) {
            if (a[j][i] == '#') {
                ++cntB;
                if (lB == -1)
                    lB = j;
                rB = j;
            }
        }
        if (lB != -1 && rB - lB + 1 != cntB) {
            std::cout << -1 << "\n";
            return 0;
        }
        if (lB == -1)
            ++wCol;
    }
    if (wRow == n) {
        std::cout << 0 << "\n";
    } else if ((wRow == 0 && wCol > 0) || (wCol == 0 && wRow > 0)) {
        std::cout << -1 << "\n";
    } else {
        int ans = 0;
        std::vector<std::vector<bool>> vis(n, std::vector<bool>(m));
        std::queue<std::pair<int, int>> que;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == '#' && !vis[i][j]) {
                    que.emplace(i, j);
                    ++ans;
                    while (!que.empty()) {
                        auto [x, y] = que.front();
                        que.pop();
                        if (vis[x][y])
                            continue;
                        vis[x][y] = true;
                        for (int k = 0; k < 4; ++k) {
                            int x1 = x + dx[k];
                            int y1 = y + dy[k];
                            if (0 <= x1 && x1 < n && 0 <= y1 && y1 < m && a[x1][y1] == '#')
                                que.emplace(x1, y1);
                        }
                    }
                }
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}
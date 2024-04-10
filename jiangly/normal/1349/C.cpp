#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
constexpr long long INF = 1e18;
constexpr int dx[] = {0, 0, -1, 1}, dy[] = {-1, 1, 0, 0};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, m, t;
    std::cin >> n >> m >> t;
    std::vector<std::string> s(n);
    for (int i = 0; i < n; ++i)
        std::cin >> s[i];
    std::vector<std::vector<long long>> d(n, std::vector<long long>(m, INF));
    std::queue<std::pair<int, int>> que;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            bool ok = false;
            for (int k = 0; k < 4; ++k) {
                int x = i + dx[k];
                int y = j + dy[k];
                if (0 <= x && x < n && 0 <= y && y < m && s[i][j] == s[x][y])
                    ok = true;
            }
            if (ok) {
                d[i][j] = 0;
                que.emplace(i, j);
            }
        }
    }
    while (!que.empty()) {
        auto [i, j] = que.front();
        que.pop();
        for (int k = 0; k < 4; ++k) {
            int x = i + dx[k];
            int y = j + dy[k];
            if (0 <= x && x < n && 0 <= y && y < m && d[x][y] == INF) {
                d[x][y] = d[i][j] + 1;
                que.emplace(x, y);
            }
        }
    }
    while (t--) {
        int x, y;
        long long p;
        std::cin >> x >> y >> p;
        --x;
        --y;
        std::cout << ((s[x][y] - '0') ^ (p & 1) ^ (std::min(p, d[x][y]) & 1)) << "\n";
    }
    return 0;
}
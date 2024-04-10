#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <tuple>
std::tuple<int, int, char, char> moves[] = {{0, -1, 'L', 'R'}, {0, 1, 'R', 'L'}, {-1, 0, 'U', 'D'}, {1, 0, 'D', 'U'}};
int n;
std::vector<std::vector<int>> x, y;
std::vector<std::string> ans;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n;
    x.assign(n, std::vector<int>(n));
    y.assign(n, std::vector<int>(n));
    ans.assign(n, std::string(n, '?'));
    std::queue<std::pair<int, int>> que;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> x[i][j] >> y[i][j];
            if (x[i][j] != -1) {
                --x[i][j];
                --y[i][j];
                if (i == x[i][j] && j == y[i][j]) {
                    ans[i][j] = 'X';
                    que.emplace(i, j);
                }
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (x[i][j] == -1 && ans[i][j] == '?') {
                for (auto [dx, dy, to, from] : moves) {
                    int x1 = i + dx, y1 = j + dy;
                    if (0 <= x1 && x1 < n && 0 <= y1 && y1 < n && x[x1][y1] == -1 && ans[x1][y1] == '?') {
                        ans[i][j] = to;
                        ans[x1][y1] = from;
                        que.emplace(i, j);
                        que.emplace(x1, y1);
                        break;
                    }
                }
            }
        }
    }
    while (!que.empty()) {
        auto [i, j] = que.front();
        que.pop();
        for (auto [dx, dy, to, from] : moves) {
            int x1 = i + dx, y1 = j + dy;
            if (0 <= x1 && x1 < n && 0 <= y1 && y1 < n && x[x1][y1] == x[i][j] && y[x1][y1] == y[i][j] && ans[x1][y1] == '?') {
                ans[x1][y1] = from;
                que.emplace(x1, y1);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (ans[i][j] == '?') {
                std::cout << "INVALID\n";
                return 0;
            }
        }
    }
    std::cout << "VALID\n";
    for (int i = 0; i < n; ++i)
        std::cout << ans[i] << "\n";
    return 0;
}
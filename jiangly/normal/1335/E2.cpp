#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <numeric>
#include <set>
const std::pair<int, int> P[] = {{0, 0}, {3, 1}, {6, 2}, {1, 3}, {4, 4}, {7, 5}, {2, 6}, {5, 7}, {8, 8}};
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
            --a[i];
        }
        std::vector<std::vector<int>> pos(200);
        for (int i = 0; i < n; ++i)
            pos[a[i]].push_back(i);
        int ans = 0;
        for (int x = 0; x < 200; ++x) {
            if (pos[x].empty())
                continue;
            ans = std::max(ans, int(pos[x].size()));
            std::vector<int> l(200), r(200);
            for (int i = 0; i < 200; ++i)
                r[i] = pos[i].size();
            for (int i = 0; 2 * (i + 1) <= int(pos[x].size()); ++i) {
                for (int y = 0; y < 200; ++y) {
                    while (l[y] < r[y] && pos[y][l[y]] <= pos[x][i])
                        ++l[y];
                    while (l[y] < r[y] && pos[y][r[y] - 1] >= pos[x][pos[x].size() - i - 1])
                        --r[y];
                    ans = std::max(ans, 2 * (i + 1) + r[y] - l[y]);
                }
            }
        }
        std::cout << ans << "\n";
    }
    return 0;
}
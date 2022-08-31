#include <iostream>
#include <numeric>
#include <algorithm>
#include <functional>
#include <vector>
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> a(n, std::vector<int>(m));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                std::cin >> a[i][j];
        int ans = 0;
        for (int i = 0; 2 * i < n + m - 2; ++i) {
            int cnt[2] = {};
            int j = n + m - 2 - i;
            for (int x = 0; x < n; ++x) {
                if (0 <= i - x && i - x < m)
                    ++cnt[a[x][i - x]];
                if (0 <= j - x && j - x < m)
                    ++cnt[a[x][j - x]];
            }
            ans += std::min(cnt[0], cnt[1]);
        }
        std::cout << ans << "\n";
    }
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
int n, m, ans;
std::vector<std::vector<int>> a;
std::vector<int> cnt;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cin >> n >> m;
    a.assign(n, std::vector<int>(m));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cin >> a[i][j];
            --a[i][j];
        }
    }
    cnt.resize(n);
    for (int c = 0; c < m; ++c) {
        std::fill(cnt.begin(), cnt.end(), 0);
        for (int r = 0; r < n; ++r)
            if (a[r][c] % m == c && a[r][c] < n * m)
                ++cnt[(r - a[r][c] / m + n) % n];
        int min = n;
        for (int i = 0; i < n; ++i)
            min = std::min(min, n - cnt[i] + i);
        ans += min;
    }
    std::cout << ans << "\n";
    return 0;
}
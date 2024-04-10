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
        int r = 0, c = 0;
        for (int i = 0; i < n; ++i)
            if (std::accumulate(a[i].begin(), a[i].end(), 0) == 0)
                ++r;
        for (int i = 0; i < m; ++i) {
            int x = 0;
            for (int j = 0; j < n; ++j)
                x += a[j][i];
            if (!x)
                ++c;
        }
        if (std::min(r, c) & 1) {
            std::cout << "Ashish\n";
        } else {
            std::cout << "Vivek\n";
        }
    }
    return 0;
}
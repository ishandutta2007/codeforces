#include <bits/stdc++.h>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, m;
        std::cin >> n >> m;
        std::vector<std::vector<int>> a(n, std::vector<int>(m));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char ch;
                std::cin >> ch;
                a[i][j] = ch - '0';
            }
        }
        std::vector<std::tuple<int, int, int, int, int, int>> ans;
        
        auto change = [&](int x1, int y1, int x2, int y2, int x3, int y3) {
            ans.emplace_back(x1, y1, x2, y2, x3, y3);
            a[x1][y1] ^= 1;
            a[x2][y2] ^= 1;
            a[x3][y3] ^= 1;
        };
        
        for (int i = n - 1; i >= 2; --i) {
            for (int j = 0; j < m; ++j) {
                if (a[i][j] == 1) {
                    if (j > 0) {
                        change(i, j, i - 1, j, i - 1, j - 1);
                    } else {
                        change(i, j, i - 1, j, i - 1, j + 1);
                    }
                }
            }
        }
        
        for (int i = m - 1; i >= 2; --i) {
            if (a[0][i] == 1) change(0, i, 0, i - 1, 1, i - 1);
            if (a[1][i] == 1) change(1, i, 1, i - 1, 0, i - 1);
        }
        
        if (a[1][1] == 1) change(0, 1, 1, 0, 1, 1);
        
        if (a[0][0] + a[0][1] + a[1][0] == 3) {
            change(0, 0, 0, 1, 1, 0);
        } else if (a[0][0] + a[0][1] == 2) {
            change(0, 0, 1, 0, 1, 1);
            change(0, 1, 1, 0, 1, 1);
        } else if (a[0][0] + a[1][0] == 2) {
            change(0, 0, 0, 1, 1, 1);
            change(1, 0, 0, 1, 1, 1);
        } else if (a[1][0] + a[0][1] == 2) {
            change(1, 0, 0, 0, 1, 1);
            change(0, 1, 0, 0, 1, 1);
        } else if (a[0][0] == 1) {
            change(0, 0, 0, 1, 1, 0);
            change(0, 0, 0, 1, 1, 1);
            change(0, 0, 1, 1, 1, 0);
        } else if (a[0][1] == 1) {
            change(0, 1, 0, 0, 1, 1);
            change(0, 1, 0, 0, 1, 0);
            change(0, 1, 1, 0, 1, 1);
        } else if (a[1][0] == 1) {
            change(1, 0, 1, 1, 0, 0);
            change(1, 0, 1, 1, 0, 1);
            change(1, 0, 0, 1, 0, 0);
        }
        
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) assert(a[i][j] == 0);
        std::cout << ans.size() << "\n";
        for (auto [a, b, c, d, e, f] : ans) std::cout << a + 1 << " " << b + 1 << " " << c + 1 << " " << d + 1 << " " << e + 1 << " " << f + 1 << "\n";
    }
    
    return 0;
}
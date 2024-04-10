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
        bool ok = true;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                int adj = 4 - (i == 0) - (i == n - 1) - (j == 0) - (j == m - 1);
                int x;
                std::cin >> x;
                if (x > adj)
                    ok = false;
                a[i][j] = adj;
            }
        }
        if (ok) {
            std::cout << "YES\n";
            for (int i = 0; i < n; ++i)
                for (int j = 0; j < m; ++j)
                    std::cout << a[i][j] << " \n"[j == m - 1];
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
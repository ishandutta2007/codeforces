#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector a(n, std::vector<int>(5));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            std::cin >> a[i][j];
        }
    }
    
    for (int x = 0; x < 5; x++) {
        for (int y = x + 1; y < 5; y++) {
            int cx = 0, cy = 0;
            bool ok = true;
            for (int i = 0; i < n; i++) {
                if (a[i][x] == 1) {
                    cx++;
                }
                if (a[i][y] == 1) {
                    cy++;
                }
                if (a[i][x] == 0 && a[i][y] == 0) {
                    ok = false;
                }
            }
            if (n % 2 == 0 && cx >= n / 2 && cy >= n / 2 && ok) {
                std::cout << "YES\n";
                return;
            }
        }
    }
    
    std::cout << "NO\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
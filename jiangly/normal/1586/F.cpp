#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector c(n, std::vector<int>(n));
    int res = 0, v = 1;
    while (v < n) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (i / v % k != j / v % k) {
                    c[i][j] = res;
                }
            }
        }
        v *= k;
        res++;
    }
    
    std::cout << res << "\n";
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            std::cout << c[i][j] + 1 << " \n"[i == n - 2 && j == n - 1];
        }
    }
}

int main() {
    // std::ios::sync_with_stdio(false);
    // std::cin.tie(nullptr);
    
    int t = 1;
    // std::cin >> t;
    
    while (t--) {
        solve();
    }
    
    return 0;
}
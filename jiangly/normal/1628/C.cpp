#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector a(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cin >> a[i][j];
        }
    }
    
    int ans = 0;
    
    std::vector<int> c(n), x(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            c[j] ^= 1;
            if (c[j]) {
                ans ^= a[i][j];
            }
        }
        std::swap(c, x);
        for (int j = 0; j < n; j++) {
            if (j < n - 1) {
                c[j + 1] ^= x[j];
            }
            if (j > 0) {
                c[j - 1] ^= x[j];
            }
        }
    }
    assert(c == std::vector(n, 1));
    
    std::cout << ans << "\n";
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
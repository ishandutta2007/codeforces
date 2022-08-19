#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector belong(n, std::vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            belong[i][j] = belong[j][n - i - 1] = belong[n - i - 1][n - j - 1] = belong[n - j - 1][i] = i * n + j;
        }
    }
    
    std::vector c(n * n, std::array<int, 2>());
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char ch;
            std::cin >> ch;
            c[belong[i][j]][ch - '0']++;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < n * n; i++) {
        ans += std::min(c[i][0], c[i][1]);
    }
    
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
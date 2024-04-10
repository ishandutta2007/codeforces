#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector a(n, std::vector<int>(m));
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        std::string s;
        std::cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j] - '0';
            cnt  += a[i][j];
        }
    }
    
    if (!cnt) {
        std::cout << "0\n";
        return;
    }
    
    int ans = 4;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m - 1; j++) {
            int t = a[i][j] + a[i][j + 1] + a[i + 1][j] + a[i + 1][j + 1];
            if (t) {
                ans = std::min(ans, std::max(1, t - 1));
            }
        }
    }
    std::cout << cnt - ans + 1 << "\n";
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
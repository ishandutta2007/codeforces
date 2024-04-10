#include <bits/stdc++.h>

using i64 = long long;

char get(int x, int y) {
    x %= 5;
    y %= 5;
    return 'a' + x * 5 + y;
}

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    int mn = (n % 2 == 1 ? m / 2 : 0);
    int mx = n * m / 2 - (m % 2 == 1 ? n / 2 : 0);
    
    if (mn <= k && k <= mx && (k - mn) % 2 == 0) {
        std::cout << "YES\n";
        
        std::vector<std::string> ans(n, std::string(m, '?'));
        if (n % 2 == 1) {
            for (int i = 0; i < m; i += 2) {
                ans[n - 1][i] = ans[n - 1][i + 1] = get(n - 1, i);
            }
            k -= mn;
        }
        
        for (int i = 0; i + 1 < n; i += 2) {
            for (int j = 0; j < m; j++) {
                ans[i][j] = ans[i + 1][j] = get(i, j);
            }
        }
        
        for (int j = 0; j < m; j += 2) {
            for (int i = 0; i + 1 < n; i += 2) {
                if (k > 0) {
                    ans[i][j] = ans[i][j + 1] = get(i, j);
                    ans[i + 1][j] = ans[i + 1][j + 1] = get(i + 1, j);
                    k -= 2;
                }
            }
        }
        
        for (int i = 0; i < n; i++) {
            std::cout << ans[i] << "\n";
        }
    } else {
        std::cout << "NO\n";
    }
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
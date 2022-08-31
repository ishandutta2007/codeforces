#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::string s[n];
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    int res = 1E9;
    
    for (int i1 = 0; i1 < n; i1++) {
        int cnt[m] = {};
        for (int i2 = i1 + 2; i2 < n; i2++) {
            for (int j = 0; j < m; j++) {
                cnt[j] += (s[i2 - 1][j] - '0');
            }
            if (i2 - i1 < 4) {
                continue;
            }
            int c1[m] = {}, c2[m] = {}, c3[m] = {};
            for (int j = 0; j < m - 1; j++) {
                c1[j + 1] = c1[j] + (s[i1][j] == '0');
                c2[j + 1] = c2[j] + (s[i2][j] == '0');
                c3[j + 1] = c3[j] + cnt[j];
            }
            for (int j = 0, x = 1E9; j < m; j++) {
                if (j >= 3) {
                    x = std::min(x, i2 - i1 - 1 - cnt[j - 3] - c1[j - 2] - c2[j - 2] - c3[j - 2]);
                }
                res = std::min(res, x + i2 - i1 - 1 - cnt[j] + c1[j] + c2[j] + c3[j]);
            }
        }
    }
    
    std::cout << res << "\n";
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
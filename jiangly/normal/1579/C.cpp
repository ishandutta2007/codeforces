#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    std::string s[n];
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '.') {
                continue;
            }
            int d = 0;
            while (d < i && d < j && j + d + 1 < m && s[i - d - 1][j - d - 1] != '.' && s[i - d - 1][j + d + 1] != '.') {
                d++;
            }
            if (d >= k) {
                for (int l = 0; l <= d; l++) {
                    s[i - l][j - l] = 'X';
                    s[i - l][j + l] = 'X';
                }
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '*') {
                std::cout << "NO\n";
                return;
            }
        }
    }
    std::cout << "YES\n";
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
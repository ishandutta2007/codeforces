#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    for (int j = 0; j < m; j++) {
        int last = n;
        for (int i = n - 1; i >= 0; i--) {
            if (s[i][j] == 'o') {
                last = i;
            } else if (s[i][j] == '*') {
                s[i][j] = '.';
                last--;
                s[last][j] = '*';
            }
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << s[i] << "\n";
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
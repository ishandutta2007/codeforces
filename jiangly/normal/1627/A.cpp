#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, r, c;
    std::cin >> n >> m >> r >> c;
    r--;
    c--;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    if (s == std::vector(n, std::string(m, 'W'))) {
        std::cout << "-1\n";
        return;
    }
    
    int cr = 0, cc = 0;
    for (int i = 0; i < m; i++) {
        cr += s[r][i] == 'B';
    }
    for (int i = 0; i < n; i++) {
        cc += s[i][c] == 'B';
    }
    
    if (s[r][c] == 'B') {
        std::cout << "0\n";
    } else if (cr > 0 || cc > 0) {
        std::cout << "1\n";
    } else {
        std::cout << "2\n";
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
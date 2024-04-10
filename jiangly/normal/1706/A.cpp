#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::string s(m, 'B');
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        x--;
        if (x > m - 1 - x) {
            x = m - 1 - x;
        }
        if (s[x] == 'B') {
            s[x] = 'A';
        } else {
            s[m - 1 - x] = 'A';
        }
    }
    
    std::cout << s << "\n";
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
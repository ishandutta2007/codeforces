#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s[2];
    std::cin >> s[0] >> s[1];
    
    for (int i = 0; i < n; i++) {
        if (s[0][i] == '1' && s[1][i] == '1') {
            std::cout << "NO\n";
            return;
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
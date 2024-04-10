#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    if (s[0] + s[1] + s[2] == s[3] + s[4] + s[5]) {
        std::cout << "YES\n";
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
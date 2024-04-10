#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s, t;
    std::cin >> s >> t;
    
    for (auto &x : s) {
        if (x == 'G') {
            x = 'B';
        }
    }
    for (auto &x : t) {
        if (x == 'G') {
            x = 'B';
        }
    }
    if (s == t) {
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
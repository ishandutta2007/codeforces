#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    if (s.back() == 'A') {
        std::cout << "NO\n";
        return;
    }
    
    int balance = 0;
    for (int i = 0; i < int(s.length()); i++) {
        if (s[i] == 'A') {
            balance++;
        } else {
            balance--;
        }
        if (balance < 0) {
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
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    for (int i = 0; i < 3; i++) {
        if (std::islower(s[i])) {
            s[i] = std::toupper(s[i]);
        }
    }
    
    std::cout << (s == "YES" ? s : "NO") << "\n";
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
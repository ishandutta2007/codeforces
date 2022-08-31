#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    for (auto t : {'a' + s, s + 'a'}) {
        if (t != std::string(t.rbegin(), t.rend())) {
            std::cout << "YES\n";
            std::cout << t << "\n";
            return;
        }
    }
    
    std::cout << "NO\n";
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
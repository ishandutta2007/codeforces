#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::set<char> s;
    for (int i = 0; i < 4; i++) {
        char c;
        std::cin >> c;
        s.insert(c);
    }
    std::cout << s.size() - 1 << "\n";
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
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    
    auto f = [&](auto s) {
        int b = 0;
        std::string t;
        for (auto c : s) {
            if (c == 'B') {
                b ^= 1;
            } else if (!t.empty() && t.back() == c) {
                t.pop_back();
            } else {
                t += c;
            }
        }
        return std::pair(b, t);
    };
    
    if (f(s) == f(t)) {
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
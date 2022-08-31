#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    int c[2] {};
    for (auto x : s) {
        c[x - '0']++;
    }
    
    std::cout << std::min(c[0], c[1]) - (c[0] == c[1]) << "\n";
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
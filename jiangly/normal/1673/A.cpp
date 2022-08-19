#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    int sum = 0;
    for (auto c : s) {
        sum += c - 'a' + 1;
    }
    
    int alice = sum;
    
    if (s.length() % 2 == 1) {
        alice -= std::min(s[0], s.back()) - 'a' + 1;
    }
    
    int bob = sum - alice;
    
    if (alice > bob) {
        std::cout << "Alice " << alice - bob << "\n";
    } else {
        std::cout << "Bob " << bob - alice << "\n";
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
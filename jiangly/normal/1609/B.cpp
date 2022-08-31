#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, q;
    std::cin >> n >> q;
    
    std::string s;
    std::cin >> s;
    
    int ans = 0;
    for (int i = 0; i + 3 <= n; i++) {
        ans += s.substr(i, 3) == "abc";
    }
    
    while (q--) {
        int x;
        char ch;
        std::cin >> x >> ch;
        x--;
        
        for (int i = std::max(0, x - 2); i <= std::min(n - 3, x); i++) {
            ans -= s.substr(i, 3) == "abc";
        }
        s[x] = ch;
        for (int i = std::max(0, x - 2); i <= std::min(n - 3, x); i++) {
            ans += s.substr(i, 3) == "abc";
        }
        
        std::cout << ans << "\n";
    }
    
    
    return 0;
}
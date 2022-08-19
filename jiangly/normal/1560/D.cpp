#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    int res = 1E9;
    
    for (int i = 0; i < 64; i++) {
        std::string t = std::to_string(1ULL << i);
        
        int k = 0;
        for (int j = 0; j < int(s.length()); j++) {
            if (k < int(t.length()) && s[j] == t[k]) {
                k++;
            }
        }
        
        res = std::min(res, int(s.length()) + int(t.length()) - 2 * k);
    }
    
    std::cout << res << "\n";
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
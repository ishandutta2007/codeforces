#include <bits/stdc++.h>

using i64 = long long;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        std::string s, t;
        std::cin >> s >> t;
        int n = s.length();
        
        bool ans = false;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n && j - i + 1 <= int(t.length()); j++) {
                if (s[j] != t[j - i]) {
                    break;
                }
                if (int(t.length()) > j - i + 1 + j) {
                    continue;
                }
                bool ok = true;
                for (int k = 0; k < int(t.length()) - (j - i + 1); k++) {
                    if (t[j - i + 1 + k] != s[j - k - 1]) {
                        ok = false;
                    }
                }
                if (ok) {
                    ans = true;
                }
            }
        }
        
        std::cout << (ans ? "YES" : "NO") << "\n";
    }
    
    return 0;
}
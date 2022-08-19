#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    int n = s.length();
    
    for (int i = 0; i < n; ) {
        int j = i;
        while (j < n && s[i] == s[j]) {
            j++;
        }
        
        if (j - i == 1) {
            std::cout << "NO\n";
            return;
        }
        i = j;
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
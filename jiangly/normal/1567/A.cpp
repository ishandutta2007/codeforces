#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == 'U') {
            s[i] = 'D';
        } else if (s[i] == 'D') {
            s[i] = 'U';
        }
    }
    
    std::cout << s << "\n";
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
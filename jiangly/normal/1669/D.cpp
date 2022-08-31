#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    int last = -1;
    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] == 'W') {
            auto t = s.substr(last + 1, i - last - 1);
            last = i;
            
            int c = std::count(t.begin(), t.end(), 'R');
            if (!t.empty() && (c == 0 || c == int(t.length()))) {
                std::cout << "NO\n";
                return;
            }
        }
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
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<std::string> s(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    auto ss = std::set(s.begin(), s.end());
    
    for (int i = 0; i < n; i++) {
        if (ss.count(std::string(s[i].rbegin(), s[i].rend()))) {
            std::cout << "YES\n";
            return;
        }
    }
    
    for (int _ = 0; _ < 2; _++) {
        bool f[26][26] = {};
        for (int i = 0; i < n; i++) {
            if (s[i].length() == 2) {
                f[s[i][0] - 'a'][s[i][1] - 'a'] = true;
            } else if (f[s[i][2] - 'a'][s[i][1] - 'a']) {
                std::cout << "YES\n";
                return;
            }
        }
        std::reverse(s.begin(), s.end());
        for (auto &x : s) {
            std::reverse(x.begin(), x.end());
        }
    }
    
    std::cout << "NO\n";
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
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s, t;
    std::cin >> s >> t;
    
    int n = s.length(), m = t.length();
    int j = 0;
    for (int i = (n ^ m) & 1; i < n && j < m; i += 2) {
        if (s[i] == t[j]) {
            j++;
            i--;
        }
    }
    if (j == m) {
        std::cout << "YES\n";
        return;
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
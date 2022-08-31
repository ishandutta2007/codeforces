#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s, t;
    std::cin >> s >> t;
    
    std::vector<int> a, b;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] != s[i]) {
            a.push_back(i);
        }
        if (t[i - 1] != t[i]) {
            b.push_back(i);
        }
    }
    
    if (s[0] != t[0] || a.size() != b.size()) {
        std::cout << "-1\n";
        return;
    }
    
    i64 ans = 0;
    for (int i = 0; i < int(a.size()); i++) {
        ans += std::abs(a[i] - b[i]);
    }
    std::cout << ans << "\n";
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
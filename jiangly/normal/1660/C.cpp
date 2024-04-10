#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    std::string s;
    std::cin >> s;
    
    int ans = 0;
    bool f[26] = {};
    for (auto c : s) {
        if (!f[c - 'a']) {
            f[c - 'a'] = true;
            ans++;
        } else {
            std::fill(f, f + 26, false);
            ans--;
        }
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
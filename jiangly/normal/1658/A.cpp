#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    if (s == std::string(n, '1')) {
        std::cout << "0\n";
        return;
    }
    
    int ans = 0;
    for (int i = 0, j = -1; i < n; i++) {
        if (s[i] == '0') {
            if (j != -1) {
                ans += std::max(0, 3 - (i - j));
            }
            j = i;
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
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::string s;
    std::cin >> s;
    
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            if (i < n / 2) {
                std::cout << i + 1 << " " << n << " " << i + 2 << " " << n << "\n";
            } else {
                std::cout << 1 << " " << i + 1 << " " << 1 << " " << i << "\n";
            }
            return;
        }
    }
    
    std::cout << 1 << " " << n / 2 * 2 << " " << 1 << " " << n / 2 << "\n";
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
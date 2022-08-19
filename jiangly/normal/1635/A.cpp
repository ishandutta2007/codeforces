#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        ans |= x;
    }
    
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    for (int i = 0; i < t; i++) {
        solve();
    }
    
    return 0;
}
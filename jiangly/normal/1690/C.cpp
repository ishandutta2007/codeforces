#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> s(n), f(n);
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> f[i];
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << f[i] - std::max(i == 0 ? 0 : f[i - 1], s[i]) << " \n"[i == n - 1];
    }
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
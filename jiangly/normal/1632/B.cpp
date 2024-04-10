#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    int k = 1;
    
    while (2 * k < n) {
        k *= 2;
    }
    
    for (int i = k - 1; i >= 0; i--) {
        std::cout << i << " ";
    }
    for (int i = k; i < n; i++) {
        std::cout << i << " \n"[i == n - 1];
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
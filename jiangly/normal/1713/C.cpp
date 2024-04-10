#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> p(n);
    int r = n, x = 2 * std::sqrt(n);
    while (r > 0) {
        while (x * x > 2 * r - 2) {
            x--;
        }
        int v = x * x;
        for (int i = v - r + 1; i < r; i++) {
            p[i] = v - i;
        }
        r = v - r + 1;
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << p[i] << " \n"[i == n - 1];
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
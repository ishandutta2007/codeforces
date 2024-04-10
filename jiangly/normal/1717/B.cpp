#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k, r, c;
    std::cin >> n >> k >> r >> c;
    r--, c--;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            std::cout << ".X"[((i - j) % k + k) % k == ((r - c) % k + k) % k];
        }
        std::cout << "\n";
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
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    int d12, d23, d31;
    std::cin >> d12 >> d23 >> d31;
    
    if ((d12 + d23 + d31) % 2) {
        std::cout << "NO\n";
        return;
    }
    
    const int x1 = (d12 + d31 - d23) / 2;
    const int x2 = (d12 + d23 - d31) / 2;
    const int x3 = (d31 + d23 - d12) / 2;
    
    if (x1 < 0 || x2 < 0 || x3 < 0) {
        std::cout << "NO\n";
        return;
    }
    
    if (x1 + x2 + x3 + 1 > n) {
        std::cout << "NO\n";
        return;
    }
    
    int cnt = 3;
    int root;
    if (x1 == 0) {
        root = 1;
    } else if (x2 == 0) {
        root = 2;
    } else if (x3 == 0) {
        root = 3;
    } else {
        root = ++cnt;
    }
    
    std::cout << "YES\n";
    if (x1) {
        int cur = root;
        for (int i = 1; i < x1; i++) {
            std::cout << cur << " " << ++cnt << "\n";
            cur = cnt;
        }
        std::cout << cur << " " << 1 << "\n";
    }
    if (x2) {
        int cur = root;
        for (int i = 1; i < x2; i++) {
            std::cout << cur << " " << ++cnt << "\n";
            cur = cnt;
        }
        std::cout << cur << " " << 2 << "\n";
    }
    if (x3) {
        int cur = root;
        for (int i = 1; i < x3; i++) {
            std::cout << cur << " " << ++cnt << "\n";
            cur = cnt;
        }
        std::cout << cur << " " << 3 << "\n";
    }
    while (cnt < n) {
        std::cout << 1 << " " << ++cnt << "\n";
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
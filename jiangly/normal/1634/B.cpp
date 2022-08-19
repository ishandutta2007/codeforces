#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, x;
    i64 y;
    std::cin >> n >> x >> y;
    
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        x ^= a;
    }
    
    if (x % 2 == y % 2) {
        std::cout << "Alice\n";
    } else {
        std::cout << "Bob\n";
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
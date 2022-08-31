#include <bits/stdc++.h>

void solve() {
    int x, y;
    std::cin >> x >> y;
    
    if ((x + y) % 2 == 1) {
        std::cout << "-1 -1\n";
    } else {
        std::cout << x / 2 << ' ' << (y + 1) / 2 << '\n';
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
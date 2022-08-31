#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    int x = 0;
    for (int i = 0; i < n; i++) {
        int y;
        std::cin >> y;
        x += y - 1;
    }
    if (x % 2 == 0) {
        std::cout << "maomao90\n";
    } else {
        std::cout << "errorgorn\n";
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
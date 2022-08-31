#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int sum = 0;
    for (int i = 0; i < 4; i++) {
        int x;
        std::cin >> x;
        sum += x;
    }
    
    if (sum == 0) {
        std::cout << "0\n";
    } else if (sum == 4) {
        std::cout << "2\n";
    } else {
        std::cout << "1\n";
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
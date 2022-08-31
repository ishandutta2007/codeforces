#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    if (n % 7 == 0) {
        std::cout << n << "\n";
    } else {
        n -= n % 10;
        n += 9;
        n -= n % 7;
        std::cout << n << "\n";
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
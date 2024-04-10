#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int k;
    std::cin >> k;
    
    int x = std::ceil(std::sqrt(k));
    
    int t = k - (x - 1) * (x - 1);
    if (t <= x) {
        std::cout << t << " " << x << "\n";
    } else {
        std::cout << x << " " << x - (t - x) << "\n";
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
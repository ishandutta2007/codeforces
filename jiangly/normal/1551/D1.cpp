#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    
    int mn = (n % 2 == 1 ? m / 2 : 0);
    int mx = n * m / 2 - (m % 2 == 1 ? n / 2 : 0);
    
    if (mn <= k && k <= mx && (k - mn) % 2 == 0) {
        std::cout << "YES\n";
    } else {
        std::cout << "NO\n";
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
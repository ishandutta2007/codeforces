#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> p;
    
    if (n % 2 == 1) {
        std::cout << 1 << " \n"[n == 1];
    }
    for (int i = n % 2 + 1; i <= n; i += 2) {
        std::cout << i + 1 << " " << i << " \n"[i == n - 1];
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
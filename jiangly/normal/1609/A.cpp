#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    i64 ans = 0;
    std::vector<i64> a(n);
    int x = 0;
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        int c = __builtin_ctzll(a[i]);
        a[i] >>= c;
        x += c;
    }
    std::sort(a.begin(), a.end());
    a.back() <<= x;
    
    std::cout << std::accumulate(a.begin(), a.end(), 0LL) << "\n";
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
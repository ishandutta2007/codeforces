#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        cnt[x]++;
    }
    
    int m = 0;
    for (auto [a, b] : cnt) {
        m = std::max(m, b);
    }
    
    int k = 0;
    while ((m << k) < n) {
        k++;
    }
    std::cout << k + n - m << "\n";
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
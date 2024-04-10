#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, l;
    std::cin >> n >> l;
    
    std::vector<int> cnt(l);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        for (int j = 0; j < l; j++) {
            cnt[j] += x >> j & 1;
        }
    }
    
    int ans = 0;
    for (int i = 0; i < l; i++) {
        if (cnt[i] > n - cnt[i]) {
            ans |= 1 << i;
        }
    }
    std::cout << ans << "\n";
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
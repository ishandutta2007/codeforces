#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    int cnt[2] = {};
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        cnt[x % 2]++;
    }
    
    std::cout << std::min(cnt[0], cnt[1]) << "\n";
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
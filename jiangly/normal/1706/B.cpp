#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> ans(n), last(n);
    for (int i = 0; i < n; i++) {
        int x;
        std::cin >> x;
        x--;
        
        if (ans[x] == 0 || (i % 2 != last[x])) {
            ans[x]++;
            last[x] = i % 2;
        }
    }
    
    for (int i = 0; i < n; i++) {
        std::cout << ans[i] << " \n"[i == n - 1];
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
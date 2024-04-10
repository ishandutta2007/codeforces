#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::string s;
    std::cin >> s;
    
    std::vector<int> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + (s[i] == 'W');
    }
    
    int ans = k;
    for (int i = 0; i <= n - k; i++) {
        ans = std::min(ans, sum[i + k] - sum[i]);
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
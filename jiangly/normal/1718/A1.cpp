#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> s(n + 1);
    for (int i = 0; i < n; i++) {
        s[i + 1] = s[i] ^ a[i];
    }
    
    std::vector<int> dp(n + 1);
    std::map<int, int> lst;
    lst[s[0]] = 0;
    for (int i = 1; i <= n; i++) {
        dp[i] = dp[i - 1];
        if (lst.count(s[i])) {
            dp[i] = std::max(dp[i], 1 + dp[lst[s[i]]]);
        }
        lst[s[i]] = i;
    }
    std::cout << n - dp[n] << "\n";
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
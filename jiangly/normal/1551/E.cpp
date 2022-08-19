#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
    }
    
    std::vector<int> p(n);
    std::iota(p.begin(), p.end(), 0);
    std::sort(p.begin(), p.end(), [&](int i, int j) { return a[i] < a[j]; });
    
    std::vector<int> dp(k + 1, -1);
    dp[0] = 0;
    
    for (int l = 0, r; l < n; l = r) {
        r = l;
        while (r < n && a[p[l]] == a[p[r]]) {
            r++;
        }
        
        for (int j = k; j > 0; j--) {
            for (int u = l; u < r; u++) {
                int i = p[u];
                if (dp[j - 1] >= 0 && dp[j - 1] <= i - a[i] && (dp[j] < 0 || dp[j] > i - a[i])) {
                    dp[j] = i - a[i];
                }
            }
        }
    }
    
    std::cout << dp[k] << "\n";
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
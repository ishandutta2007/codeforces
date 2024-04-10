#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::vector<int> sum(n + 1);
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + (a[i] < i + 1);
    }
    
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] < i + 1 && a[i] > 0) {
            ans += sum[std::min(n, a[i] - 1)];
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
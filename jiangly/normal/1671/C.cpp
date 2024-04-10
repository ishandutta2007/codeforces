#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, x;
    std::cin >> n >> x;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::sort(a.begin(), a.end());
    int days = 0;
    i64 sum = 0;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        sum += a[i];
        if (sum > x) {
            ans += 1LL * i * days;
            days = 0;
            break;
        }
        
        int newDays = (x - sum) / (i + 1) + 1;
        ans += 1LL * i * (days - newDays);
        days = newDays;
    }
    ans += 1LL * n * days;
    
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
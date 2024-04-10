#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    i64 sum = std::accumulate(a.begin(), a.end(), 0LL);
    
    if (sum * 2 % n != 0) {
        std::cout << "0\n";
        return;
    }
    
    int need = sum * 2 / n;
    std::map<int, int> cnt;
    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cnt[need - a[i]];
        cnt[a[i]]++;
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
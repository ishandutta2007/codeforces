#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    i64 ans = 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        if (i < n - 1) {
            ans += a[i];
        }
    }
    
    int j = 0;
    while (j < n - 1 && !a[j]) {
        j++;
    }
    ans += std::count(a.begin() + j, a.end() - 1, 0);
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
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    i64 n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    std::sort(a.begin(), a.end());
    
    i64 mn = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        mn += a[i];
        mx += a[i];
    }
    mn += 1LL * (n - 2) * a[0];
    mx += 1LL * (n - 2) * a[n - 1];
    if (mn > 0 || mx < 0) {
        std::cout << "INF\n";
        return;
    }
    
    i64 ans = -1E18;
    i64 coef = 0, cons = 0;
    for (int i = 1; i < n; i++) {
        coef += a[0] + a[i];
        cons += 1LL * a[0] * a[i];
    }
    for (int i = 1; i < n; i++) {
        i64 l = -a[i], r = -a[i - 1];
        ans = std::max({ans, coef * l + cons, coef * r + cons});
        coef -= a[0];
        coef += a[n - 1];
        cons += 1LL * a[i] * (a[n - 1] - a[0]);
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
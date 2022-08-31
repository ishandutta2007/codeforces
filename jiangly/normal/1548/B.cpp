#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<i64> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int ans = 0;
    n--;
    std::vector<i64> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = a[i + 1] - a[i];
    }
    
    std::vector<std::pair<i64, int>> f;
    for (int i = 0; i < n; i++) {
        f.emplace_back(b[i], i);
        i64 v = b[i];
        for (int j = f.size() - 1; j >= 0; j--) {
            v = std::gcd(v, f[j].first);
            f[j].first = v;
        }
        int k = 0;
        for (int j = 0; j < int(f.size()); j++) {
            if (k == 0 || f[j].first != f[k - 1].first) {
                f[k++] = f[j];
            }
        }
        f.resize(k);
        int j = 0;
        while (j < k && f[j].first == 1) {
            j++;
        }
        if (j < k) {
            ans = std::max(ans, i + 1 - f[j].second);
        }
    }
    
    ans++;
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
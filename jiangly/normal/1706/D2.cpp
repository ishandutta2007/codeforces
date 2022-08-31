#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int m = a.back();
    int min = a[0];
    
    std::vector<std::vector<int>> f(m + 1);
    for (int i = 0; i < n; i++) {
        f[a[i]].push_back(i);
    }
    
    int ans = m;
    for (int max = m; max >= 0; max--) {
        ans = std::min(ans, max - min);
        for (auto i : f[max]) {
            if (max == a[i] / k) {
                std::cout << ans << "\n";
                return;
            }
            int v = a[i] / (a[i] / max + 1);
            f[v].push_back(i);
            min = std::min(min, v);
        }
        f.pop_back();
    }
    assert(false);
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
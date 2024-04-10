#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<i64> f(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            i64 x;
            std::cin >> x;
            f[i] += j * x;
        }
    }
    
    std::map<i64, int> cnt;
    for (int i = 0; i < n; i++) {
        cnt[f[i]]++;
    }
    for (int i = 0; i < n; i++) {
        if (cnt[f[i]] == 1) {
            std::cout << i + 1 << " " << f[i] - f[(i + 1) % n] << "\n";
            return;
        }
    }
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
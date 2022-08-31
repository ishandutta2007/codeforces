#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n), cnt(n);
    std::vector<std::vector<int>> f(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        f[cnt[a[i]]].push_back(i);
        cnt[a[i]]++;
    }
    
    std::vector<int> b(n);
    for (int i = 0; i < n; i++) {
        if (!f[i].empty()) {
            std::sort(f[i].begin(), f[i].end(), [&](int i, int j) { return a[i] < a[j]; });
            int k = f[i].size();
            for (int j = 0; j < k; j++) {
                b[f[i][j]] = a[f[i][(j + 1) % k]];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        std::cout << b[i] + 1 << " \n"[i == n - 1];
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
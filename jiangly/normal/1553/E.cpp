#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    
    std::vector<int> a(n), cnt(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i]--;
        cnt[(i - a[i] + n) % n]++;
    }
    
    std::vector<int> ans;
    
    for (int k = 0; k < n; k++) {
        if (cnt[k] >= n - 2 * m) {
            std::vector<int> p(n);
            for (int i = 0; i < n; i++) {
                p[(i - k + n) % n] = a[i];
            }
            int cyc = 0;
            std::vector<bool> vis(n);
            for (int i = 0; i < n; i++) {
                if (vis[i]) {
                    continue;
                }
                int j = i;
                while (!vis[j]) {
                    vis[j] = true;
                    j = p[j];
                }
                cyc++;
            }
            if (n - cyc <= m) {
                ans.push_back(k);
            }
        }
    }
    
    std::cout << ans.size();
    for (auto k : ans) {
        std::cout << " " << k;
    }
    std::cout << "\n";
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
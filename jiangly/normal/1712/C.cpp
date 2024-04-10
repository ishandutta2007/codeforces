#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    std::vector<std::vector<int>> pos(n + 1);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        pos[a[i]].push_back(i);
    }
    
    
    int bad = 0, ans = 0;
    for (int i = 0; i < n - 1; i++) {
        bad += a[i] > a[i + 1];
    }
    
    for (int i = 0; i < n && bad > 0; i++) {
        if (a[i] > 0) {
            ans++;
            for (auto j : pos[a[i]]) {
                if (j < n - 1) {
                    bad -= a[j] > a[j + 1];
                }
                if (j > 0) {
                    bad -= a[j - 1] > a[j];
                }
                a[j] = 0;
                if (j < n - 1) {
                    bad += a[j] > a[j + 1];
                }
                if (j > 0) {
                    bad += a[j - 1] > a[j];
                }
            }
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
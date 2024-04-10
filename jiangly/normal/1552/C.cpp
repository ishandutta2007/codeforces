#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> x(k), y(k);
    
    std::vector<int> a(2 * n, 1), s(2 * n + 1);
    for (int i = 0; i < k; i++) {
        std::cin >> x[i] >> y[i];
        x[i]--;
        y[i]--;
        if (x[i] > y[i]) {
            std::swap(x[i], y[i]);
        }
        a[x[i]] = a[y[i]] = 0;
    }
    for (int i = 0; i < 2 * n; i++) {
        s[i + 1] = s[i] + a[i];
    }
    
    int ans = (n - k) * (n - k - 1) / 2;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            if (x[i] < x[j] && x[j] < y[i] && y[i] < y[j]) {
                ans++;
            }
        }
        ans += std::min(s[y[i]] - s[x[i]], s[2 * n] - s[y[i]] + s[x[i]]);
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
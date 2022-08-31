#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector a(2, std::vector<int>(n));
    for (int j = 0; j < 2; j++) {
        for (int i = 0; i < n; i++) {
            std::cin >> a[j][i];
        }
    }
    a[0][0] = -1;
    
    std::vector sp(a), sm(a);
    for (int j = 0; j < 2; j++) {
        for (int i = n - 1; i >= 0; i--) {
            sp[j][i] += i;
            sm[j][i] -= i;
            if (i < n - 1) {
                sp[j][i] = std::max(sp[j][i], sp[j][i + 1]);
                sm[j][i] = std::max(sm[j][i], sm[j][i + 1]);
            }
        }
    }
    int ans = std::numeric_limits<int>::max();
    int cur = 0;
    for (int i = 0; i < n; i++) {
        int x = i % 2;
        ans = std::min(ans, std::max({cur, sm[x][i] + 2 * n - i, sp[!x][i] - i + 1}));
        cur = std::max({cur, a[x][i] + 2 * (n - i), a[!x][i] + 2 * (n - i) - 1});
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
#include <bits/stdc++.h>

using i64 = long long;

void solve() {
    int n;
    std::cin >> n;
    
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int p = 0, l = 0, r = 0;
    for (int j = -1, i = 0; i <= n; i++) {
        if (i == n || a[i] == 0) {
            int pw = 0, sgn = 0;
            std::pair<int, int> mn[2] = {std::pair(0, j + 1), std::pair(n, -1)};
            for (int k = j + 1; k < i; k++) {
                if (a[k] < 0) {
                    sgn ^= 1;
                }
                if (std::abs(a[k]) == 2) {
                    pw++;
                }
                if (pw - mn[sgn].first > p) {
                    p = pw - mn[sgn].first;
                    l = mn[sgn].second;
                    r = k + 1;
                }
                mn[sgn] = std::min(mn[sgn], std::pair(pw, k + 1));
            }
            j = i;
        }
    }
    
    std::cout << l << " " << n - r << "\n";
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
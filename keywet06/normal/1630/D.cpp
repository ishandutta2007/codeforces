#include <bits/stdc++.h>

using int64 = long long;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) std::cin >> a[i];
    int L = 0;
    for (int i = 0; i < m; ++i) {
        int x;
        std::cin >> x, L = std::gcd(L, x);
    }
    int64 ans = -1E18;
    for (int _ = 0; _ < 2; ++_) {
        int64 sum = 0;
        for (int x = 0; x < L; ++x) {
            int cnt = 0, mn = 1E9;
            for (int i = x; i < n; i += L) {
                cnt += (a[i] < 0);
                mn = std::min(mn, std::abs(a[i]));
                sum += std::abs(a[i]);
            }
            if (cnt % 2 == 1) sum -= 2 * mn;
        }
        ans = std::max(ans, sum);
        for (int i = 0; i < L; ++i) a[i] *= -1;
    }
    std::cout << ans << "\n";
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--) solve();
    return 0;
}
#include <bits/stdc++.h>
constexpr int P = 1000000007;
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, x, pos;
    std::cin >> n >> x >> pos;
    int l = 0, r = n;
    int L = 0, R = 0;
    while (l < r) {
        int m = (l + r) / 2;
        if (pos < m) r = m, ++R;
        else l = m + 1, L += m != pos;
    }
    int ans = 1;
    for (int i = 1; i <= L; ++i) ans = int64_t(ans) * (x - i) % P;
    for (int i = 1; i <= R; ++i) ans = int64_t(ans) * (n - x - i + 1) % P;
    for (int i = 1; i <= n - L - R - 1; ++i) ans = int64_t(ans) * i % P;
    std::cout << ans << "\n";
    
    return 0;
}
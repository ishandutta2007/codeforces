#include <bits/stdc++.h>
using int64 = long long;
int n, a, la;
int64 ans;
int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    std::cin >> n;
    std::cin >> la;
    ans += 1ll * la * (n - la + 1);
    for (int i = 1; i < n; ++i) {
        std::cin >> a;
        ans += 1ll * a * (n - a + 1);
        ans -= 1ll * std::min(a, la) * (n + 1 - std::max(a, la));
        la = a;
    }
    std::cout << ans << std::endl;
    return 0;
}
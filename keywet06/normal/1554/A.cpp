#include <bits/stdc++.h>

using int64 = long long;

const int N = 1000005;

int T, n, x, y, z;

int64 ans;
int64 a[N];

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> T;
    while (T--) {
        std::cin >> n;
        for (int i = 1; i <= n; ++i) std::cin >> a[i];
        ans = 0;
        for (int i = 1; i < n; ++i) ans = std::max(ans, a[i] * a[i + 1]);
        std::cout << ans << '\n';
    }
    return 0;
}
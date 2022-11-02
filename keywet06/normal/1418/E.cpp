#include <bits/stdc++.h>

using int64 = long long;

const int N = 200005;
const int P = 998244353;

int64 n, m, ta, tb, ans, low, hg;
int64 a[N], inv[N], pre[N];

int64 bpow(int64 x, int64 y) {
    int64 ret = 1, cur = x;
    while (y) {
        if (y & 1) ret = (ret * cur) % P;
        y /= 2;
        cur = (cur * cur) % P;
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0), std::cout.tie(0);
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i) std::cin >> a[i];
    std::sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; ++i) pre[i] = (pre[i - 1] + a[i]) % P;
    for (int i = 1; i < N; ++i) inv[i] = bpow(i, P - 2);
    for (int i = 0; i < m; ++i) {
        std::cin >> ta >> tb;
        ans = 0;
        low = std::lower_bound(a + 1, a + n + 1, tb) - (a + 1);
        hg = n - low;
        if (hg < ta) {
            std::cout << 0 << '\n';
            continue;
        }
        ans = pre[low] * (hg + 1 - ta) % P * inv[hg + 1] % P;
        ans +=
            (pre[n] - pre[low] + P) % P * (hg - ta) % P * inv[hg] % P;
        std::cout << ans % P << '\n';
    }
    return 0;
}
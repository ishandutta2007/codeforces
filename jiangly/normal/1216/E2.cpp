#include <bits/stdc++.h>
using namespace std;
using LL = int64_t;
constexpr int INF = 1e9;
constexpr LL INFLL = 1e18;
LL sum(LL l, LL r) {
    return (l + r) * (r - l + 1) / 2;
}
LL calc(LL x) {
    LL k = 1;
    LL ans = 0;
    for (int i = 1; k <= x; ++i, k *= 10)
        ans += i * sum(x - min(x, 10 * k - 1) + 1, x - k + 1);
    return ans;
}
LL calc1(LL x) {
    LL k = 1;
    LL ans = 0;
    for (int i = 1; k <= x; ++i, k *= 10)
        ans += i * (min(x, 10 * k - 1) - k + 1);
    return ans;
}
void solve() {
    LL k;
    cin >> k;
    --k;
    LL x = 0;
    for (LL i = 1 << 29; i > 0; i >>= 1)
        if (calc(x + i) <= k)
            x += i;
    k -= calc(x);
    x = 0;
    for (LL i = 1 << 29; i > 0; i >>= 1)
        if (calc1(x + i) <= k)
            x += i;
    k -= calc1(x);
    cout << to_string(x + 1)[k] << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
typedef long long llong;

const llong inf = 5e18;
llong A[10000001];
void solve() {
    llong n, l, r, x, y, z, b1, b2;
    cin >> n >> l >> r >> x >> y >> z >> b1 >> b2;
    for (int i = 1; i <= n; ++i) {
        if (i == 1) A[i] = (b1 % (r - l + 1)) + l;
        else if (i == 2) A[i] = (b2 % (r - l + 1)) + l;
        else {
            llong b3 = (b1 * x + b2 * y + z) & ((1ll << 32) - 1);
            A[i] = (b3 % (r - l + 1)) + l;
            b1 = b2;
            b2 = b3;
        }
    }
    llong mn = r + 1;
    llong ans = inf;
    for (int i = 1; i <= n; ++i) {
        if (mn < A[i]) ans = min(ans, mn * A[i]);
        else mn = A[i];
    }
    llong mx = l - 1;
    for (int i = n; i > 0; --i) {
        if (A[i] < mx) ans = min(ans, mx * A[i]);
        else if (A[i] < 0) mx = A[i];
    }
    if (ans < inf) printf("%lld\n", ans);
    else printf("IMPOSSIBLE\n");
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}
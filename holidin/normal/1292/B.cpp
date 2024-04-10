#include <bits/stdc++.h>
//#pragma GCC optimize 03
#define fi first
#define se second
#define int long long
#define ld long double
using namespace std;
const int N = 2e6 + 1;
int bad = 0;
int m[2][N];
int x[N], y[N];

void solve() {
    int i, j, k, n, q, ans = 0, ax, ay, bx, by, xs, ys, t, top = 0;
    cin >> x[0] >> y[0] >> ax >> ay >> bx >> by;
    cin >> xs >> ys >> t;
    for (i = 1; i < 100; ++i) {
        x[i] = x[i - 1] * ax + bx;
        y[i] = y[i - 1] * ay + by;
        if (x[i] > 3e16 || y[i] > 3e16) {
            top = i;
            break;
        }
    }
    for (i = 0; i < top; ++i)
    for (j = i; j < top; ++j)
    if (min(abs(xs - x[i]) + abs(ys - y[i]), abs(xs - x[j]) + abs(ys - y[j])) + x[j] - x[i] + y[j] - y[i] <= t)
        ans = max(ans, j - i + 1);
    cout << ans;
}

signed main() {
    #ifdef local
        freopen("input.txt", "r", stdin);
    #endif
    ios_base::sync_with_stdio(false); cin.tie(0);

    solve();
}
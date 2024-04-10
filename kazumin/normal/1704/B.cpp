#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ld long double
#define pii pair<int, int>
#define f first
#define s second
#define boost() cin.tie(0), cin.sync_with_stdio(0)

const int MN = 200005;

int t, n, x, a[MN];

int32_t main() {
    boost();

    cin >> t;
    while (t--) {
        cin >> n >> x;
        int mn = 0x3f3f3f3f, mx = -0x3f3f3f3f, ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mx = max(mx, a[i]);
            mn = min(mn, a[i]);
            if (mx - mn > 2 * x) ans++, mn = mx = a[i];
        }
        printf("%lld\n", ans);
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        ll a = 0, b = 0;
        ll now = 0;
        ll x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        ll x = max(x1, x2);
        ll y = min(y1, y2);
        if (x <= y) {
            now = (y - x) * n;
            a = (y1 + y2 - x1 - x2 - 2 * (y - x)) * n;
            k -= now;
            if (k <= 0) {
                cout << 0 << endl;
                continue;
            } else if (k <= a) {
                cout << k << endl;
                continue;
            } else {
                k -= a;
                cout << k * 2 + a << endl;
                continue;
            }
        } else {
            ll d = x - y;
            ll mx = min(x1, x2);
            ll my = max(y1, y2);
            a = 2 * d + y2 + y1 - x1 - x2;
            b = (my - mx);
            if (b * n <= k) {
                ll ans = a * n;
                k -= b * n;
                ans += k * 2;
                cout << ans << endl;
                continue;
            } else {
                ll ans = (k / b) * a;
                ll kk = k;
                k -= (k / b) * b;
                ll mmin = d + k;
                if (kk >= b) mmin = min(mmin, 2 * k);
                ans += mmin;
                cout << ans << endl;
                continue;
            }
        }
    }
}
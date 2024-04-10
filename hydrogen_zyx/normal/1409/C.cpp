#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll t, n;
    cin >> t;
    while (t--) {
        ll x, y;
        cin >> n >> x >> y;
        ll mmin = 0x3f3f3f3f3f3f3f3f;
        ll ss, dd;
        for (ll i = 1; i <= n - 1; i++) {
            if ((y - x) % i) continue;
            ll d = (y - x) / i;
            ll c = (x - 1) / d;
            ll ans = max(y, x - c * d + d * (n - 1));
            if (ans < mmin) {
                mmin = ans;
                dd = d;
                ss = x - c * d;
                if (ans == y) {
                    ss = y - (n - 1) * d;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ss + (i - 1) * dd << ' ';
        }
        cout << endl;
    }
}
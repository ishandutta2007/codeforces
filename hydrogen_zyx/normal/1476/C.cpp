#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = cos(-1.0);
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll a[N], b[N], c[N];

int main() {
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        for (ll i = 1; i <= n; i++) {
            cin >> c[i];
            c[i]--;
        }
        for (ll i = 1; i <= n; i++) cin >> a[i];
        for (ll i = 1; i <= n; i++) cin >> b[i];
        for (ll i = 1; i <= n; i++) if (a[i] > b[i]) swap(a[i], b[i]);
        ll ans = 0;
        ll now = c[n];
        for (ll i = n - 1; i > 0; i--) {
            now += 2;
            if (a[i + 1] == b[i + 1]) {
                ans = max(ans, now);
                now = c[i];
            } else {
                ans = max(ans, now + b[i + 1] - a[i + 1]);
                now += c[i] - (b[i + 1] - a[i + 1]);
            }
            now = max(now, c[i]);
        }
//        now = now - c[1] + (b[2] - a[2]) * 2;
//        ans = max(now, ans);
        cout << ans << endl;
    }
}
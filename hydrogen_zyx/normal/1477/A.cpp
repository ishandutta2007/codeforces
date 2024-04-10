#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = cos(-1.0);
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll a[N], b[N];

int main() {
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> a[i];
        ll mmin = 0x3f3f3f3f3f3f3f3f;
        for (int i = 1; i <= n; i++) mmin = min(mmin, a[i]);
        for (int i = 1; i <= n; i++) b[i] = a[i] - mmin;
        ll ans = 0;
        for (int i = 1; i <= n; i++) ans = gcd(ans, b[i]);
        bool ok = 0;
//        cout << ans << endl;
        for (int i = 1; i <= n; i++) {
            ll d = k - a[i];
            if (d < 0) d = -d;
            if (ans == 0) {
                if (d == 0) ok = 1;
            } else {
                if (d % ans == 0) ok = 1;
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
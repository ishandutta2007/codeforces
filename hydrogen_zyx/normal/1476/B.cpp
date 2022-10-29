#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1 << 20;
const ll mod = 1e9 + 7;
const double eps = 1e-9;
const double PI = cos(-1.0);
const ll inf = 0x3f3f3f3f3f3f3f3f;


ll a[N];

int main() {
    ios::sync_with_stdio(false);
    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        for (ll i = 1; i <= n; i++) cin >> a[i];
        ll l = 0, r = 1e14, mid;
        while (l < r) {
            mid = (l + r) >> 1;
            ll now = a[1] + mid;
            bool ok = 1;
            for (ll i = 2; i <= n; i++) {
                if (100 * a[i] > k * now) ok = 0;
                now += a[i];
            }
            if (ok) r = mid;
            else l = mid + 1;
        }
        cout << l << endl;
    }
}
#include<bits/stdc++.h>

using namespace std;

#define pii pair<ll,ll>
#define fi first
#define se second
#define de(x) cout<< #x << ' ' << x << endl;
typedef long long ll;
const ll N = 1e6 + 5;
const ll mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;

ll a[N];
ll tmp[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll l = 1, r = 1000000000;
        while (l < r) {
            ll mid = (l + r + 1) >> 1;
            ll cnt = 0;
            for (ll i = 1; i <= n; i++) {
                if (a[i] * 2 < mid) {
                    cnt++;
                    tmp[i] = 1000000000;
                } else {
                    tmp[i] = a[i];
                }
            }
            ll mmin = 2;
            for (ll i = 2; i <= n; i++) {
                if (min(tmp[i], tmp[i - 1]) >= mid) mmin = min(mmin, 0ll);
                if (tmp[i] >= mid || tmp[i - 1] >= mid) mmin = min(mmin, 1ll);
            }
            cnt += mmin;
            if (cnt <= k) l = mid;
            else r = mid - 1;
        }
        cout << l << endl;
    }
}
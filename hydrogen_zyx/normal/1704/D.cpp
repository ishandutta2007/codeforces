#include<bits/stdc++.h>

#define pii pair<ll,ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
using namespace std;
typedef long long ll;
const ll N = 1e6 + 5;
const ll mod = 1e9 + 7;

__int128 res[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        for (ll i = 1; i <= n; i++) res[i] = 0;
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= m; j++) {
                ll tmp;
                cin >> tmp;
                res[i] += ((__int128) 1 * j) * tmp;
            }
        }
        __int128 mmax = -0x3f3f3f3f;
        __int128 mmin = res[1];
        ll pos = 0;
        for (ll i = 1; i <= n; i++) {
            mmin = min(mmin, res[i]);
            if (res[i] > mmax) {
                mmax = res[i];
                pos = i;
            }
        }
        cout << pos << ' ' << ll(mmax - mmin) << endl;
    }
}
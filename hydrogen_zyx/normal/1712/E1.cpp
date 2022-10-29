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

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll lcm(ll a, ll b) {
    return a * b / gcd(a, b);
}

ll a[N];
ll cnt[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    ll tot = 0;
//    ll ln = 100;
//    for (ll i = 1; i <= ln; i++) {
//        for (ll j = i + 1; j <= ln; j++) {
//            for (ll k = j + 1; k <= ln; k++) {
//                ll lm = lcm(i, lcm(j, k));
//                if (lm >= i + j + k) {
//                    tot++;
////                    if (gcd(i, k) == i && gcd(j, k) == j) continue;
////                    if (j * 3 == k * 2) continue;
////                    cout << i << ' ' << j << ' ' << k << endl;
//                }
//            }
//        }
//    }
//    cout << tot << endl;
    ll t;
    cin >> t;
    while (t--) {
        ll l, r;
        cin >> l >> r;
        memset(cnt, 0, sizeof cnt);
        for (ll i = l; i <= r; i++) {
            for (ll j = i + i; j <= r; j += i) {
                cnt[j]++;
            }
        }
        ll ans = 0;
        for (ll i = l; i <= r; i++) {
            for (ll j = i; j <= 2 * r; j += i) {
                if (j % 2 != 0) continue;
                ll act = j / 2;
                if (act % 3 == 0 && act / 3 < i && i < 2 * act / 3) ans++;
            }
        }
        for (ll i = l; i <= r; i++) {
            ans += cnt[i] * (cnt[i] - 1) / 2;
        }
        ll len = r - l + 1;
        ans = len * (len - 1) * (len - 2) / 6 - ans;
        cout << ans << endl;

    }
}
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

ll a[N];

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        cin >> n >> m;
        for (ll i = 0; i < m; i++) cin >> a[i];
        sort(a, a + m);
        vector<ll> v;
        for (ll i = 0; i < m; i++) {
            if ((a[(i + 1) % m] - a[i] + n) % n == 1) {
                continue;
            }
            v.push_back((a[(i + 1) % m] - a[i] + n - 1 + n) % n);
        }
        sort(v.begin(), v.end(), [](ll a, ll b) { return a > b; });
        ll ans = 0;
        ll cost = 0;
        for (ll i = 0; i < v.size(); i++) {
            ll now = max(0ll, v[i] - cost * 2);
            if (now == 0) continue;
            if (now == 1 || now == 2) {
                cost++;
                ans++;
            } else {
                ans += now - 1;
                cost += 2;
            }
        }
        cout << n - ans << endl;
    }
}
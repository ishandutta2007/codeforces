#include<bits/stdc++.h>

using namespace std;
#define pii pair<ll,ll>
#define fi first
#define se second
#define pb push_back
#define de(x) cout<< #x << ' ' << x << endl;
typedef long long ll;
const ll N = 1e6 + 5;
const ll mod = 1e9 + 7;

ll a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    ll t;
    cin >> t;
    while (t--) {
        ll n;
        cin >> n;
        for (ll i = 1; i <= n; i++) cin >> a[i];
        ll sum = 0;
        for (ll i = 1; i <= n; i++) sum += a[i];
        bool ok = 1;
        if(sum!=0) ok = 0;
        for (ll i = 2; i <= n; i++) {
            a[i] += a[i - 1];
        }
        for (ll i = 1; i <= n; i++) if (a[i] < 0) ok = 0;
        ll pos = n;
        while (pos && a[pos] == 0) pos--;
        for (ll i = 1; i <= pos; i++) if (a[i] == 0) ok = 0;
        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
}
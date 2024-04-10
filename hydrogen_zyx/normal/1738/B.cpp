#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;

ll a[N];

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        for (ll i = 1; i <= k; i++) cin >> a[i];

        for (ll i = k; i > 1; i--) a[i] = a[i] - a[i - 1];
        bool f = 1;
        for (ll i = 3; i <= k; i++) if (a[i - 1] > a[i]) f = 0;
        if (k > 1) if (a[2] * (n - k + 1) < a[1]) f = 0;
        if (f) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
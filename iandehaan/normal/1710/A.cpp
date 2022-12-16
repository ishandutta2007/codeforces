#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(ll i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (ll)(x).size()
typedef long long ll;
typedef pair<ll, ll> pii;
typedef vector<ll> vi;

#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll t;
    cin >> t;
    while (t--) {
        ll n, m;
        ll k;
        cin >> n >> m >> k;
        ll a[k];
        rep(i, 0, k) cin >> a[i];
        sort(a, a+k);

        bool found = false;
        rep(i, 0, k) {
            //cout << a[i] << ' ' << n*m << endl;
            if (a[i] >= n*m) found = true; // fill with i
        }
        //cout << found << endl;

        // try filling vertically
        ll rowsfilled = 0;
        for (int i = k-1; i >= 0; i--) {
            if (a[i] / m >= 2) rowsfilled += a[i] / m;

            if (rowsfilled >= n && n >= 2*(k-i)) found = true;
        }

        // try filling horizontally
        ll colsfilled = 0;
        for (int i = k-1; i >= 0; i--) {
            if (a[i] / n >= 2) colsfilled += a[i] / n;

            if (colsfilled >= m && m >= 2*(k-i)) found = true;
        }

        if (found) cout << "Yes\n";
        else cout << "No\n";
    }
}
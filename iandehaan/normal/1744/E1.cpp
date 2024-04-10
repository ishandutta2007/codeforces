#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define pb push_back
#define mp make_pair

int main() {
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;
        ll fac = a*b;
        bool found = false;
        for (ll x = a+1; x <= c; x++) {
            // need fac = k*x*y
            ll remaining = fac/gcd(fac, x);
            // need y = k*remaining
            ll lo = 0;
            ll hi = 1e6;
            while (hi-lo > 1) {
                ll mid = (lo+hi)/2;
                ll amt = mid*remaining;
                if (amt > d) {
                    hi = mid;
                } else {
                    lo = mid;
                }
            }
            //cout << x << ' ' << lo << ' ' << hi << ' ' << remaining << '\n';
            if (lo*remaining > b && lo*remaining <= d) {
                cout << x << ' ' << lo*remaining << '\n';
                found = true;
                break;
            }
        }
        if (!found) cout << -1 << ' ' << -1 << '\n';
    }
}
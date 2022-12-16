#include <bits/stdc++.h>
using namespace std;

using ll = long long;


#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define pb push_back
#define mp make_pair

struct FT {
	vector<ll> s;
	FT(ll n) : s(n) {}
	void update(ll pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(ll pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	ll lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		ll pos = 0;
		for (ll pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, q, k;
    cin >> n >> q >> k;

    ll a[n];
    for (ll i = 0; i < n; i++) cin >> a[i];

    ll poss[n];
    for (ll i = 0; i < n; i++) {
        if (i == 0) {
            poss[i] = a[i+1]-1;
        } else if (i == n-1) {
            poss[i] = k-a[i-1];
        } else {
            poss[i] = a[i+1]-a[i-1]-1;
        }
    }

    FT ftree(n);
    for (ll i = 0; i < n; i++) ftree.update(i, poss[i]-1);

    while (q--) {
        ll l, r;
        cin >> l >> r;
        if (l == r) {
            cout << k-1 << endl;
            continue;
        }
        ll q1 = ftree.query(r-1);
        ll q2 = ftree.query(l);
        ll out = max((ll)0, q1-q2);
        out += a[l]-2;
        out += k-a[r-2]-1;
        //cout << q1-q2 << ' ' << a[l]-2 << ' ' << k-a[r-2]-1 << endl;
        cout << out << endl;
    }
}
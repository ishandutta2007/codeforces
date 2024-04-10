#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, A, cf, cm, m;
ll aorig[100005];
pair<ll, ll> work[100005];
ll a[100005];
ll z[100005];
ll b[100005];

ll sc_x[100005];
ll sc_y[100005], sclen;

ll sc_find(ll x) {
	ll i = upper_bound(sc_x, sc_x + sclen, x) - sc_x - 1;
	if (i == -1) {
		return 0;
	} else if (i == sclen-1) {
		return sc_y[sclen-1];
	} else {
		return sc_y[i] + (sc_y[i+1] - sc_y[i]) / (sc_x[i+1] - sc_x[i]) * (x - sc_x[i]);
	}
}

ll binarna(ll left) {
	ll l=1, r=A, o = 0;
	while (l <= r) {
		ll m = (l+r) >> 1;
		if (sc_find(m) <= left) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	return o;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> A >> cf >> cm >> m;
	for (ll i=0; i<n; i++) {
		cin >> aorig[i];
		work[i] = {aorig[i], i};
	}
	sort(work, work+n);
	for (int i=0; i<n; i++)
		a[i] = work[i].first;
	for (ll i=0; i<n; i++)
		z[i+1] = z[i] + a[i];

	// napravi sc
	sc_x[sclen] = a[0];
	sc_y[sclen++] = 0;
	a[n] = A;
	for (ll i=1; i<=n; i++) {
		sc_x[sclen] = a[i];
		sc_y[sclen] = sc_y[sclen-1] + i*(a[i] - a[i-1]);
		sclen++;
	}

	ll sol = -1, besti = -1, bestj = -1;

	for (ll i=0; i<=n; i++) {
		// ocu zadnjih i da mi postanu A
		ll left = m - (A*i - (z[n] - z[n-i]));

		// cerr << "spremam se da radim " << i << '\n';
		// for (int i=0; i<sclen; i++)
		// 	cerr << sc_x[i] << ":" << sc_y[i] << "  ";
		// cerr << '\n';

		if (left >= 0) {
			ll j = binarna(left);

			ll val = cf*i + cm*j;
			if (val > sol) {
				sol = val;
				besti = i;
				bestj = j;
			}
		}
		if (i < n) {
			sc_x[n-i-1] = A;
			if (i == n-1) {
				sc_y[0] = 0;
			} else {
				sc_y[n-i-1] = sc_y[n-i-2] + (n-i-1)*(A - a[n-i-2]);
			}
			sclen--;
		}
	}

	// mozda mogu da napravim da su svi jednaki A?
	if (A*n - z[n] <= m) {
		cout << cf*n + cm*A << '\n';
		for (int i=0; i<n; i++)
			cout << A << " \n"[i == n-1];
		return 0;
	}

	cout << sol << '\n';

	for (ll k=n-besti; k<n; k++)
		a[k] = A;
	for (ll k=0; k<n; k++)
		a[k] = max(a[k], bestj);

	for (ll i=0; i<n; i++)
		b[work[i].second] = a[i];

	for (ll i=0; i<n; i++)
		cout << b[i] << " \n"[i == n-1];
}
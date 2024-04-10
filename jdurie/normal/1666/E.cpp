#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
typedef long double ld;
typedef pair<ll, ll> pl;
typedef vector<ll> vl;

#define G(x) ll x; cin >> x;
#define F(i, l, r) for(ll i = l; i < (r); i++)
#define all(a) begin(a), end(a)
#define K first
#define V second
#define N 100010

ll n, lb, x[N], y[N], a[N], mn;

bool worksn(ll m) {
	ll r = 0;
	F(i, 0, n) {
		if(r > a[i]) return false;
		x[i] = max(r, a[i] - m);
		r = y[i] = x[i] + m;
	}
	return r <= lb;
}

ll bsn(ll l, ll r) {
	if(l == r) return l;
	ll m = (l + r + 1) / 2;
	return worksn(m) ? bsn(m, r) : bsn(l, m - 1);
}

bool worksx(ll m) {
	worksn(mn);
	ll cv = lb;
	for(ll i = n - 1; ~i; --i) {
		ll d = m - mn;
		if(d < cv - y[i]) {
		       	if(d + (a[i] - x[i]) < cv - y[i]) return false;
			ll shft = cv - y[i] - d;
			x[i] += shft, y[i] += shft;
		}
		d -= cv - y[i];
		y[i] = cv;
		ll k = min(d, x[i] - (i ? y[i - 1] : 0));
		x[i] -= k;
		cv = x[i];
	}
	return accumulate(y, y + n, 0ll) - accumulate(x, x + n, 0ll) == lb;
}

ll bsx(ll l, ll r) {
	if(l == r) { worksx(l); return l; }
	ll m = (l + r) / 2;
	return worksx(m) ? bsx(l, m) : bsx(m + 1, r);
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> lb >> n;
	F(i, 0, n) cin >> a[i];
	mn = bsn(1, 1e10);
	bsx(mn, 1e10);
	F(i, 0, n) cout << x[i] << ' ' << y[i] << '\n';
}
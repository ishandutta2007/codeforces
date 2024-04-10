// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

void g(ll l, ll r, ll u, ll v, ll xl, ll xr) {
	if (r <= xl || xr <= l)
		return;
	for (ll i=max(xl, l); i<min(xr, r); i++) {
		ll d = i-xl;
		if (d % 2 == 0)
			cout << u << ' ';
		else
			cout << u+(d/2)+1 << ' ';
	}
}

void s(ll l, ll r, ll x, ll xl, ll xr) {
	if (r <= xl || xr <= l)
		return;
	cout << x << ' ';
}

void f(ll l, ll r, ll u, ll v, ll xl, ll xr) {
	if (r <= xl || xr <= l)
		return;
	// prvi deo u, u+1, u, u+2, ..., u, v-1, u, v
	// obradi g-parce
	ll xm = xl + (v-u)*2;
	g(l, r, u, v, xl, xm);
	if (v - u >= 2)
		f(l, r, u+1, v, xm, xr);
}

void a(ll l, ll r, ll u, ll v, ll xl, ll xr) {
	if (r <= xl || xr <= l)
		return;
	f(l, r, u, v, xl, xr-1);
	s(l, r, u, xr-1, xr);
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	ll t;
	cin >> t;
	while (t--) {
		ll n, l, r;
		cin >> n >> l >> r;
		l--;
		a(l, r, 1, n, 0, n*(n-1) + 1);
		cout << '\n';
	}
}

// 1 2 1 3 1 4 1 5 1 6 2 3 2 4 2 5 3 4 3 5 4 5 2 6 3 6 4 6 5 6 1
// 1 2 1 3 1 4 1 5 1 6 2 3 2 4 2 5 2 6 3 4 3 5 3 6 4 5 4 6 5 6 1
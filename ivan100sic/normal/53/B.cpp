// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll ox = 0, oy = 0;

void aib(ll x, ll y) {
	ll diff = x*y - ox*oy;
	if (diff > 0 || (diff == 0 && x > ox)) {
		ox = x;
		oy = y;
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	ll x, y;
	cin >> x >> y;

	for (ll i=1; i<=1e12; i*=2) {
		ll jlo = (i*4+4)/5;
		ll jhi = i*5/4;

		if (jlo <= y && i <= x) {
			aib(i, min(y, jhi));
		}
	}

	for (ll j=1; j<=1e12; j*=2) {
		ll ilo = (j*4+4)/5;
		ll ihi = j*5/4;

		if (ilo <= x && j <= y) {
			aib(min(x, ihi), j);
		}
	}

	cout << ox << ' ' << oy << '\n';
}
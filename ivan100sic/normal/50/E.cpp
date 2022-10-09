#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll b, c;

ll fpy(ll r) {
	ll xlo = 1;
	xlo = max(xlo, (1+r*r+2*r-1)/(2*r));
	xlo = max(xlo, r);
	ll xhi = b;
	xhi = min(xhi, (c+r*r)/(2*r));
	return max(0ll, xhi-xlo+1);
}

ll fmy(ll r) {
	ll xlo = 1;
	xlo = max(xlo, (1+r*r+2*r-1)/(2*r));
	ll xhi = b;
	xhi = min(xhi, r);
	xhi = min(xhi, (c+r*r)/(2*r));
	return max(0ll, xhi-xlo+1);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> b >> c;
	
	ll z = 0;
	for (ll i=1; i<=b; i++) {
		z += min(c, i*i);
	}
	z *= 2;

	for (ll r=1; r<=5'000'000ll; r++) {
		ll f = fmy(r) + fpy(r);
		z -= f ? f-1 : 0;
	}

	cout << z << '\n';
}
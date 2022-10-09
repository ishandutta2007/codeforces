#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll a, b;
	cin >> a >> b;
	ll n = a+b, sol = 0;
	for (ll k=1; k<n; k=n/(n/(k+1))) {
		ll plo = n/(k+1)+1;
		ll phi = n/k;
		ll xlo = (a+k)/(k+1), xhi = a/k;
		ll ylo = (b+k)/(k+1), yhi = b/k;
		ll lo = max(xlo+ylo, plo);
		ll hi = min(xhi+yhi, phi);
		if (lo <= hi && xlo <= xhi && ylo <= yhi)
			sol += hi-lo+1;
	}
	cout << sol << '\n';
}
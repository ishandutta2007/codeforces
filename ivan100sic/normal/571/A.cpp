#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll g(ll a, ll b, ll c, ll l) {
	ll z = 0;
	for (ll i=0; i<=l; i++) {
		// b+x+c+y <= a+i   <=> b+c+(x+y) <= a+i  <=>
		//    x+y <= a+i-b-c
		// x+y <= l-i
		ll ub = min(l-i, a+i-b-c);
		if (ub < 0)
			continue;
		z += (ub+1) * (ub+2) / 2;
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int a, b, c, l;
	cin >> a >> b >> c >> l;
	ll sol = (l+1ll)*(l+2)*(l+3) / 6;

	sol -= g(a, b, c, l);
	sol -= g(b, c, a, l);
	sol -= g(c, a, b, l);

	cout << sol << '\n';
}
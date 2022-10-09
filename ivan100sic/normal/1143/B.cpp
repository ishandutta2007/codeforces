#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll pd(ll x) {
	ll p = 1;
	while (x > 0) {
		p *= x % 10;
		x /= 10;
	}
	return p;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n;
	cin >> n;
	ll s = 0;
	for (ll r=1; r<=1e12; r*=10) {
		s = max(s, pd(n));
		n = n/r*r;
		n--;
	}
	cout << s << '\n';
}
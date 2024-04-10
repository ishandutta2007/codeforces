#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll t, n, a, b, k;

bool moze(ll x) {
	ll aa = min(a, x);
	ll bb = min(b, x);

	ll c = n/2*(aa+bb) + n%2*aa;
	return x*k <= c;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> t >> n >> a >> b >> k;

	if (k > n) {
		cout << "0\n";
		return 0;
	}

	ll l = 1, r = t, o = 0;
	while (l <= r) {
		ll m = (l+r) >> 1;
		if (moze(m)) {
			o = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}
	cout << o << '\n';
}
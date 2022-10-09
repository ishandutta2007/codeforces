#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll pw10[18];

ll sumblocks(ll x) {
	ll z = 0;
	for (int i=1; i<18; i++) {
		ll lo = pw10[i-1];
		ll hi = pw10[i] - 1;
		if (hi <= x) {
			/*
			lo se javlja u lo, lo+1, ... x
			lo+1 se javlja u lo+1, ... x
			hi se javlja u hi, hi+1, ... x
			*/
			z += -(1+hi-lo)*(hi+lo-2*(1+x))/2*i;
		} else if (lo <= x) {
			z += (lo-x-2)*(lo-x-1)/2*i;
		}
	}
	return z;
}

ll sumone(ll x) {
	ll z = 0;
	for (int i=1; i<18; i++) {
		ll lo = pw10[i-1];
		ll hi = pw10[i] - 1;
		if (hi <= x) {
			z += (1+hi-lo) * i;
		} else if (lo <= x) {
			z += (1-lo+x) * i;
		}
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	pw10[0] = 1;
	for (int i=1; i<18; i++)
		pw10[i] = pw10[i-1] * 10;

	// cerr << sumone(100) << '\n';

	int q;
	cin >> q;
	while (q--) {
		ll k;
		cin >> k;
		k--;

		ll bl = 0;

		{
			ll l=0, r = 1.5e9, o = -1;
			while (l <= r) {
				ll m = (l+r) >> 1;
				if (sumblocks(m) <= k) {
					o = m;
					l = m + 1;
				} else {
					r = m - 1;
				}
			}
			k -= sumblocks(o);
			bl = o+1;
		}

		// cerr << "trazi " << k << ' ' << bl << '\n';

		ll num = 0;

		{
			ll l = 0, r = bl, o = -1;
			while (l <= r) {
				ll m = (l+r) >> 1;
				if (sumone(m) <= k) {
					o = m;
					l = m + 1;
				} else {
					r = m - 1;
				}
			}
			k -= sumone(o);
			num = o+1;
		}

		// cerr << "trazi " << k << ' ' << num << '\n';

		cout << to_string(num)[k] << '\n';
	}
}
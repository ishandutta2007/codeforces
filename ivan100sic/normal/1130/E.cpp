#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<ll> a;

ll greedy() {
	ll res = 0, cur = 0, k = -1;
	for (int i=0; i<n; i++) {
		cur += a[i];
		if (cur < 0) {
			cur = 0;
			k = i;
		}
		res = max(res, (i-k) * cur);
	}
	return res;
}

ll full() {
	ll res = 0;
	for (int i=0; i<n; i++) {
		ll cur = 0;
		for (int j=i; j<n; j++) {
			cur += a[j];
			res = max(res, (j-i+1) * cur);
		}
	}
	return res;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll x;
	cin >> x;
	
	for (ll k=1; k<=999; k++) {
		ll lo = (k + 2*k*k + x + 2*k-1) / (2*k);
		ll hi = (3*k*k + 6*k*k*k + 3*k*x) / (6*k*k - 2*k - 1);
		for (ll a=lo; a<=hi; a++) {
			if (a > 999999)
				break;
			ll p = a + k + 2*k*k + x;
			if (p % (2*k+1))
				continue;
			ll d = p / (2*k+1);

			cerr << a << ' ' << d << ' ' << k << '\n';

			{
				::a += a;
				::a += -1-a;
				for (int i=0; i<k-1; i++)
					::a += {a, -1-a};
				::a += d;
				n = ::a.size();

				cout << n << '\n';
				for (ll x : ::a)
					cout << x << ' ';
				cout << '\n';

				// cerr << greedy() << '\n';
				// cerr << full() << '\n';
				return 0;
			}
		}
	}

				
}
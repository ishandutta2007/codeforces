#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

basic_string<ll> td(ll n) {
	basic_string<ll> a;
	for (ll x=1; x*x<=n; x++) {
		if (n % x == 0) {
			a += x;
			if (x*x != n)
				a += n / x;
		}
	}
	sort(a.begin(), a.end());
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		int k;
		cin >> k;
		basic_string<ll> a;
		for (int i=0; i<k; i++) {
			ll x;
			cin >> x;
			a += x;
		}
		sort(a.begin(), a.end());
		ll val = -1;
		for (int i=0, j=k-1; i<k; i++, j--) {
			ll z = a[i] * a[j];
			if (val == -1) {
				val = z;
			} else if (val != z) {
				val = 0;
			}
		}

		if (val != 0) {
			basic_string<ll> ch = td(val);

			// cerr << "proveravamo " << val << '\n';
			// for (ll x : ch)
			// 	cerr << x << ' ';
			// cerr << '\n';

			basic_string<ll> ch2 = {1};
			ch2 += a;
			ch2 += val;

			// for (ll x : ch2)
			// 	cerr << x << ' ';
			// cerr << '\n';

			if (ch == ch2) {
				cout << val << '\n';
			} else {
				cout << "-1\n";
			}
		} else {
			cout << "-1\n";
		}
	}
}
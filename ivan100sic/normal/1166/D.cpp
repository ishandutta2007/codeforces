#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int moze(ll s, ll a, ll b, ll m, int k) {
	ll lo = a, hi = a;
	while (k--) {
		lo = lo == a ? a+s+1 : 2*lo;
		hi = hi == a ? a+s+m : 2*hi;
		if (lo > b)
			return 1;
	}
	if (lo > b)
		return 1;
	if (hi < b)
		return -1;
	return 0;
}

basic_string<ll> nadji_put(ll a, ll b, ll m, int k) {
	basic_string<ll> w = {a};
	ll s = a;
	while (k > 0) {
		ll lo = 1, hi = m;
		int ok = 0;
		while (lo <= hi) {
			ll mid = (lo + hi) >> 1;
			int rez = moze(s, s+mid, b, m, k-1);
			// cerr << s << ' ' << s+mid << ' ' << b << ' ' << m << ' ' << k-1;
			// cerr << " -> " << rez << '\n';
			if (rez == 1) {
				hi = mid - 1;
			} else if (rez == -1) {
				lo = mid + 1;
			} else {
				w += s + mid;
				s += s + mid;
				k--;
				ok = 1;
				break;
			}
		}
		if (!ok) {
			cerr << "fuck!\n";
			for (ll x : w)
				cerr << x << ' ';
			cerr << '\n';
			cerr << "s: " << s << '\n';
			cerr << "called with: ";
			cerr << a << ' ' << b << ' ' << m << ' ' << k << '\n';
			return {};
		}
	}
	return w;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		ll a, b, m;
		cin >> a >> b >> m;
		int ok = 0;
		for (int k=0; k<50; k++) {
			if (moze(0, a, b, m, k) == 0) {
				ok = 1;
				auto w = nadji_put(a, b, m, k);
				cout << w.size() << '\n';
				for (ll x : w)
					cout << x << ' ';
				cout << '\n';
				break;
			}		
		}
		if (!ok) {
			cout << "-1\n";
		}
	}
}
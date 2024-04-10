#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll n, k;
ll f[14];

basic_string<int> lex_perm(ll n, ll k) { // n <= 13, garantujem da postoji
	set<int> s;
	for (int i=1; i<=n; i++)
		s.insert(i);

	basic_string<int> v;
	for (int i=1; i<=n; i++) {
		ll x = k / f[n-i];
		auto it = s.begin();
		for (int _i=0; _i<x; _i++) ++it;
		v += *it;
		s.erase(it);
		k -= x * f[n-i];
	}

	return v;
}

bool laki(int x) {
	while (x) {
		int y = x % 10;
		if (y != 4 && y != 7)
			return false;
		x /= 10;
	}
	return true;
}

int svi(ll ub) {
	ll z = 0;
	for (int i=1; i<=12; i++) {
		for (int mask=0; mask<(1<<i); mask++) {
			ll x = 0;
			for (int j=0; j<i; j++)
				if (mask & (1 << j))
					x = 10*x + 4;
				else
					x = 10*x + 7;
			if (x <= ub)
				z++;
		}
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	f[0] = 1;
	for (int i=1; i<14; i++)
		f[i] = f[i-1] * i;

	cin >> n >> k;

	if (n <= 13 && k > f[n])
		return cout << -1, 0;

	if (n <= 13) {
		// "brut"
		int z = 0;
		auto v = lex_perm(n, k-1);
		for (int i=0; i<n; i++) {
			if (laki(i+1) && laki(v[i]))
				z++;
		}
		cout << z;
	} else {
		auto v = lex_perm(13, k-1);
		int z = 0;
		for (int i=0; i<13; i++)
			if (laki(n-12+i) && laki(v[i] + n - 13))
				z++;
		cerr << "pre " << z << '\n';
		z += svi(n-13);
		cout << z;
	}
}
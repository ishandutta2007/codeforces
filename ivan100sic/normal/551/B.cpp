#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<char, ll> ka, kb, kc;
string sa, sb, sc;

map<char, ll> ucitaj(string& s) {
	map<char, ll> m;
	cin >> s;
	for (char x : s)
		m[x]++;
	return m;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ka = ucitaj(sa);
	kb = ucitaj(sb);
	kc = ucitaj(sc);

	ll ib = 0, jb = 0;

	for (ll i=0; i<=100000; i++) {
		auto a = ka;
		ll ok = 1;
		for (auto [x, y] : kb) {
			a[x] -= i*y;
			if (a[x] < 0)
				ok = 0;
		}

		if (!ok)
			continue;

		ll j = 123123123123123123ll;

		for (auto [x, y] : kc) {
			j = min(j, a[x] / y);
		}

		if (i + j >= ib + jb) {
			ib = i;
			jb = j;
		}
	}

	string sol;

	while (ib--) {
		for (auto [x, y] : kb) {
			while (y--) {
				ka[x]--;
			}
		}
		sol += sb;
	}

	while (jb--) {
		for (auto [x, y] : kc) {
			while (y--) {
				ka[x]--;
			}
		}
		sol += sc;
	}

	cout << sol;

	for (auto [x, y] : ka) {
		while (y--) {
			cout << x;
		}
	}

	cout << '\n';
}
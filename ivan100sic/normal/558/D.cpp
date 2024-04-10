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

	ll h, q;
	cin >> h >> q;
	ll l = 1ll << (h-1);

	// ne mogu da verujem koliko ste bezobrazni
	if (q == 0) {
		if (h == 1) {
			cout << "1\n";
		} else {
			cout << "Data not sufficient!\n";
		}
		return 0;
	}
	
	map<ll, ll> b;

	b[l-1] = 0;
	b[l] = 0;
	b[2*l] = 0;

	for (ll qq=0; qq<q; qq++) {
		ll x, y, i, t;
		cin >> i >> x >> y >> t;
		while (i++ < h)
			x = 2*x, y = 2*y+1;
		if (t == 1)
			b[x]++, b[y+1]--;
		else
			b[l]++, b[2*l]--, b[x]--, b[y+1]++;
	}

	ll z = 0;
	for (auto& [x, y] : b)
		y = z += y;

	ll mult = 0, p = -1;
	for (auto it = b.begin(); it != b.end(); ++it) {
		if (it->second == q) {
			p = it->first;
			mult += next(it)->first - it->first;
		}
	}

	if (mult > 1) {
		cout << "Data not sufficient!\n";
	} else if (mult == 0) {
		cout << "Game cheated!\n";
	} else {
		cout << p << '\n';
	}
}
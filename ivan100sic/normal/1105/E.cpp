#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

map<string, int> mp;

int id(string s) {
	if (mp.count(s))
		return mp[s];
	int x = mp.size();
	mp[s] = x;
	return x;
}

int sos[1 << 20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m, h;
	bitset<64> g[64];

	cin >> n >> m;
	set<int> s;
	while (n--) {
		int x;
		cin >> x;
		if (x == 1) {
			s.clear();
		} else {
			string p;
			cin >> p;
			int j = id(p);
			for (int i : s)
				g[j][i] = g[i][j] = 1;
			s.insert(j);
		}
	}

	for (int i=0; i<m; i++)
		g[i][i] = 1;

	// max independent set
	h = m / 2;
	bitset<64> lower, upper;
	for (int i=0; i<m; i++) {
		if (i < h) {
			lower[i] = 1;
		} else {
			upper[i] = 1;
		}
	}

	for (int mask=0; mask<(1<<h); mask++) {
		bitset<64> unija;
		int ok = 1;
		for (int i=0; i<h; i++)
			if (mask & (1 << i)) {
				if (unija[i]) {
					ok = 0;
					break;
				} else {
					unija |= g[i];
				}
			}
		if (ok) {
			sos[mask] = __builtin_popcount(mask);
		}
	}

	for (int i=0; i<h; i++) {
		for (int j=0; j<(1<<h); j++) {
			if (j & (1 << i)) {
				sos[j] = max(sos[j], sos[j - (1 << i)]);
			}
		}
	}

	int sol = 0, lmask = (1 << h) - 1;

	for (int mask=0; mask<(1<<(m-h)); mask++) {
		bitset<64> unija;
		int ok = 1;
		for (int i=0; i<m-h; i++)
			if (mask & (1 << i)) {
				if (unija[h+i]) {
					ok = 0;
					break;
				} else {
					unija |= g[h+i];
				}
			}
		
		if (ok) {
			int resto = lmask ^ (unija.to_ullong() & lmask);
			sol = max(sol, sos[resto] + __builtin_popcount(mask));
		}
	}

	cout << sol << '\n';
}
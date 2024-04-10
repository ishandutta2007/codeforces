// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct iset {
	vector<int> s;

	void operator^= (const iset& b) {
		vector<int> t;
		set_symmetric_difference(begin(s), end(s), begin(b.s), end(b.s), back_inserter(t));
		swap(s, t);
	}
};

struct gaus {
	ll g[61];
	iset s[61];

	gaus() {
		memset(g, 0, sizeof g);
	}

	void dod(ll x, int id, const vector<int>& bo) {
		iset sx = {{id}};
		for (int i : bo) {
			if (x & (1ll << i)) {
				if (g[i]) {
					x ^= g[i];
					sx ^= s[i];
				} else {
					g[i] = x;
					s[i] = sx;
					return;
				}
			}
		}
	}

	ll elim(ll x, const vector<int>& bo) {
		for (int i : bo) {
			if (x & (1ll << i)) {
				if (g[i]) {
					x ^= g[i];
				}
			}
		}
		return x;
	}

	iset elim_s(ll x, const vector<int>& bo) {
		iset is;
		for (int i : bo) {
			if (x & (1ll << i)) {
				if (g[i]) {
					x ^= g[i];
					is ^= s[i];
				}
			}
		}

		return is;
	}
};

int n;
ll a[100005];
int sol[100005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	gaus g;

	ll totx = 0, extra = 0;

	for (int i=0; i<n; i++) {
		cin >> a[i];
		totx ^= a[i];
	}

	vector<int> bitord;
	for (int i=60; i>=0; i--) {
		if (!(totx & (1ll << i))) {
			bitord.push_back(i);
		}
	}
	for (int i=60; i>=0; i--) {
		if (totx & (1ll << i)) {
			bitord.push_back(i);
		}
	}

	for (int i=0; i<n; i++) {
		g.dod(a[i], i, bitord);
	}

	ll sve = (1ll << 61) - 1;

	for (int b : bitord) {
		ll m = 1ll << b;
		sve -= m;
		ll eok = extra ^ m;
		ll ebad = extra;

		if (m & totx) {
			swap(eok, ebad);
		}

		ll e = g.elim(eok, bitord);
		if ((e & sve) == e) {
			// ok
			extra = eok;
		} else {
			extra = ebad;
		}
	}

	auto sols = g.elim_s(extra, bitord);

	cerr << "totx = " << totx << '\n';
	cerr << "extra = " << extra << '\n';

	bool f = extra < (totx ^ extra);

	fill(sol, sol+n, f ? 2 : 1);

	for (int i : sols.s) {
		sol[i] = f ? 1 : 2;
	}

	for (int i=0; i<n; i++) {
		cout << sol[i] << " \n"[i == n-1];
	}
}
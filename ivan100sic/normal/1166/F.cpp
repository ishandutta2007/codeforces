#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

set<int> rainbow_adjs[100005];

// labela x se menja u y
void cb(int x, int y) {
	for (int t : rainbow_adjs[x])
		rainbow_adjs[y].insert(t);
	rainbow_adjs[x].clear();
}

struct dsu {
	vector<int> p, s;

	dsu(int n = 0) : p(n), s(n) {
		iota(p.begin(), p.end(), 0);
		fill(s.begin(), s.end(), 1);
	}

	int e(int x) {
		while (x != p[x])
			x = p[x];
		return x;
	}

	void spoji(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return;
		if (s[x] > s[y]) {
			swap(x, y);
		}
		cb(x, y);
		p[x] = y;
		s[y] += s[x];
	}
} eng;

map<pair<int, int>, int> nbh; // nbh(x, c) je jedan cvor iz 
// c-obojene okoline cvora x

void dodaj_granu(int x, int y, int c) {
	auto& rx = nbh[{x, c}];
	if (rx) {
		eng.spoji(y, rx);
	} else {
		rx = y;
	}

	auto& ry = nbh[{y, c}];
	if (ry) {
		eng.spoji(x, ry);
	} else {
		ry = x;
	}

	int xroot = eng.e(x);
	int yroot = eng.e(y);
	rainbow_adjs[xroot].insert(y);
	rainbow_adjs[yroot].insert(x);
}

void resi(int x, int y) {
	int xroot = eng.e(x);
	int yroot = eng.e(y);
	if (xroot == yroot || rainbow_adjs[xroot].count(y)) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, m, c, q;
	cin >> n >> m >> c >> q;
	eng = dsu(n+1);
	while (m--) {
		int x, y, z;
		cin >> x >> y >> z;
		dodaj_granu(x, y, z);
	}
	while (q--) {
		char t;
		cin >> t;
		if (t == '?') {
			int x, y;
			cin >> x >> y;
			resi(x, y);
		} else {
			int x, y, z;
			cin >> x >> y >> z;
			dodaj_granu(x, y, z);
		}
	}
}
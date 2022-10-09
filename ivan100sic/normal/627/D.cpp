#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct opis {
	bool k;
	int v;
};

int n, k;
int a[200005];
basic_string<int> e[200005];
bool ok[200005];
opis dole[200005], gore[200005];

void dfs1(int x, int p) {
	int mw = 0, tw = 0;
	bool k = true;

	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs1(y, x);
		if (dole[y].k) {
			tw += dole[y].v;
		} else {
			k = false;
			mw = max(mw, dole[y].v);
		}
	}

	if (!ok[x]) {
		dole[x] = {false, 0};
	} else {
		dole[x] = {k, mw + tw + 1};
	}
}

void dfs2(int x, int p) {
	int m1 = -1, m2 = -1, i1 = -1, i2 = -1;
	int tw = 0, bn = 0;

	auto dodaj = [&](opis o, int y) {
		if (o.k) {
			tw += o.v;
		} else {
			bn++;
			if (o.v > m1) {
				i2 = i1;
				m2 = m1;
				m1 = o.v;
				i1 = y;
			} else if (o.v > m2) {
				m2 = o.v;
				i2 = y;
			}
		}
	};

	for (int y : e[x]) {
		if (y == p)
			continue;
		dodaj(dole[y], y);
	}

	if (x != p)
		dodaj(gore[x], x);

	for (int y : e[x]) {
		if (y == p)
			continue;
		if (bn == 0) {
			gore[y] = {true, tw - dole[y].v};
		} else if (bn == 1) {
			if (y == i1) {
				gore[y] = {true, tw};
			} else {
				gore[y] = {false, tw - dole[y].v + m1};
			}
		} else {
			if (y == i1) {
				gore[y] = {false, tw + m2};
			} else if (dole[y].k) {
				gore[y] = {false, tw - dole[y].v + m1};
			} else {
				gore[y] = {false, tw + m1};
			}
		}

		if (!ok[x]) {
			gore[y] = {false, 0};
		} else {
			gore[y].v++;
		}
	}

	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs2(y, x);
	}
}

void dfs3(int x, int p, bool& naso) {
	int mw = 0, tw = 0;

	for (int y : e[x]) {
		if (y == p)
			continue;
		if (dole[y].k) {
			tw += dole[y].v;
		} else {
			mw = max(mw, dole[y].v);
		}
	}

	if (gore[x].k) {
		tw += gore[x].v;
	} else {
		mw = max(mw, gore[x].v);
	}

	tw += mw + 1;
	if (!ok[x])
		tw = 0;

	if (tw >= k)
		naso = true;

	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs3(y, x, naso);
	}
}

bool moze(int m) {
	for (int i=1; i<=n; i++)
		ok[i] = a[i] >= m;
	dfs1(1, 1);

	// for (int i=1; i<=n; i++) {
	// 	cerr << "1nfo " << i << ' ' << dole[i].k << ' ' << dole[i].v << '\n';
	// }

	dfs2(1, 1);
	bool u = false;
	dfs3(1, 1, u);
	return u;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	// return moze(3);

	int l = 0, r = 1e6, o = -1;
	while (l <= r) {
		int m = (l+r) >> 1;
		if (moze(m)) {
			o = m;
			l = m + 1;
		} else {
			r = m - 1;
		}
	}
	cout << o << '\n';
}
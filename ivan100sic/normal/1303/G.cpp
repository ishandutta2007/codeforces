#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct line {
	ll k, b;

	line(ll k=0, ll b=-1e18) : k(k), b(b) {}

	ll operator* (ll x) const {
		return k*x + b;
	}
};

struct lichao {
	vector<line> a;
	int maxn;

	lichao(int n) {
		maxn = 1;
		while (maxn < n)
			maxn <<= 1;
		a.resize(2*maxn);
	}

	void add(line p, int x, int xl, int xr) {
		if (a[x]*xl >= p*xl && a[x]*xr >= p*xr)
			return;
		if (a[x]*xl <= p*xl && a[x]*xr <= p*xr) {
			a[x] = p;
			return;
		}

		int xm = (xl+xr) >> 1;
		if (p*xl < a[x]*xl)
			swap(a[x], p);

		add(p, 2*x, xl, xm);
		add(p, 2*x+1, xm+1, xr);
	}

	ll get(int p) {
		ll z = -1e18;
		for (int x=p+maxn; x; x>>=1)
			z = max(z, a[x] * p);
		return z;
	}

	void add(line p) {
		add(p, 1, 0, maxn-1);
	}
};

int n;
basic_string<int> e[150005];
int sz[150005], blok[150005], w[150005];

void dfs1(int x, int p) {
	sz[x] = 1;
	for (int y : e[x]) {
		if (blok[y] || y == p)
			continue;
		dfs1(y, x);
		sz[x] += sz[y];
	}
}

void dfs2(int x, int p, int sve, int& r) {
	int ok = 1;
	for (int y : e[x]) {
		if (y == p || blok[y])
			continue;
		dfs2(y, x, sve, r);
		if (sz[y] * 2 > sve)
			ok = 0;
	}
	if ((sve - sz[x]) * 2 > sve)
		ok = 0;
	if (ok)
		r = x;
}

struct trojka {
	ll a, b, c;
};

void dfs3(int x, int par, ll a, ll b, ll c, ll p, ll q, ll r, vector<trojka>& vd, vector<trojka>& vu) {
	vd.push_back({a, b, c});
	vu.push_back({p, q, r});
	for (int y : e[x]) {
		if (y == par || blok[y])
			continue;
		dfs3(y, x, a+1, b+w[y], c+b+w[y], p+1, q+w[y], r+w[y]*(p+1), vd, vu);
	}
}

ll sol = 0;

void resi(int x) {
	int r;
	dfs1(x, x);
	dfs2(x, x, sz[x], r);

	for (int _rep=0; _rep < 2; _rep++) {
		lichao drvo(sz[x] + 2);
		drvo.add({w[r], w[r]});
		for (int y : e[r]) {
			if (blok[y])
				continue;
			vector<trojka> vd, vu;
			dfs3(y, r,
				1, w[y], w[y],
				2, w[r] + w[y], 2*w[y] + w[r],
				vd, vu
			);

			for (auto [p, q, r] : vd)
				sol = max(sol, r + drvo.get(p));

			for (auto [a, b, c] : vu) {
				drvo.add({b, c});
				sol = max(sol, c);
			}
		}
		reverse(e[r].begin(), e[r].end());
	}

	blok[r] = 1;
	for (int y : e[r]) {
		if (blok[y])
			continue;
		resi(y);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	for (int i=1; i<=n; i++)
		cin >> w[i];

	resi(1);
	cout << sol << '\n';
}
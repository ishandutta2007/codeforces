#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int m>
struct modint {

	unsigned x;

	modint() : x(0) {}

	modint(long long arg) {
		arg %= m;
		if (arg < 0) {
			x = arg + m;
		} else {
			x = arg;
		}
	}	

	modint& operator+= (const modint& other) {
		x += other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint& operator*= (const modint& other) {
		x = (x * 1ull * other.x) % m;
		return *this;
	}

	modint& operator-= (const modint& other) {
		x += m - other.x;
		if (x >= m) {
			x -= m;
		}
		return *this;
	}

	modint operator+ (const modint& other) const {
		modint tmp = *this;
		tmp += other;
		return tmp;
	}

	modint operator- (const modint& other) const {
		modint tmp = *this;
		tmp -= other;
		return tmp;
	}

	modint operator* (const modint& other) const {
		modint tmp = *this;
		tmp *= other;
		return tmp;
	}

	explicit operator int () const {
		return x;
	}

	modint& operator++ () {
		++x;
		if (x == m) {
			x = 0;
		}
		return *this;
	}

	modint& operator-- () {
		if (x == 0) {
			x = m-1;
		} else {
			--x;
		}
		return *this;
	}

	modint operator++ (int) {
		modint tmp = *this;
		++*this;
		return tmp;
	}

	modint operator-- (int) {
		modint tmp = *this;
		--*this;
		return tmp;
	}

	bool operator== (const modint& other) const {
		return x == other.x;
	}

	bool operator!= (const modint& other) const {
		return x != other.x;
	}

	template<class T>
	modint operator^ (T arg) const {
		if (arg == 0) {
			return 1;
		}
		if (arg == 1) {
			return x;
		}
		auto t = *this ^ (arg >> 1);
		t *= t;
		if (arg & 1) {
			t *= *this;
		}
		return t;
	}

	template<class T>
	modint operator^= (T arg) {
		return *this = *this ^ arg;
	}

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 998244353;
typedef modint<MOD> mint;

mint invn;

struct seg {
	int l, r, sz;
};

int n, q;
basic_string<int> e[150005], f[150005];
basic_string<seg> g[150005];
int sz[150005], par[150005];

void dfs1(int x, int p) {
	par[x] = p;
	sz[x] = 1;
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs1(y, x);
		sz[x] += sz[y];
		f[x] += y;
	}
	sort(f[x].begin(), f[x].end(), [&](int u, int v) {
		return sz[u] < sz[v];
	});
	int l = 0;
	for (int i=0; i<(int)f[x].size(); i++) {
		if (sz[f[x][i]] != sz[f[x][l]]) {
			// dodaj
			g[x] += {l, i, sz[f[x][l]]};
			l = i;
		}
	}
	g[x] += {l, (int)f[x].size(), sz[f[x][l]]};
}

int el[150005], er[150005], et = 0;

void dfs2(int x) {
	el[x] = et++;
	for (int y : f[x])
		dfs2(y);
	er[x] = et;
}

const int BLOG = 9;
const int BS = 1 << BLOG;

struct rqds {
	vector<mint> bloksum;
	vector<mint> indsum;
	
	rqds() : bloksum(200005 >> BLOG), indsum(200005) {}

	void add(int x, mint y) {
		bloksum[x >> BLOG] += y;
		indsum[x] += y;
	}

	void add(int l, int r, mint y) {
		add(l, y);
		add(r, mint(0) - y);
	}

	mint query(int x) {
		mint z = 0;
		for (int i=0; i<(x>>BLOG); i++)
			z += bloksum[i];
		for (int i=x-(x & (BS-1)); i<x; i++)
			z += indsum[i];
		return z;
	}
} ds;

void mark(int v, int d) {
	// prvo sve povecaj
	ds.add(0, n, d);

	// dechishta
	for (auto [l, r, sz] : g[v]) {
		int a = f[v][l];
		int b = f[v][r-1];
		ds.add(el[a], er[b], invn*-sz*d);
	}

	// ovaj jadnik gore ako postoji
	if (v != 1) {
		mint dd = invn*(sz[v]-n)*d;
		ds.add(0, n, dd);
		ds.add(el[v], er[v], mint(0)-dd);
	}
}

void query(int v) {
	cout << (int)ds.query(el[v] + 1) << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	invn = mint(n).inv();

	dfs1(1, 1);
	dfs2(1);

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int v, d;
			cin >> v >> d;
			mark(v, d);
		} else {
			int v;
			cin >> v;
			query(v);
		}
	}

}
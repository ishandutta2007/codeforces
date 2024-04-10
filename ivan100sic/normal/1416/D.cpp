// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T = int, class F = plus<T>>
struct segtree {
	int maxn;
	vector<T> a;
	T e;
	F f;

	segtree(int n, T e = T(), F f = F(), T v = T()) : e(e), f(f) {
		maxn = 1;
		while (maxn < n)
			maxn <<= 1;
		a.assign(2*maxn, v);
		for (int i=maxn-1; i; i--)
			a[i] = f(a[2*i], a[2*i+1]);
	}

	void add(int p, const T& v) {
		p += maxn;
		a[p] = f(a[p], v);
		for (p >>= 1; p; p >>= 1)
			a[p] = f(a[2*p], a[2*p+1]);
	}

	void update(int p, const T& v) {
		p += maxn;
		a[p] = v;
		for (p >>= 1; p; p >>= 1)
			a[p] = f(a[2*p], a[2*p+1]);
	}

	T get(int l, int r, int x, int xl, int xr) const {
		if (r <= xl || xr <= l)
			return e;
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return f(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm, xr));
	}

	T operator() (int l, int r) const {
		return get(l, r, 1, 0, maxn);
	}
};

const int inf = 1e9;

struct qry {
	int t, x;
};

int n, m, q;
int p[500005];
int a[500005], b[500005], delt[500005];
qry upit[500005];

vector<int> g[500005];
bool vis[500005];
int par[500005][20];
int dl[500005], dr[500005], dt;
int indeg[500005];

void dfs(int x, int p) {
	dl[x] = dt++;
	par[x][0] = p;
	for (int i=1; i<20; i++) {
		par[x][i] = par[par[x][i-1]][i-1];
	}
	for (auto y : g[x]) {
		dfs(y, x);
	}
	dr[x] = dt;
}

// union-find
int up[500005];

int ep(int x) {
	if (x == up[x]) return x;
	return up[x] = ep(up[x]);
}

int seek(int x, int lim) {
	if (par[x][0] == x) {
		return x;
	}

	for (int i=19; i>=0; i--) {
		int y = par[x][i];
		if (delt[y-n] >= lim) {
			x = y;
		}
	}
	return x;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m >> q;
	for (int i=0; i<n; i++) {
		cin >> p[i];
	}

	for (int j=0; j<m; j++) {
		cin >> a[j] >> b[j];
		a[j]--, b[j]--;
		delt[j] = inf;
	}

	for (int i=0; i<q; i++) {
		int t, x;
		cin >> t >> x;
		x--;
		if (t == 2) {
			delt[x] = i;
		}
		upit[i] = {t, x};
	}

	vector<int> erev(m);
	iota(begin(erev), end(erev), 0);
	sort(begin(erev), end(erev), [&](int x, int y) {
		return delt[x] > delt[y];
	});

	iota(up, up+n+m, 0);
	for (int i : erev) {
		int x = a[i], y = b[i], z = n+i;
		x = ep(x);
		y = ep(y);
		if (x == y) {
			continue;
		}
		up[x] = up[y] = z;
		g[z].emplace_back(x);
		g[z].emplace_back(y);
		// cerr << z << " -> " << x << "\n";
		// cerr << z << " -> " << y << "\n";
		indeg[x]++;
		indeg[y]++;
	}


	for (int i=0; i<n+m; i++) {
		if (indeg[i] == 0) {
			// cerr << "dfs " << i << '\n';
			dfs(i, i);
		}
	}

	segtree st(n+m, pair(-1, -1), [](auto x, auto y) { return max(x, y); });
	for (int x=0; x<n; x++) {
		// cerr << x << ' ' << dl[x] << ' ' << dr[x] << '\n';
		st.update(dl[x], {p[x], dl[x]});
	}

	// cerr << "===\n";
	//
	// for (int i=n; i<n+m; i++) {
	// 	cerr << i << ' ' << dl[i] << ' ' << dr[i] << '\n';
	// }

	for (int i=0; i<q; i++) {
		auto [t, x] = upit[i];
		if (t == 1) {
			int y = seek(x, i);
			auto rez = st(dl[y], dr[y]);
			cout << rez.first << '\n';
			st.update(rez.second, {0, rez.second});
		}
	}
}
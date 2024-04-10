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
		x = (x * 1ll * other.x) % m;
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

	modint inv() const {
		return *this ^ (m-2);
	}
};

const int MOD = 1'000'000'007;
typedef modint<MOD> mint;


int n, q;
basic_string<int> e[100005];
mint dp[2][305];

namespace lca {
	const int MAX_LOG = 18;
	const int MAX_N = 100005;

	int p[MAX_LOG][MAX_N];
	int dub[MAX_N];
	int sz[MAX_N], l[MAX_N], r[MAX_N], lrt;
	int flat[2*MAX_N];

	void dfs(int x, int par) {
		p[0][x] = par;
		for (int i=1; i<MAX_LOG; i++) {
			p[i][x] = p[i-1][p[i-1][x]];
		}

		sz[x] = 1;
		l[x] = ++lrt;
		flat[lrt] = x;

		for (int y : e[x]) {
			if (y != par) {
				dub[y] = dub[x] + 1;
				dfs(y, x);
				sz[x] += sz[y];
			}
		}

		r[x] = ++lrt;
		flat[lrt] = x;
	}

	int dizi(int x, int v) {
		for (int i=0; i<MAX_LOG; i++) {
			if (v & (1 << i)) {
				x = p[i][x];
			}
		}
		return x;
	}

	bool ispod(int a, int b) {
		return l[b] < l[a] && r[a] < r[b];
	}

	int lca(int a, int b) {
		if (dub[a] > dub[b]) {
			a = dizi(a, dub[a] - dub[b]);
		}
		if (dub[b] > dub[a]) {
			b = dizi(b, dub[b] - dub[a]);
		}

		if (a == b) {
			return a;
		}

		for (int i=MAX_LOG-1; i>=0; i--) {
			int aa = p[i][a];
			int bb = p[i][b];

			if (aa != bb) {
				a = aa;
				b = bb;
			}
		}

		return p[0][a];
	}

	int dist(int a, int b) {
		int c = lca(a, b);
		return dub[a] + dub[b] - 2*dub[c];
	}

	bool kolinear(int a, int b, int c) {
		return dist(a, b) + dist(b, c) == dist(a, c);
	}

	int kth(int a, int b, int k) {
		int c = lca(a, b);
		if (k <= dub[a] - dub[c]) {
			return dizi(a, k);
		} else {
			return dizi(b, (dub[a] + dub[b] - 2*dub[c]) - k);
		}
	}
}

using namespace lca;

int root_node;

template<class T, int size>
struct fenwick {
	T a[size];

	/* precondition: pos > 0 */
	void add(int pos, const T& val) {
		while (pos < size) {
			a[pos] += val;
			pos += pos & -pos;
		}
	}

	T sum(int pos) {
		T ret = T();
		while (pos > 0) {
			ret += a[pos];
			pos -= pos & -pos;
		}
		return ret;
	}
};

fenwick<int, 200005> drvo;

int wdist(int x, int y) {
	int z = lca::lca(x, y);
	return drvo.sum(l[y]) + drvo.sum(l[x])
		- drvo.sum(l[z]) - drvo.sum(l[z]-1);
}

bool cmp(int x, int y) {
	return wdist(x, root_node) < wdist(y, root_node);
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

	dfs(1, 1);

	while (q--) {
		int k, m, rt;
		cin >> k >> m >> rt;
		root_node = rt;
		basic_string<pair<int, int>> b(k, {});
		for (int i=0; i<k; i++) {
			int x;
			cin >> x;
			b[i] = {0, x};
		}

		for (auto [w, x] : b) {
			drvo.add(l[x], +1);
			drvo.add(r[x], -1);
		}

		for (int i=0; i<k; i++)
			b[i].first = wdist(b[i].second, root_node) - 1;

		sort(b.begin(), b.end());

		// for (auto [w, x] : b)
		// 	cerr << w << ' ' << x << '\n';
		// cerr << '\n';

		auto dp_old = dp[0];
		auto dp_nu = dp[1];
		memset(dp, 0, sizeof(dp));
		dp_old[0] = 1;

		for (auto [w, x] : b) {
			memset(dp_nu, 0, sizeof(dp[0]));
			for (int i=1; i<=m; i++) {
				// nesto nesto
				mint& d = dp_nu[i];
				d = 0;
				// kreiram novu grupu?
				if (w < m && i-1-w >= 0) {
					d += dp_old[i-1];
				}
				// dodajem u neku postojecu
				if (w <= m) {
					d += dp_old[i] * (i-w);
				}
			}
			swap(dp_old, dp_nu);
		}

		cout << (int)accumulate(dp_old+1, dp_old+m+1, mint(0)) << '\n';

		for (auto [w, x] : b) {
			drvo.add(l[x], -1);
			drvo.add(r[x], +1);
		}
	}
}
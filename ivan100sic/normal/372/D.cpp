#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, k;
basic_string<int> e[100005];

namespace lcaa {
	const int MAX_LOG = 18;
	const int MAX_N = 100005;

	int p[MAX_LOG][MAX_N];
	int dub[MAX_N];
	int l[MAX_N], lrt;

	void dfs(int x, int par) {
		p[0][x] = par;
		for (int i=1; i<MAX_LOG; i++)
			p[i][x] = p[i-1][p[i-1][x]];

		l[x] = ++lrt;

		for (int y : e[x]) {
			if (y != par) {
				dub[y] = dub[x] + 1;
				dfs(y, x);
			}
		}
	}

	int dizi(int x, int v) {
		for (int i=0; i<MAX_LOG; i++) {
			if (v & (1 << i)) {
				x = p[i][x];
			}
		}
		return x;
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
}

using namespace lcaa;

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		bool prazno;
		int l, r, sz;

		/* CONSTRUCTOR */
		node_t(int x) : prazno(false), l(x), r(x), sz(dub[x]) {}

		node_t() : prazno(true) {}

		node_t& operator+= (const node_t& other) {
			if (prazno)
				return *this = other;
			if (other.prazno)
				return *this;

			sz += other.sz - dub[lca(r, other.l)];
			r = other.r;

			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	node_t a[2*MAXN];

	segtree() {
		for (int i=1; i<=MAXN; i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			a[i + MAXN - 1] = node_t();
		}
		for (int i=MAXN-1; i>0; i--) {
			a[i] = a[2*i] + a[2*i+1];
		}
	}

	node_t get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		if (r < nl || nr < l) {
			return node_t();
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		return get(l, r, 2*node, nl, nm) + get(l, r, 2*node+1, nm+1, nr);
	}

	void set(int pos, node_t val) {
		pos += MAXN-1;
		a[pos] = val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}
};

segtree<131072> drvo;

int vel() {
	auto nd = drvo.a[1];
	if (nd.prazno)
		return 0;
	return nd.sz - dub[lca(nd.l, nd.r)] + 1;
}

void dodaj(int x) {
	drvo.set(l[x], x);
}

void skini(int x) {
	drvo.set(l[x], {});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	dfs(1, 1);

	int sol = 1;

	for (int l=1, r=0; r<n; l++) {
		while (r < n && vel() <= k) {
			dodaj(++r);
			// cerr << "[" << l << ", " << r << "] " << vel() << '\n';
		}
		if (vel() > k)
			skini(r--);
		sol = max(sol, r-l+1);
		skini(l);
	}

	cout << sol << '\n';
}
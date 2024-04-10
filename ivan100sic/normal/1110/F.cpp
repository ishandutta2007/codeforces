#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int MAXN>
struct segtree_lazy {

	struct updater {
		/* DATA MEMBERS */
		ll x;

		updater(ll x = 0) : x(x) {}

		updater& operator+= (const updater& other) {
			/* ADDITION */
			x += other.x;

			return *this;
		}

		operator bool () const {
			/* BOOL CAST */
			return x != 0;
		}
	};
	
	struct node_t {
		/* DATA MEMBERS */
		ll x;

		/* CONSTRUCTOR */
		node_t(ll x = 0) : x(x) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			x = min(x, other.x);
			return *this;
		}

		node_t& operator+= (const updater& other) {
			/* UPDATE ADDITION */
			x += other.x;
			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	node_t a[2*MAXN];
	updater b[2*MAXN];

	void init() {
		for (int i=1; i<=MAXN; i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			a[i + MAXN - 1] = node_t();
		}
		for (int i=MAXN-1; i>0; i--) {
			a[i] = a[2*i] + a[2*i+1];
		}
	}

	void push(int i) {
		if (b[i]) {
			a[i] += b[i];
			if (i < MAXN) {
				b[2*i] += b[i];
				b[2*i+1] += b[i];
			}
			b[i] = updater();
		}
	}

	node_t get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
		push(node);

		if (r < nl || nr < l) {
			return node_t(1e18);
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		return get(l, r, 2*node, nl, nm) + get(l, r, 2*node+1, nm+1, nr);
	}

	void update(int l, int r, updater val, int node=1, int nl=1, int nr=MAXN) {
		push(node);

		if (r < nl || nr < l) {
			return;
		}
		if (l <= nl && nr <= r) {
			b[node] += val;
			push(node);
			return;
		}

		int nm = (nl + nr) >> 1;
		update(l, r, val, 2*node, nl, nm);
		update(l, r, val, 2*node+1, nm+1, nr);
		a[node] = a[2*node] + a[2*node+1];
	}
};

struct dete {int x, w; };
struct upit {int l, r, id; };

segtree_lazy<524288> drvo;

basic_string<dete> e[500005];
basic_string<upit> u[500005];
int n, q;
ll d[500005], ans[500005];
int r[500005];

void dfs1(int x) {
	r[x] = x;
	for (auto [y, w] : e[x]) {
		d[y] = d[x] + w;
		dfs1(y);
		r[x] = max(r[x], r[y]);
	}
}

void dfs2(int x) {
	for (auto [l, r, id] : u[x])
		ans[id] = drvo.get(l, r).x + d[x];

	for (auto [y, w] : e[x]) {
		drvo.update(y, r[y], -2*w);
		dfs2(y);
		drvo.update(y, r[y], 2*w);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=2; i<=n; i++) {
		int p, w;
		cin >> p >> w;
		e[p] += dete{i, w};
	}

	for (int i=0; i<q; i++) {
		int x, l, r;
		cin >> x >> l >> r;
		u[x] += upit{l, r, i};
	}

	dfs1(1);

	for (int i=1; i<=n; i++) {
		if (e[i].size())
			drvo.update(i, i, 1e18);
		else
			drvo.update(i, i, d[i]);
	}

	dfs2(1);
	for (int i=0; i<q; i++)
		cout << ans[i] << '\n';
}
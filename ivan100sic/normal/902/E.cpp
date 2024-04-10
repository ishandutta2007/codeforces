#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[300005], ee[300005];
bool v[300005], inst[300005];
int p[300005], rr[300005];

void mx(int& x, int y) {
	x = max(x, y);
}

void mn(int& x, int y) {
	x = min(x, y);
}

void dfs(int x) {
	v[x] = 1;
	inst[x] = 1;
	for (int y : e[x]) {
		if (!v[y]) {
			p[y] = x;
			dfs(y);
		} else if (inst[y] && y != p[x]) {
			// b-e
			int lo = y, hi = y;
			for (int i=x; i!=y; i=p[i])
				mn(lo, i), mx(hi, i);
			mx(rr[hi], lo);
		}
	}
	inst[x] = 0;
}

template<int MAXN>
struct segtree_lazy {

	struct updater {
		/* DATA MEMBERS */
		int x;

		updater(int x = 0) : x(x) {}

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
		ll x, len;

		/* CONSTRUCTOR */
		node_t() : x(0), len(0) {}

		node_t(int x) : x(x), len(1) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			x += other.x;
			len += other.len;

			return *this;
		}

		node_t& operator+= (const updater& other) {
			/* UPDATE ADDITION */
			x += other.x * len;

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

	segtree_lazy() {
		for (int i=1; i<=MAXN; i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			a[i + MAXN - 1] = node_t(0);
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
			return node_t();
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

segtree_lazy<524288> drvo;

int q;
ll ans[300005];
int ql[3000005], qr[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	for (int i=1; i<=n; i++) {
		if (!v[i]) {
			p[i] = i;
			dfs(i);
		}
	}

	for (int i=1; i<=n; i++)
		rr[i] = max(rr[i], rr[i-1]);

	cin >> q;
	for (int i=0; i<q; i++) {
		cin >> ql[i] >> qr[i];
		ee[qr[i]] += i;
	}

	for (int i=1; i<=n; i++) {
		drvo.update(rr[i]+1, i, 1);
		for (int j : ee[i])
			ans[j] = drvo.get(ql[j], i).x;
	}

	for (int i=0; i<q; i++)
		cout << ans[i] << '\n';
}
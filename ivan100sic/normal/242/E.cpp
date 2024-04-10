#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
template<int MAXN>
struct segtree_lazy {

	struct updater {
		/* DATA MEMBERS */
		int x;

		updater(int x = 0) : x(x) {}

		updater& operator+= (const updater& other) {
			/* ADDITION */
			x ^= other.x;

			return *this;
		}

		operator bool () const {
			/* BOOL CAST */
			return x != 0;
		}
	};
	
	struct node_t {
		/* DATA MEMBERS */
		array<int, 20> a;
		int len;

		node_t() {
			len = 0;
			fill(a.begin(), a.end(), 0);
		}

		/* CONSTRUCTOR */
		node_t(int x) {
			len = 1;
			for (int i=0; i<20; i++)
				a[i] = !!(x & (1 << i));
		}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			len += other.len;
			for (int i=0; i<20; i++)
				a[i] += other.a[i];
			return *this;
		}

		node_t& operator+= (const updater& other) {
			/* UPDATE ADDITION */
			for (int i=0; i<20; i++)
				if (other.x & (1 << i))
					a[i] = len - a[i];
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
		for (int i=1; i<=MAXN; i++)
			a[i + MAXN - 1] = node_t(0);
		for (int i=MAXN-1; i>1; i--)
			a[i] = a[2*i] + a[2*i+1];
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

segtree_lazy<131072> drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n;
	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		drvo.update(i, i, x);
	}
	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r;
			cin >> l >> r;
			auto g = drvo.get(l, r);
			ll sol = 0;
			for (int i=0; i<20; i++)
				sol += (ll)g.a[i] << i;
			cout << sol << '\n';
		} else {
			int l, r, v;
			cin >> l >> r >> v;
			drvo.update(l, r, v);
		}
	}
}
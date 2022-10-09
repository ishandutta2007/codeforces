#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
int a0[100005];

template<int MAXN>
struct segtree_lazy {

	struct updater {
		/* DATA MEMBERS */
		int v[10];
		bool dirty;

		updater() {
			iota(v, v+10, 0);
			dirty = false;
		}

		updater& operator+= (const updater& other) {
			/* ADDITION */
			int t[10];
			for (int i=0; i<=9; i++) {
				t[i] = other.v[v[i]];
			}
			for (int i=0; i<=9; i++) {
				v[i] = t[i];
			}
			dirty |= other.dirty;
			return *this;
		}

		operator bool () const {
			/* BOOL CAST */
			return dirty;
		}
	};
	
	struct node_t {
		/* DATA MEMBERS */
		ll v[10];

		/* CONSTRUCTOR */
		node_t() {
			for (int i=0; i<=9; i++) {
				v[i] = 0;
			}
		}

		node_t(int x) {
			for (int i=0; i<=9; i++) {
				v[i] = 0;
			}

			for (int pw=1; x; pw*=10) {
				int r = x % 10;
				v[r] += pw;
				x /= 10;
			}
		}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			for (int i=0; i<=9; i++) {
				v[i] += other.v[i];
			}

			return *this;
		}

		node_t& operator+= (const updater& other) {
			/* UPDATE ADDITION */
			ll t[10] = {0};
			for (int i=0; i<=9; i++) {
				t[other.v[i]] += v[i];
			}
			for (int i=0; i<=9; i++) {
				v[i] = t[i];
			}

			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}

		ll val() const {
			ll z = 0;
			for (ll i=0; i<=9; i++) {
				z += i * v[i];
			}
			return z;
		}
	};

	node_t a[2*MAXN];
	updater b[2*MAXN];

	void init() {
		for (int i=n+1; i<=MAXN; i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			a[i + MAXN - 1] = node_t();
		}

		for (int i=1; i<=n; i++) {
			a[i + MAXN - 1] = node_t(a0[i]);
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

segtree_lazy<131072> drvo;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		cin >> a0[i];
	}

	drvo.init();

	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int l, r, x, y;
			cin >> l >> r >> x >> y;

			segtree_lazy<131072>::updater upd;

			upd.v[x] = y;
			upd.dirty = true;

			drvo.update(l, r, upd);
		} else {
			int l, r;
			cin >> l >> r;
			cout << drvo.get(l, r).val() << '\n';
		}
	}

}
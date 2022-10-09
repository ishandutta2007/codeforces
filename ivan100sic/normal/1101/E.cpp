#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

set<pair<int, int>> chain;

template<int MAXN>
struct segtree_lazy {

	struct updater {
		/* DATA MEMBERS */
		int x;

		updater(int x = 0) : x(x) {}

		updater& operator+= (const updater& other) {
			/* ADDITION */
			x = max(x, other.x);

			return *this;
		}

		operator bool () const {
			/* BOOL CAST */
			return x != 0;
		}
	};
	
	struct node_t {
		/* DATA MEMBERS */
		int x;

		/* CONSTRUCTOR */
		node_t(int x = 0) : x(x) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			x = max(x, other.x);

			return *this;
		}

		node_t& operator+= (const updater& other) {
			/* UPDATE ADDITION */
			x = max(x, other.x);

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

	node_t get(int l, int r, int node=1, int nl=0, int nr=MAXN-1) {
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

	void update(int l, int r, updater val, int node=1, int nl=0, int nr=MAXN-1) {
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

segtree_lazy<(1 << 21)> drvo;
basic_string<int> uq;

char t[500005];
int x[500005], y[500005], h, q;

int lb(int x) {
	return lower_bound(uq.begin(), uq.end(), x) - uq.begin();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> q;
	for (int i=0; i<q; i++) {
		cin >> t[i] >> x[i] >> y[i];
		uq += {x[i], y[i], x[i] - 1, y[i] - 1};
	}
	uq += 1123123123;
	sort(uq.begin(), uq.end());
	h = unique(uq.begin(), uq.end()) - uq.begin();
	uq.resize(h);

	for (int i=0; i<q; i++) {
		if (x[i] > y[i])
			swap(x[i], y[i]);
		int x0 = lb(x[i]);
		int x1 = lb(x[i] - 1);
		int y0 = lb(y[i]);
		int y1 = lb(y[i] - 1);
		int inf = lb(1123123123);
		if (t[i] == '+') {
			drvo.update(1, x1, inf);
			drvo.update(x0, y1, y1);
			drvo.update(y0, inf, x1);
		} else {
			int c = drvo.get(x0, x0).x;
			cout << (y0 <= c ? "NO\n" : "YES\n");
		}
	}
}
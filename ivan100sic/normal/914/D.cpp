#include <bits/stdc++.h>
using namespace std;

template<class T>
T gcd(T a, T b) {
	T t;
	while (a) {
		t = a;
		a = b % a;
		b = t;
	}
	return b;
}

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int x;

		/* CONSTRUCTOR */
		node_t(int x = 0) : x(x) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			x = gcd(x, other.x);

			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	node_t a[2*MAXN];

	void init() {
		for (int i=1; i<=MAXN; i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			a[i + MAXN - 1] = node_t();
		}
		for (int i=MAXN-1; i>0; i--) {
			a[i] = a[2*i] + a[2*i+1];
		}
	}

	int get(int l, int r, int x, int node=1, int nl=1, int nr=MAXN) {
		if (r < nl || nr < l) {
			return 0;
		}
		if (l <= nl && nr <= r) {
			if (a[node].x % x == 0) {
				return 0;
			}
		}

		if (node >= MAXN) {
			return 1;
		}

		int nm = (nl + nr) >> 1;

		int ls = get(l, r, x, 2*node, nl, nm);

		if (ls >= 2) {
			return 2;
		}

		return ls + get(l, r, x, 2*node+1, nm+1, nr);
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

segtree<524288> drvo;

int n, q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		drvo.set(i, x);
	}

	cin >> q;
	while (q--) {
		int t, l, r, x;
		cin >> t;
		if (t == 1) {
			cin >> l >> r >> x;
			cout << (drvo.get(l, r, x) <= 1 ? "YES\n" : "NO\n");
		} else {
			cin >> l >> x;
			drvo.set(l, x);
		}
	}
}
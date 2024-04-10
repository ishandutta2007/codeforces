#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int k;

struct pt {
	int x[5];

	int val(int mask) const {
		int z = 0;
		for (int i=0; i<k; i++) {
			if (mask & (1 << i))
				z += x[i];
			else
				z -= x[i];
		}
		return z;
	}
};

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		pt a[32];
		bool prazno;

		/* CONSTRUCTOR */
		node_t() : prazno(true) {}

		node_t(pt b) {
			for (int i=0; i<(1<<k); i++)
				a[i] = b;
			prazno = false;
		}

		node_t& operator+= (const node_t& other) {
			if (prazno) {
				*this = other;
				return *this;
			}

			if (other.prazno) {
				return *this;
			}

			for (int i=0; i<(1<<k); i++)
				if (a[i].val(i) < other.a[i].val(i))
					a[i] = other.a[i];
			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	vector<node_t> a;

	segtree() {}

	segtree(basic_string<pt> b) : a(2*MAXN) {
		for (int i=0; i<(int)b.size(); i++) {
			a[i + MAXN] = node_t(b[i]);
		}
		for (int i=MAXN-1; i>0; i--)
			a[i] = a[2*i] + a[2*i+1];
	}

	node_t get(int l, int r, int node=1, int nl=0, int nr=MAXN-1) {
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
		pos += MAXN;
		a[pos] = val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}
};

segtree<262144> drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, q;
	cin >> n >> k;
	basic_string<pt> b;
	while (n--) {
		pt a;
		for (int i=0; i<k; i++)
			cin >> a.x[i];
		b += a;
	}
	drvo = segtree<262144>(b);
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 2) {
			int x, y;
			cin >> x >> y;
			auto g = drvo.get(x-1, y-1);
			int z = 0;
			for (int i=0; i<(1 << k); i++) {
				int j = ((1 << k) - 1) ^ i;
				z = max(z, g.a[i].val(i) + g.a[j].val(j));
			}
			cout << z << '\n';
		} else {
			int x;
			cin >> x;
			pt b;
			for (int i=0; i<k; i++)
				cin >> b.x[i];
			drvo.set(x-1, b);
		}
	}
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int a[100005];

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int l, r;

		/* CONSTRUCTOR */
		node_t(int l = 123123123, int r = -123123123) : l(l), r(r) {
			l = max(l, -n);
			r = min(r, 2*n);
		}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			l = min(l, other.l);
			r = max(r, other.r);

			l = max(l, -n);
			r = min(r, 2*n);

			return *this;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	node_t a[2*MAXN];

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

	node_t get_cyclic(int l, int r) {
		if (r-l+1 >= n)
			return {0, n-1};
		if (l >= 0 && r < n)
			return get(l, r);
		if (l < 0) {
			auto g1 = get(0, r);
			auto g2 = get(n+l, n-1);
			g2.l -= n;
			g2.r -= n;
			return g1 + g2;
		}
		if (r >= n) {
			auto g1 = get(l, n-1);
			auto g2 = get(0, r-n);
			g2.l += n;
			g2.r += n;
			return g1 + g2;
		}
		return {};
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

segtree<131072> drvo[17];

ostream& operator<< (ostream& os, segtree<131072>::node_t a) {
	os << a.l << ' ' << a.r;
	return os;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;

	if (n == 1) {
		cout << "0\n";
		return 0;
	}

	for (int i=0; i<n; i++) {
		cin >> a[i];
		drvo[0].set(i, {i - a[i], i + a[i]});
	}

	for (int i=1; i<17; i++) {
		for (int j=0; j<n; j++) {
			auto [l1, r1] = drvo[i-1].get_cyclic(j, j);
			auto [l2, r2] = drvo[i-1].get_cyclic(l1, r1);
			drvo[i].set(j, {l2, r2});
		}
	}

	for (int j=0; j<n; j++) {
		int lx = j, rx = j, z = 0;
		for (int i=16; i>=0; i--) {
			auto [lt, rt] = drvo[i].get_cyclic(lx, rx);
			if (rt-lt+1 < n) {
				z += 1 << i;
				lx = lt;
				rx = rt;
			}
		}
		cout << z+1 << ' ';
	}
	cout << '\n';
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int x;

		/* CONSTRUCTOR */
		node_t(int x = 0) : x(x) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
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

	void init() {
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

	void add(int pos, node_t val) {
		pos += MAXN-1;
		a[pos] += val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
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

int n, k, d;
int a[500005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> d;
	for (int i=2; i<=n+1; i++)
		cin >> a[i];

	sort(a+2, a+n+2);

	drvo.set(1, 1);

	int z = 0;

	for (int i=2; i<=n+1; i++) {
		int lo = lower_bound(a+2, a+n+2, a[i] - d) - a;
		int hi = i-k+1;

		if (lo > hi)
			continue;

		z = !!drvo.get(lo-1, hi-1).x;
		if (z)
			drvo.set(i, 1);

		// cerr << i << ' ' << lo << ' ' << hi << ' ' << z << '\n';
	}

	cout << (drvo.get(n+1, n+1).x ? "YES\n" : "NO\n");
}
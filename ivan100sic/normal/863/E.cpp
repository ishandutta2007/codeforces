#include <bits/stdc++.h>
using namespace std;

int t;
map<int, int> compress;

int n;
int l[200005], r[200005];
int z[600005];

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int x;

		/* CONSTRUCTOR */
		node_t(int x = 10000005) : x(x) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			x = min(x, other.x);
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
		for (int i=1; i<=t; i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			a[i + MAXN - 1] = z[i];
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

segtree<1 << 20> drvo;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> l[i] >> r[i];
		compress[l[i]] = 0;
		compress[r[i]] = 0;
		compress[r[i]+1] = 0;
	}

	for (auto& p : compress) {
		p.second = ++t;
	}

	for (int i=1; i<=n; i++) {
		l[i] = compress[l[i]];
		r[i] = compress[r[i]];
		z[l[i]]++;
		z[r[i]+1]--;
	}

	for (int i=2; i<=t; i++) {
		z[i] += z[i-1];
	}

	drvo.init();

	for (int i=1; i<=n; i++) {
		if (drvo.get(l[i], r[i]).x > 1) {
			cout << i;
			return 0;
		}
	}

	cout << -1;
}
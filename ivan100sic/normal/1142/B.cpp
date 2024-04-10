#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, q;
int p[200005], pnx[200005];

int a[200005], seen[200005];
int f[20][200005];

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int x;

		/* CONSTRUCTOR */
		node_t(int x = 123123123) : x(x) {}

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

	void add(int pos, node_t val) {
		pos += MAXN;
		a[pos] += val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
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

	cin >> n >> m >> q;
	for (int i=0; i<n; i++) {
		cin >> p[i];
		p[i]--;
	}

	for (int i=0; i<n; i++)
		pnx[p[i]] = p[(i+1)%n];

	for (int i=0; i<m; i++) {
		cin >> a[i];
		a[i]--;
	}

	fill(seen, seen+n, m);
	f[0][m] = m;
	for (int i=m-1; i>=0; i--) {
		f[0][i] = seen[pnx[a[i]]];
		seen[a[i]] = i;
	}

	for (int i=1; i<20; i++)
		for (int j=0; j<=m; j++)
			f[i][j] = f[i-1][f[i-1][j]];

	for (int i=0; i<=m; i++) {
		int x = i;
		for (int j=0; j<20; j++) {
			if ((1 << j) & (n-1))
				x = f[j][x];
		}
		drvo.set(i, x);
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		cout << (drvo.get(l, r).x <= r);
	}
	cout << '\n';
}
#include <bits/stdc++.h>
using namespace std;

int n;
int a[300005];

int lmb[300005][30];
int rmb[300005][30];

inline int seek_left(int r, int val) {
	int v = 0;
	for (int i=0; i<30; i++) {
		if (!(val & (1<<i))) {
			v = max(v, lmb[r][i]);
		}
	}
	return v;
}

inline int seek_right(int l, int val) {
	int v = 10000000;
	for (int i=0; i<30; i++) {
		if (!(val & (1<<i))) {
			v = min(v, rmb[l][i]);
		}
	}
	return v;
}

template<int MAXN>
struct segtree_max {
	
	struct node_t {
		/* DATA MEMBERS */
		int x, pos;

		/* CONSTRUCTOR */
		node_t(int x = -1, int pos = 0) : x(x), pos(pos) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			if (other.x > x) {
				x = other.x;
				pos = other.pos;
			}

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
			a[i + MAXN - 1] = node_t(::a[i], i);
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
};

segtree_max<2*131072> drvom;

long long sol;

void solve(int l, int r) {
	if (l >= r) {
		return;
	}

	int m = drvom.get(l, r).pos;

	int bl, br;
	// binarna levo
	{
		bl = seek_left(m, a[m]) + 1;
	}

	// binarna desno
	{
		br = seek_right(m, a[m]) - 1;
	}

	bl = max(bl, l);
	br = min(br, r);

	// cerr << l << ' ' << r << ' ' << m << ' ' << bl << ' ' << br << '\n';

	sol += (m-l+1) * 1ll * (r-m+1);
	sol -= (m-bl+1) * 1ll * (br-m+1);

	solve(l, m-1);
	solve(m+1, r);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	a[1] = 2147483647;
	a[n+2] = 2147483647;

	for (int i=2; i<=n+1; i++) {
		cin >> a[i];
	}

	for (int i=1; i<=n+2; i++) {
		for (int j=0; j<30; j++) {
			if (a[i] & (1<<j)) {
				lmb[i][j] = i;
			} else {
				lmb[i][j] = lmb[i-1][j];
			}
		}
	}

	for (int i=n+2; i>=1; i--) {
		for (int j=0; j<30; j++) {
			if (a[i] & (1<<j)) {
				rmb[i][j] = i;
			} else {
				rmb[i][j] = rmb[i+1][j];
			}
		}
	}

	drvom.init();

	solve(2, n+1);

	cout << sol << '\n';
}
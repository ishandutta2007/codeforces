#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

void add(int* a, int x) {
	if (x == -1)
		return;
	if (a[0] == -1 || x < a[0]) {
		a[1] = a[0];
		a[0] = x;
	} else if (a[1] == -1 || x < a[1]) {
		a[1] = x;
	}
}

struct node {
	int a[9][2];

	node() {
		memset(a, 0xff, sizeof(a));
	}

	node(int x) {
		memset(a, 0xff, sizeof(a));
		for (int i=0, t=x; i<9; i++, t/=10) {
			if (t % 10) {
				a[i][0] = x;
			}
		}
	}

	node operator+ (const node& b) const {
		node t = *this;
		for (int i=0; i<9; i++) {
			add(t.a[i], b.a[i][0]);
			add(t.a[i], b.a[i][1]);
		}
		return t;
	}
};

const int maxn = 262144;
struct segtree {
	vector<node> a;
	segtree() : a(2*maxn) {}

	void update(int i, int x) {
		i += maxn;
		a[i] = node(x);
		while (i > 1) {
			i >>= 1;
			a[i] = a[2*i] + a[2*i+1];
		}
	}

	node query(int l, int r, int x=1, int xl=0, int xr=maxn-1) {
		if (r < xl || xr < l)
			return node();
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl+xr) >> 1;
		return query(l, r, 2*x, xl, xm) + query(l, r, 2*x+1, xm+1, xr);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int n, q;
	cin >> n >> q;
	segtree drvo;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		drvo.update(i, x);
	}	
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			int i, x;
			cin >> i >> x;
			drvo.update(i, x);
		} else {
			int l, r;
			cin >> l >> r;
			node t = drvo.query(l, r);
			int z = 2012012012;
			for (int i=0; i<9; i++)
				if (t.a[i][0] != -1 && t.a[i][1] != -1)
					z = min(z, t.a[i][0] + t.a[i][1]);
			if (z == 2012012012)
				z = -1;
			cout << z << '\n';
		}
	}
}
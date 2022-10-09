#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct node_t {
	/* DATA MEMBERS */
	int x[60];

	/* CONSTRUCTOR */
	node_t() {
		memset(x, 0, sizeof x);
	}

	node_t& operator+= (const node_t& other) {
		return *this = *this + other;
	}

	node_t operator+ (const node_t& other) const {
		node_t u;
		for (int i=0; i<60; i++)
			u.x[i] = x[i] + other.x[(i + x[i]) % 60];
		return u;
	}
};

template<int MAXN>
struct segtree {
	
	node_t a[2*MAXN];

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

	void set(int pos, node_t val) {
		pos += MAXN-1;
		a[pos] = val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}
};

segtree<131072> drvo;

int n;
int a[100005];
node_t init[8];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int k=2; k<=6; k++) {
		for (int j=0; j<60; j++) {
			init[k].x[j] = 1 + (j % k == 0);
		}
	}

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i], drvo.set(i, init[a[i]]);

	int q;
	cin >> q;
	while (q--) {
		char t;
		cin >> t;
		if (t == 'A') {
			int x, y;
			cin >> x >> y;
			cout << drvo.get(x, y-1).x[0] << '\n';
		} else {
			int x, y;
			cin >> x >> y;
			a[x] = y;
			drvo.set(x, init[y]);
		}
	}
}
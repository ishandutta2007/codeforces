#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
		// cerr << "drvo.set " << pos << ' ' << val.x << '\n';
		pos += MAXN-1;
		a[pos] = val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}
};

segtree<1<<20> drvo;

struct upit {
	int l, id;
};

int n, q;
int a[500005], ans[500005], seen[500005], seeeen[500005];
bool ima[500005];
vector<upit> u[500005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		ima[a[i]] = 1;
	}
	cin >> q;
	for (int i=1; i<=q; i++) {
		int l, r;
		cin >> l >> r;
		u[r].push_back({l, i});
	}

	// nesto?
	for (int i=1; i<=500000; i++)
		if (ima[i]) {
			seen[i] = -i;
		}

	for (int r=1; r<=n; r++) {
		// upd tabelu
		int x = a[r];
		
		if (seen[x] > 0)
			drvo.set(seen[x], 123123123);
		seeeen[x] = seen[x];
		seen[x] = r;

		drvo.set(seen[x], seeeen[x]);

		for (auto v : u[r]) {
			int t = drvo.get(v.l, r).x;
			// cerr << "get " << t << '\n';
			if (t == 123123123 || t >= v.l)
				ans[v.id] = 0;
			else if (t < 0)
				ans[v.id] = -t;
			else
				ans[v.id] = a[t];
		}
	}

	for (int i=1; i<=q; i++)
		cout << ans[i] << '\n';
}
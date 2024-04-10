// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int MAXN>
struct segtree_lazy {

	struct updater {
		/* DATA MEMBERS */
		ll x;

		updater(ll x = 0) : x(x) {}

		updater& operator+= (const updater& other) {
			/* ADDITION */
			x += other.x;

			return *this;
		}

		operator bool () const {
			/* BOOL CAST */
			return x != 0;
		}
	};
	
	struct node_t {
		/* DATA MEMBERS */
		ll x;

		/* CONSTRUCTOR */
		node_t(ll x = -1e18) : x(x) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			x = max(x, other.x);

			return *this;
		}

		node_t& operator+= (const updater& other) {
			/* UPDATE ADDITION */
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
	updater b[2*MAXN];

	segtree_lazy() {
		for (int i=1; i<2*MAXN; i++)
			a[i] = node_t(0);
	}

	void push(int i) {
		if (b[i]) {
			a[i] += b[i];
			if (i < MAXN) {
				b[2*i] += b[i];
				b[2*i+1] += b[i];
			}
			b[i] = updater();
		}
	}

	node_t get(int l, int r, int node=1, int nl=0, int nr=MAXN-1) {
		push(node);

		if (r < nl || nr < l) {
			return node_t();
		}
		if (l <= nl && nr <= r) {
			return a[node];
		}

		int nm = (nl + nr) >> 1;
		return get(l, r, 2*node, nl, nm) + get(l, r, 2*node+1, nm+1, nr);
	}

	void update(int l, int r, updater val, int node=1, int nl=0, int nr=MAXN-1) {
		push(node);

		if (r < nl || nr < l) {
			return;
		}
		if (l <= nl && nr <= r) {
			b[node] += val;
			push(node);
			return;
		}

		int nm = (nl + nr) >> 1;
		update(l, r, val, 2*node, nl, nm);
		update(l, r, val, 2*node+1, nm+1, nr);
		a[node] = a[2*node] + a[2*node+1];
	}
};

segtree_lazy<524288> drvo;

struct monster {
	int a, b, c;
	bool operator< (const monster& o) const {
		return a < o.a;
	}
};

struct gear {
	int x, y;
	bool operator< (const gear& o) const {
		return x < o.x;
	}
};

int n, m, p, q;
gear a[200005], b[200005];
monster c[200005];
pair<int, int> u[400005];

void dodaj_stvar(int p, int v) {
	// cerr << "dodaj_stvar " << p << '\n';
	drvo.update(p+1, 432432, v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> p;
	for (int i=0; i<n; i++)
		cin >> a[i].x >> a[i].y;
	sort(a, a+n);

	for (int i=0; i<m; i++)
		cin >> b[i].x >> b[i].y; 
	sort(b, b+m);
	for (int i=0; i<m; i++)
		u[i] = {b[i].x, i};

	for (int i=0; i<p; i++)
		cin >> c[i].a >> c[i].b >> c[i].c;
	sort(c, c+p);
	for (int i=0; i<p; i++)
		u[i+m] = {c[i].b, i+m};

	q = m + p;
	sort(u, u+q);

	const ll INF = 1e17;
	drvo.update(-1e9, 1e9, -INF);

	for (int i=0; i<m; i++) {
		int j = lower_bound(u, u+q, make_pair(b[i].x, i)) - u;
		drvo.update(j, j, INF-b[i].y);
	}

	int j = 0;
	ll sol = -1e18;
	for (int i=0; i<n; i++) {
		while (j < p && c[j].a < a[i].x) {
			int id = lower_bound(u, u+q, make_pair(c[j].b, j+m)) - u;
			dodaj_stvar(id, c[j].c);
			j++;
		}
		// testiraj
		ll tmp = drvo.get(0, 400005).x - a[i].y;
		// cerr << tmp << '\n';
		sol = max(sol, tmp);
	}

	cout << sol << '\n';
}

// I will still practice daily...
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll INF = 123'123'123'123'123'123ll;

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
		node_t(ll x = INF) : x(x) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			x = min(x, other.x);

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

	void init() {
		for (int i=1; i<=MAXN; i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			a[i + MAXN - 1] = node_t();
		}
		for (int i=MAXN-1; i>0; i--) {
			a[i] = a[2*i] + a[2*i+1];
		}
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

	node_t get(int l, int r, int node=1, int nl=1, int nr=MAXN) {
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

	void update(int l, int r, updater val, int node=1, int nl=1, int nr=MAXN) {
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

segtree_lazy<2*131072> drvo;

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		ll x;

		/* CONSTRUCTOR */
		node_t(ll x = INF) : x(x) {}

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
		pos += MAXN-1;
		a[pos] = val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}
};

segtree<2*131072> drvo_izi;


int n, m, q;
int a[200005], b[200005];
int maj[200005];
vector<pair<int, int>> e[200005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;
	for (int i=1; i<n; i++) {
		cin >> a[i] >> b[i+1];
	}

	for (int i=1; i<=m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u].push_back({v, w});
	}

	for (int j=1; j<=n; j++) {
		drvo.update(j, j, b[j] - INF);
	}

	for (int i=1; i<=n; i++) {
		// dodaj grane koje fale
		for (auto p : e[i]) {
			int v = p.first;
			int w = p.second;
			
			drvo.update(1, v, w);
		}
		// maj
		ll vr = drvo.get(1, n).x + a[i];

		// cerr << "! " << i << ' ' << vr << '\n';

		drvo_izi.set(i, vr);
	}

	/*
	for (int i=1; i<n; i++) {
		cerr << "??? " << drvo_izi.get(i, i).x << '\n';
		// cerr << "heh " << drvo.get(i, i).x << '\n';
	}

	for (int i=1; i<=n; i++) {
		// cerr << "??? " << drvo_izi.get(i, i).x << '\n';
		cerr << "heh " << drvo.get(i, i).x << '\n';
	}
	*/

	cout << drvo_izi.get(1, n).x << '\n';

	while (q--) {
		int i, v;
		cin >> i >> v;
		int delta = v - a[i];
		a[i] += delta;
		drvo_izi.set(i, drvo_izi.get(i, i).x + delta);

		cout << drvo_izi.get(1, n).x << '\n';
	}	
}
#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> e[200005];
int l[200005], r[200005];
int t;
int a0[200005];

template<int MAXN>
struct segtree_lazy {

	struct updater {
		/* DATA MEMBERS */
		int x;

		updater(int x = 0) : x(x) {}

		updater& operator+= (const updater& other) {
			/* ADDITION */
			x ^= other.x;

			return *this;
		}

		operator bool () const {
			/* BOOL CAST */
			return x != 0;
		}
	};
	
	struct node_t {
		/* DATA MEMBERS */
		int x, len;

		/* CONSTRUCTOR */
		node_t(int x = 0, int len = 0) : x(x), len(len) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			x += other.x;
			len += other.len;

			return *this;
		}

		node_t& operator+= (const updater& other) {
			/* UPDATE ADDITION */
			if (other.x) {
				x = len - x;
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
	updater b[2*MAXN];

	void init() {
		for (int i=1; i<=MAXN; i++) {
			/* KOPIRAJ NEKI EKSTERNI NIZ OVDE */
			a[i + MAXN - 1] = node_t();
		}

		for (int i=1; i<=n; i++) {
			int j = l[i] + MAXN - 1;
			a[j].x = a0[i];
			a[j].len = 1;
		}

		for (int i=MAXN-1; i>0; i--) {
			a[i] = a[2*i] + a[2*i+1];
		}
	}

	void push(int i) {
		if (b[i]) {

			// cerr << "pushing down " << i << '\n';

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

segtree_lazy<131072*4> drvo;

void dfs(int x) {
	l[x] = ++t;
	for (int y : e[x]) {
		dfs(y);
	}
	r[x] = ++t;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=2; i<=n; i++) {
		int x;
		cin >> x;
		e[x].push_back(i);
	}
	for (int i=1; i<=n; i++) {
		cin >> a0[i];
	}

	dfs(1);

	drvo.init();

	int q;
	cin >> q;
	while (q--) {
		string s;
		int x;
		cin >> s >> x;
		if (s == "get") {
			cout << drvo.get(l[x], r[x]).x << '\n';
		} else {
			drvo.update(l[x], r[x], segtree_lazy<131072*4>::updater(1));
		}
	}
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
int a[200005];

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int x;

		/* CONSTRUCTOR */
		node_t(int x = 222222) : x(x) {}

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

segtree<262144> drvo;

int prvi[200005], zadnji[200005];

void nema() {
	cout << "NO\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;

	vector<int> nule;

	for (int i=1; i<=n; i++) {
		cin >> a[i];
		if (a[i] == 0) {
			a[i] = 222222;
			nule.push_back(i);
		} else {
			int x = a[i];
			if (prvi[x] == 0)
				prvi[x] = i;
			zadnji[x] = i;
		}
	}

	// provera, da li se najveci broj javlja negde bar
	if (nule.size() == 0 && prvi[q] == 0)
		nema();

	// range provera
	drvo.init();
	for (int i=1; i<=n; i++)
		drvo.set(i, a[i]);

	for (int i=1; i<=q; i++) {
		if (prvi[i]) {
			int g = drvo.get(prvi[i], zadnji[i]).x;
			if (g < i)
				nema();
		}
	}

	// popuni greedy
	if ((int)nule.size() == n) {
		a[1] = 1;
	}

	for (int i=2; i<=n; i++)
		if (a[i] == 222222)
			a[i] = a[i-1];

	for (int i=n-1; i>=1; i--)
		if (a[i] == 222222)
			a[i] = a[i+1];
	
	// popuni q
	if (prvi[q] == 0 && nule.size()) {
		// pazljivo stavi q
		a[nule[0]] = q;
	}

	cout << "YES\n";
	for (int i=1; i<=n; i++)
		cout << a[i] << ' ';

}
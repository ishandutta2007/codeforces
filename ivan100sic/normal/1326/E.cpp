// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int p, m;

		/* CONSTRUCTOR */
		node_t(int p = 0, int m = 0) : p(p), m(m) {}

		node_t& operator+= (const node_t& other) {
			return *this = *this + other;
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp;
			if (p >= other.m) {
				tmp.m = m;
				tmp.p = p - other.m + other.p;
			} else {
				tmp.m = m + other.m - p;
				tmp.p = other.p;
			}
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

	void set(int pos, node_t val) {
		pos += MAXN-1;
		a[pos] = val;
		while (pos > 1) {
			pos >>= 1;
			a[pos] = a[2*pos] + a[2*pos+1];
		}
	}
};

segtree<(1<<20)> drvo;

int n, p[300005], q[300005], ip[300005];
int dokle[300005], sol[300005];

void stavi_plus(int x) {
	drvo.set(2*x, {1, 0});
}

void stavi_minus(int x) {
	drvo.set(2*x+1, {0, 1});
}

bool dobro() {
	return drvo.a[1].p > 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	drvo.init();

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> p[i], ip[p[i]] = i;
	for (int i=1; i<=n; i++)
		cin >> q[i];

	int u = 0;
	for (int x=n; x>=1; x--) {
		stavi_plus(ip[x]);
		while (u < n) {
			if (dobro()) {
				stavi_minus(q[++u]);
			} else {
				break;
			}
		}
		dokle[x] = u;
		sol[u] = max(sol[u], x);
	}

	for (int i=n; i>=1; i--)
		sol[i] = max(sol[i], sol[i+1]);

	for (int i=1, z=0; i<=n; i++)
		cout << sol[i] << " \n"[i == n];
}

// I will still practice daily...
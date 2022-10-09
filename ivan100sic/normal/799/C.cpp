#include <bits/stdc++.h>
using namespace std;

int n, c, d;
int b[100005], p[100005];
char tip[100005];

int sol = 0;

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int x;

		/* CONSTRUCTOR */
		node_t(int x = -1e9) : x(x) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			x = max(x, other.x);
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

typedef segtree<131072> drvo;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> c >> d;
	for (int i=1; i<=n; i++) {
		string s;
		cin >> b[i] >> p[i] >> s;
		tip[i] = s[0];
	}

	int sol = -1e9;

	// pravi mesovito
	{
		int max_c = -1e9, max_d = -1e9;
		for (int i=1; i<=n; i++) {
			if (tip[i] == 'C') {
				if (p[i] <= c) {
					max_c = max(max_c, b[i]);
				}
			} else {
				if (p[i] <= d) {
					max_d = max(max_d, b[i]);
				}
			}
		}
		sol = max(sol, max_c + max_d);
	}

	cerr << "after1 " << sol << '\n';

	// pravi dve c
	{
		drvo tre;
		for (int i=1; i<=n; i++) {
			if (tip[i] == 'C') {
				if (p[i] <= c) {
					sol = max(sol, b[i] + tre.get(1, c - p[i] + 1).x);
					tre.add(p[i] + 1, b[i]);
				}
			}
		}
	}

	// pravi dve d
	{
		drvo tre;
		for (int i=1; i<=n; i++) {
			if (tip[i] == 'D') {
				if (p[i] <= d) {
					sol = max(sol, b[i] + tre.get(1, d - p[i] + 1).x);
					tre.add(p[i] + 1, b[i]);
				}
			}
		}
	}

	if (sol < 0) {
		sol = 0;
	}

	cout << sol;
}
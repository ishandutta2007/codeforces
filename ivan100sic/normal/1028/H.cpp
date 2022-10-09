#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int SITO_MAX = 5100000;

int f[SITO_MAX+1];
int fs[SITO_MAX+1];
vector<int> prosti;

struct sito {
	sito() {

		// squarefree
		for (int i=1; i<=SITO_MAX; i++) {
			if (fs[i] == 0) {
				fs[i] = i;
				for (int j=1; j*j*i<=SITO_MAX; j++)
					fs[j*j*i] = i;
			}
		}

		for (int i=2; i<=SITO_MAX; i++) {
			if (f[i] == 0) {
				f[i] = i;
				prosti.push_back(i);
			}
			int j = 0;
			while (j < (int)prosti.size()) {
				if (prosti[j] > f[i]) {
					break;
				}
				int x = i * prosti[j];
				if (x > SITO_MAX) {
					break;
				}
				f[x] = prosti[j];
				j++;
			}
		}
	}
} sito_obj_983431;

vector<int> factor_small(int x) {
	vector<int> v;
	while (x > 1) {
		int p = f[x];
		x /= p;
		v.push_back(p);
	}
	return v;
}

struct qry {
	int l, i;
};

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int x;

		/* CONSTRUCTOR */
		node_t(int x = 12) : x(x) {}

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

int n, q;
int a[200000];
int ans[1100000];
vector<qry> e[200000];
int pos[5100000][13];

int rmost[20];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;
		a[i] = fs[x];
	}

	for (int i=1; i<=q; i++) {
		int l, r;
		cin >> l >> r;
		e[r].push_back({l, i});
	}

#define pc __builtin_popcount

	for (int i=1; i<=n; i++) {
		// seek
		vector<int> v = factor_small(a[i]);
		int m = v.size();
		fill(rmost, rmost+20, 0);
		
		for (int mask=0; mask<(1<<m); mask++) {
			int prod = 1;
			for (int i=0; i<m; i++)
				if ((1 << i) & mask)
					prod *= v[i];

			for (int i=0; i+m-pc(mask)<12; i++) {
				int d = i+m-pc(mask);
				rmost[d] = max(rmost[d], pos[prod][i]);
			}
		}

		/*
		cerr << "i: " << i << '\n';
		cerr << "rmost:";
		for (int j=0; j<12; j++)
			cerr << ' ' << rmost[j];
		cerr << '\n';
		*/

		// solve queries
		for (int i=0; i<12; i++)
			if (rmost[i] > 0)
				drvo.add(rmost[i], i);

		for (auto ee : e[i])
			ans[ee.i] = drvo.get(ee.l, i).x;

		// add
		for (int mask=0; mask<(1<<m); mask++) {
			int prod = 1;
			for (int i=0; i<m; i++)
				if ((1 << i) & mask)
					prod *= v[i];

			int& ref = pos[prod][m - pc(mask)];
			// cerr << "write " << prod << ' ' << m - pc(mask) << ' ' << i << '\n';
			ref = max(ref, i);
		}
	}

	for (int i=1; i<=q; i++)
		cout << ans[i] << '\n';

}
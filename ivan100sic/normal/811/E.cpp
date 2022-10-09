#include <bits/stdc++.h>
using namespace std;

int n, m, q;
int a[11][100005];

int ql[100000], qr[100000];

namespace minijoin {

	int p[40], sz[40];
	int reg[40], regsz;
	int remap[40];

	void resetuj() {
		iota(p, p+40, 0);
		fill(sz, sz+40, 1);
		regsz = 0;
	}

	void registruj(int x) {
		reg[regsz++] = x;	
	}

	int endp(int x) {
		while (x != p[x]) {
			x = p[x];
		}
		return x;
	}

	int spoji(int x, int y) {
		x = endp(x);
		y = endp(y);

		if (x == y) {
			return 0;
		}

		if (sz[x] > sz[y]) {
			swap(x, y);
		}
		p[x] = y;
		sz[y] += sz[x];

		return 1;
	}

	void remapiraj() {
		fill(remap, remap+40, -1);
		int maper = 0;
		for (int i=0; i<regsz; i++) {
			int x = endp(reg[i]);
			remap[x] = remap[x] == -1 ? maper++ : remap[x];
		}
	}

	int remapirano(int x) {
		return remap[endp(x)];
	}
}

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int l[10], r[10];
		int levi, desni;
		bool neutral;
		int brkom;

		/* CONSTRUCTOR */
		node_t() : neutral(true) {}

		node_t& operator+= (const node_t& other) {
			/* ADDITION */
			if (neutral) {
				*this = other;
				return *this;
			} else if (other.neutral) {
				return *this;
			} else {
				// cerr << "spajaaa " << desni << ' ' << other.levi << '\n';

				minijoin::resetuj();

				for (int i=0; i<n; i++) {
					minijoin::registruj(l[i]);
					minijoin::registruj(20 + other.r[i]);
				}

				brkom += other.brkom;

				for (int i=0; i<n; i++) {
					if (::a[i][desni] == ::a[i][other.levi]) {
						brkom -= minijoin::spoji(r[i], 20 + other.l[i]);
						// cerr << "spajam " << i << '\n';
					}
				}

				minijoin::remapiraj();

				for (int i=0; i<n; i++) {
					l[i] = minijoin::remapirano(l[i]);
					r[i] = minijoin::remapirano(20 + other.r[i]);
				}

				desni = other.desni;

				return *this;
			}
		}

		node_t operator+ (const node_t& other) const {
			node_t tmp = *this;
			tmp += other;
			return tmp;
		}
	};

	node_t a[2*MAXN];

	void init() {
		for (int i=1; i<=m; i++) {
			int maper = 0;
			
			node_t& cv = a[i + MAXN - 1];

			cv.neutral = false;
			cv.brkom = 1;
			cv.l[0] = 0;
			cv.r[0] = 0;
			cv.levi = cv.desni = i;

			for (int j=1; j<n; j++) {
				if (::a[j][i] == ::a[j-1][i]) {
					cv.l[j] = cv.r[j] = maper;
				} else {
					cv.brkom++;
					cv.l[j] = cv.r[j] = ++maper;
				}
			}
		}

		for (int i=m+1; i<=MAXN; i++) {
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

segtree<131072> drvo;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;

	for (int i=0; i<n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> a[i][j];
		}
	}

	drvo.init();

	for (int i=0; i<q; i++) {
		int l, r;
		cin >> l >> r;
		// cerr << "upit\n";
		cout << drvo.get(l, r).brkom << '\n';
	}

	
}
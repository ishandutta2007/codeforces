#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct event {
	char tip;
	int x, w, k;
	// x - koordinata upita / pocekta segmenta
	// w - duzina segmenta
	// k - o kom vitezu se radi ili odgovor na pitanje
};

struct knight {
	int l, r, x, w;
};

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		ll l, r, gep, strc;

		/* CONSTRUCTOR */
		node_t() : l(0), r(0), gep(0), strc(-1) {}

		node_t(ll l, ll r, ll gep, ll strc) :
			l(l), r(r), gep(gep), strc(strc) {}

		node_t& operator+= (const node_t& other) {
			if (other.strc == -1)
				return *this;

			if (strc == -1)
				return *this = other;

			/* ADDITION */
			ll g, s;
			if (strc <= other.gep) {
				g = gep + other.gep - strc;
				s = other.strc;
			} else {
				g = gep;
				s = other.strc + strc - other.gep;
			}
			r = other.r;
			gep = g;
			strc = s;
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
			a[i + MAXN - 1] = {i, i+1, 1, 0};
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

segtree<(1 << 20)> drvo;

int q, m;
int a[300005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> q;

	drvo.init();

	for (int i=1; i<=q; i++) {
		char c;
		cin >> c;
		if (c == '?') {
			int t;
			cin >> t;
			if (t == 1) {
				auto tmp = drvo.get(1, 1);
				if (tmp.gep == 0) {
					cout << tmp.strc + 1 << '\n';
				} else {
					cout << 0 << '\n';
				}
			} else {
				auto x = drvo.get(1, t-1);
				auto tmp = drvo.get(t, t);
				if (tmp.gep == 0) {
					x += tmp;
					cout << x.strc + 1 << '\n';
				} else {
					cout << x.strc << '\n';
				}
			}
		} else if (c == '+') {
			int t, d;
			cin >> t >> d;
			a[i] = t;
			drvo.set(t, {t, t+1, 0, d-1});
		} else if (c == '-') {
			int t;
			cin >> t;
			t = a[t];
			drvo.set(t, {t, t+1, 1, 0});
		}
	}
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int inf = 123123123;

template<int MAXN>
struct segtree {
	
	struct node_t {
		/* DATA MEMBERS */
		int x;

		/* CONSTRUCTOR */
		node_t(int x = 0) : x(x) {}

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

segtree<262144> drvo_pos; // koordinata = vrednost
segtree<262144> drvo_val; // koordinata = pozicija

int n, m;
int val[222222], pos[222222];
set<int> alive; // pozicije zivih

void dodaj(int p, int v) {
	vector<int> vv;
	pos[v] = p;
	val[p] = v;
	alive.insert(p);
	for (int i=0; i<=10; i++)
		if (pos[v-i])
			vv.push_back(v-i);
	for (int v : vv) {
		drvo_val.set(v, 0);
		drvo_pos.set(pos[v], 0);
	}
	for (int v : vv) {
		int z = drvo_pos.get(pos[v]+1, inf).x + 1;
		drvo_pos.set(pos[v], z);
		drvo_val.set(v, z);
	}
}

void brisi(int c) {
	vector<int> pp;
	auto it = alive.begin();
	for (int i=0; i<c; i++)
		pp.push_back(*it++);
	for (int p : pp) {
		drvo_pos.set(p, 0);
		drvo_val.set(val[p], 0);
	}
	int pe = pp.back(); pp.pop_back();
	alive.erase(pe);
	pos[val[pe]] = 0;
	val[pe] = 0;
	reverse(pp.begin(), pp.end());
	for (int p : pp) {
		int z = drvo_val.get(val[p]+1, inf).x + 1;
		drvo_val.set(val[p], z);
		drvo_pos.set(p, z);
	}
}

int resenje() {
	return drvo_val.a[1].x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;

	for (int i=0, hb = 200022; i<m; i++, hb--) {
		int t;
		cin >> t;
		if (t == 1) {
			int p, h;
			cin >> p >> h;
			dodaj(p, hb + h);
		} else {
			int x;
			cin >> x;
			brisi(x);
		}
		cout << resenje() << '\n';
	}
}
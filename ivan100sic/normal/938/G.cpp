#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct upit {
	int tip, u, v, w;
} a[400005];

struct zivot {
	int u, v, w, l, r;
};

vector<zivot> b;

int n, m, q;

struct izmena {
	int x, parent, sz, up;
	vector<int> baza;
};

int resi_sa_bazom(vector<int>& baza, int x) {
	// baza da bude sortirana opadajuce!
	for (int y : baza)
		x = min(x, x^y);
	return x;
}

void spoji_baze(vector<int>& b1, const vector<int>& b2) {
	for (int x : b2)
		b1.push_back(x);
	int l = 0;
	for (int i=29; i>=0; i--) {
		int k = -1;
		for (int j=l; j<(int)b1.size(); j++) {
			if (b1[j] & (1 << i)) {
				k = j;
				break;
			}
		}
		if (k != -1) {
			swap(b1[k], b1[l]);
			for (int j=l+1; j<(int)b1.size(); j++) {
				if (b1[j] & (1 << i)) {
					b1[j] ^= b1[l];
				}
			}
			l++;
		}
	}
	b1.resize(l);
}

struct dsu {
	vector<int> parent, sz, up;
	vector<vector<int>> baza;
	vector<izmena> stek;

	dsu(int n = 0) : parent(n), sz(n, 1), up(n, 0), baza(n) {
		iota(parent.begin(), parent.end(), 0);
	}

	int xor_dubina(int x) {
		int y = 0;
		while (x != parent[x]) {
			y ^= up[x];
			x = parent[x];
		}
		return y;
	}

	int endparent(int x) {
		while (x != parent[x]) {
			x = parent[x];
		}
		return x;
	}

	void dodaj_sentinel() {
		stek.push_back({-1, 0, 0, 0, {}});
	}

	void dodaj_granu(int x, int y, int w) {
		// ista komponenta?
		if (endparent(x) == endparent(y)) {
			int vx = xor_dubina(x);
			int vy = xor_dubina(y);
			vector<int> tmp = {vx ^ vy ^ w};
			int ep = endparent(x);
			stek.push_back({ep, parent[ep], sz[ep], up[ep], baza[ep]});
			spoji_baze(baza[ep], tmp);
		} else {
			w ^= xor_dubina(x) ^ xor_dubina(y);
			x = endparent(x);
			y = endparent(y);
			if (sz[x] > sz[y])
				swap(x, y);
			// x -> y
			stek.push_back({x, parent[x], sz[x], up[x], baza[x]});
			stek.push_back({y, parent[y], sz[y], up[y], baza[y]});
			up[x] = w;
			sz[y] += sz[x];
			spoji_baze(baza[y], baza[x]);
			parent[x] = y;
		}
	}

	void rollback() {
		while (stek.back().x != -1) {
			auto& b = stek.back();
			parent[b.x] = b.parent;
			sz[b.x] = b.sz;
			up[b.x] = b.up;
			baza[b.x] = b.baza;
			stek.pop_back();
		}
		stek.pop_back();
	}
} lepotan;

void resi(int l, int r, vector<zivot> e) {
	if (l > r)
		return;

	int m = (l+r) >> 1;

	vector<zivot> levi, desni;

	// cerr << "enter " << l << ' ' << r << '\n';
	lepotan.dodaj_sentinel();

	for (auto ee : e) {
		if (ee.l <= l && r <= ee.r) {
			lepotan.dodaj_granu(ee.u, ee.v, ee.w);
		} else {
			if (ee.l <= m) {
				levi.push_back(ee);
			}
			if (ee.r >= m+1) {
				desni.push_back(ee);
			}
		}
	}

	if (l == r && a[m].tip == 0) {
		int ep = lepotan.endparent(a[m].u);
		int w = lepotan.xor_dubina(a[m].u);
		w ^= lepotan.xor_dubina(a[m].v);
		a[m].w = resi_sa_bazom(lepotan.baza[ep], w);
	}

	if (l != r) {
		resi(l, m, levi);
		resi(m+1, r, desni);	
	}

	// cerr << "exit " << l << ' ' << r << '\n';
	lepotan.rollback();
}

void test() {
	vector<int> a = {54, 33, 18, 27, 50};
	vector<int> b = {};
	spoji_baze(a, b);
	for (int x : a)
		cerr << x << ' ';
	cerr << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	test();

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		if (u > v) swap(u, v);
		a[i] = {+1, u, v, w};
	}
	cin >> q;
	for (int i=1; i<=q; i++) {
		int t;
		cin >> t;
		if (t == 1) {
			int u, v, w;
			cin >> u >> v >> w;
			if (u > v) swap(u, v);
			a[i+m] = {+1, u, v, w};
		} else if (t == 2) {
			int u, v;
			cin >> u >> v;
			if (u > v) swap(u, v);
			a[i+m] = {-1, u, v};
		} else {
			int u, v;
			cin >> u >> v;
			if (u > v) swap(u, v);
			a[i+m] = {0, u, v};
		}
	}


	// zivot
	{
		map<pair<int, int>, int> kad;
		for (int i=1; i<=m+q; i++) {
			if (a[i].tip != 0) {
				int u = a[i].u;
				int v = a[i].v;
				auto it = kad.find({u, v});
				if (it != kad.end()) {
					b[it->second].r = i;
					kad.erase(it);
				} else {
					kad[{u, v}] = b.size();
					b.push_back({u, v, a[i].w, i, m+q});
				}
			}
		}	
	}

	lepotan = dsu(n+1);
	resi(1, m+q, b);

	for (int i=1; i<=m+q; i++)
		if (a[i].tip == 0)
			cout << a[i].w << '\n';

}
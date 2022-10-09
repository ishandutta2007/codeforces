#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef unsigned ui;
typedef unsigned long long ull;

ull hasher[63];

struct mybitset {
	ui a[63];

	void set(ui x) {
		a[x >> 5u] |= 1u << (x & 31u);
	}

	void operator^= (const mybitset& b) {
		for (ui i=0; i<63; i++)
			a[i] ^= b.a[i];
	}

	ui ffs() const {
		for (ui i=0; i<63; i++) {
			if (a[i]) {
				return (i << 5u) | __builtin_ctz(a[i]);
			}
		}
		return 2016u;
	}

	ull hash() const {
		ull h = 0;
		for (ui i=0; i<63; i++) {
			h ^= a[i] * hasher[i];
		}
		return h;
	}

	ui popcnt() const {
		ui h = 0;
		for (ui i=0; i<63; i++) {
			h += __builtin_popcount(a[i]);
		}
		return h;
	}

	mybitset minus(const mybitset& b) const {
		mybitset t;
		for (ui i=0; i<63; i++) {
			t.a[i] = a[i] & ~b.a[i];
		}
		return t;
	}

	bool notsubset(const mybitset& b) const {
		for (ui i=0; i<63; i++) {
			if (a[i] & ~b.a[i]) {
				return true;
			}
		}
		return false;
	}
};

int n, m, q;
mybitset a[2048], z[2048];

// mp[c] je mapa tj. niz parova (hes_vrednost, skup id_vrste), gde je c
//   broj setovanih bitova u a[id_vrste]
//   ako je skup prazan key se brise iz mape!
// lens je skup svih brojeva c takvih da mp[c] ima tacno jedan element
// dulens je skup svih brojeva c takvih da mp[c] ima bar dve razlicite hes vrednosti
//   tj velicina te mape je bar dva
// adj je skup svih brojeva c takvih da se c javlja u lens i ima sledbenika u lens, neka
//   je to y, tako da i mp[c] i mp[y] imaju tacno jedan element i
//   tako da se oni ne slazu tj. da mp[c][0] nije subset od mp[y][0]
map<ull, set<ui>> mp[2005];
set<int> lens, dulens, adj;

vector<int> dvareda(int i, int j) {
	mybitset t1 = a[i].minus(a[j]);
	mybitset t2 = a[j].minus(a[i]);
	int u = t1.ffs();
	int v = t2.ffs();
	return {i, u, j, v};
}

vector<int> ima() {
	if (dulens.size()) {
		int x = *dulens.begin();
		int i = *mp[x].begin()->second.begin();
		int j = *next(mp[x].begin())->second.begin();
		return dvareda(i, j);
	}

	if (adj.size()) {
		int x = *adj.begin();
		int y = *lens.upper_bound(x);
		int i = *mp[x].begin()->second.begin();
		int j = *mp[y].begin()->second.begin();
		return dvareda(i, j);
	}

	return {-1};
}

// bullshit-proof
void lens_erase(int c) {
	auto it = lens.find(c);
	if (it == lens.end())
		return;
	adj.erase(c);
	if (it != lens.begin()) {
		adj.erase(*prev(it));
		if (next(it) != lens.end()) {
			// ubaci dva nastala lepotana
			int i = *mp[*prev(it)].begin()->second.begin();
			int j = *mp[*next(it)].begin()->second.begin();
			if (a[i].notsubset(a[j])) {
				adj.insert(*prev(it));
			}
		}
	}
	lens.erase(it);
}

// bullshit-proof
void lens_insert(int c) {
	auto [it, has] = lens.insert(c);
	if (!has)
		return;

	// brisem par koji je pocepan
	if (it != lens.begin() && next(it) != lens.end()) {
		int i = *mp[*prev(it)].begin()->second.begin();
		int j = *mp[*next(it)].begin()->second.begin();
		if (a[i].notsubset(a[j])) {
			adj.erase(*prev(it));
		}
	}

	if (next(it) != lens.end()) {
		int i = *mp[*    (it)].begin()->second.begin();
		int j = *mp[*next(it)].begin()->second.begin();
		if (a[i].notsubset(a[j])) {
			adj.insert(*    (it));
		}
	}

	if (it != lens.begin()) {
		int i = *mp[*prev(it)].begin()->second.begin();
		int j = *mp[*    (it)].begin()->second.begin();
		if (a[i].notsubset(a[j])) {
			adj.insert(*prev(it));
		}
	}
}

void dodaj(int i) {
	ull h = a[i].hash();
	ui c = a[i].popcnt();

	int ol = mp[c].size();
	mp[c][h].insert(i);
	int nu = mp[c].size();

	if (ol == 0 && nu == 1) {
		lens_insert(c);
	} else if (ol == 1 && nu == 2) {
		lens_erase(c);
		dulens.insert(c);
	}
}

void skloni(int i) {
	ull h = a[i].hash();
	ui c = a[i].popcnt();

	int ol = mp[c].size();
	mp[c][h].erase(i);
	if (mp[c][h].empty())
		mp[c].erase(h);
	int nu = mp[c].size();

	if (ol == 2 && nu == 1) {
		dulens.erase(c);
		lens_insert(c);
	} else if (ol == 1 && nu == 0) {
		lens_erase(c);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	{
		mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
			+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));
		for (ui i=0; i<63; i++) {
			hasher[i] = uniform_int_distribution<ull>(0, -1ull)(eng) << 1 | 1;
		}
	}

	cin >> n >> m >> q;
	for (int i=1; i<=m; i++) {
		z[i] = z[i-1];
		z[i].set(i);
	}

	for (int i=1; i<=n; i++) {
		mp[0][a[0].hash()].insert(i);
		lens.insert(0);
	}

	for (int _q=0; _q<q; _q++) {
		int i, l, r;
		cin >> i >> l >> r;
		skloni(i);
		a[i] ^= z[r];
		a[i] ^= z[l-1];
		dodaj(i);
		auto v = ima();
		if (v.size() == 4) {
			if (v[0] > v[2])
				swap(v[0], v[2]);
			if (v[1] > v[3])
				swap(v[1], v[3]);
		}
			
		for (int x : v) {
			cout << x << ' ';
		}
		cout << '\n';
	}
}
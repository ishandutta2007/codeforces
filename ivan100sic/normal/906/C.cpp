#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count()
	+ reinterpret_cast<unsigned long>(new int) + *(new unsigned long));

int n;

struct graf {
	bitset<22> a[22];

	bitset<22>& operator[](int x) {
		return a[x];
	}

	const bitset<22>& operator[](int x) const {
		return a[x];
	}
};

graf klik(const graf& a, int x) {
	graf b = a;
	for (int i=0; i<n; i++) {
		if (!a[x][i])
			continue;
		b[i] |= a[x];
	}
	return b;
}

graf ucitaj() {
	int m;
	cin >> m;
	graf g;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		g[u][v] = 1;
		g[v][u] = 1;
	}
	for (int i=0; i<n; i++)
		g[i][i] = 1;
	// g.diam = dijametar(g);
	return g;
}

void print(const graf& g) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++)
			cerr << g[i][j];
		cerr << '\n';
	}
	cerr << '\n';
}

bool kompletan(const graf& g) {
	for (int i=0; i<n; i++)
		if ((int)g[i].count() != n)
			return false;
	return true;
}

basic_string<int> sol;

void resi_brzo(const graf& g, basic_string<int>& st, int curr) {
	if (curr == n) {
		if (kompletan(g)) {
			if (st.size() < sol.size())
				sol = st;
		}
		return;
	}
	resi_brzo(g, st, curr+1);
	st += curr;
	resi_brzo(klik(g, curr), st, curr+1);
	st.pop_back();
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	graf g = ucitaj();
	sol.resize(n);
	iota(sol.begin(), sol.end(), 0);
	basic_string<int> st;
	resi_brzo(g, st, 0);
	cout << sol.size() << '\n';
	for (int x : sol)
		cout << x+1 << ' ';
	cout << '\n';
}
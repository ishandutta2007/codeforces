#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
vector<pair<int, int>> e[3005];

struct stanje {
	int suma, cena;	
};

struct dpstek {

	vector<stanje> a;

	dpstek() {
		a = {{0, 0}};
	}

	void push(int x) {
		if (x == 1) {
			stanje t = {a.back().suma + 1, a.back().cena};
			a.push_back(t);
		} else {
			stanje t = {a.back().suma, a.back().cena + 1};
			t.cena = min(t.cena, t.suma);
			a.push_back(t);
		}
	}

	int cena() {
		return a.back().cena;
	}

	int suma() {
		return a.back().suma;
	}

	void pop() {
		a.pop_back();
	}
};

int naopake, z;

void dfs2(int x, int p, dpstek& s) {
	z = min(z, naopake - s.suma() + s.cena());
	for (auto [y, d] : e[x]) {
		if (y == p)
			continue;
		s.push(d);
		dfs2(y, x, s);
		s.pop();
	}
}

void dfs1(int x, int p) {
	for (auto [y, d] : e[x]) {
		if (y == p)
			continue;
		naopake += d;
		dfs1(y, x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u].emplace_back(v, 0);
		e[v].emplace_back(u, 1);
	}

	z = n;

	for (int i=1; i<=n; i++) {
		naopake = 0;
		dpstek s;
		dfs1(i, i);
		dfs2(i, i, s);
	}

	cout << z << '\n';

}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int c[200005];
basic_string<int> e[200005];
int ql[200005], qr[200005], listova;

void dfs(int x, int p) {
	ql[x] = listova;
	if (e[x].size() == 1 && x != 1)
		listova++;
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs(y, x);
	}
	qr[x] = listova;
}

int p[200005];

int ep(int x) {
	if (x == p[x])
		return x;
	return p[x] = ep(p[x]);
}

bool isti(int x, int y) {
	return ep(x) == ep(y);
}

bool spoji(int x, int y) {
	x = ep(x);
	y = ep(y);
	if (x == y)
		return false;
	p[x] = y;
	return true;
}

bool cmp(int i, int j) {
	return c[i] < c[j];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> c[i];

	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	dfs(1, 1);
	iota(p, p+listova+1, 0);

	ll sol = 0;
	basic_string<int> mozda_dobri;

	iota(p, p+listova+1, 0);
	map<int, basic_string<int>> klase;
	for (int i=1; i<=n; i++)
		klase[c[i]] += i;

	for (auto [w, v] : klase) {
		bool ok_klasa = false;
		for (int x : v) {
			if (!isti(ql[x], qr[x])) {
				ok_klasa = true;
			}
		}

		if (ok_klasa) {
			for (int x : v)
				if (!isti(ql[x], qr[x]))
					mozda_dobri += x;
		}

		for (int x : v) {
			sol += (ll)spoji(ql[x], qr[x]) * c[x];
		}
	}

	cout << sol << ' ' << mozda_dobri.size() << '\n';
	sort(mozda_dobri.begin(), mozda_dobri.end());
	for (int x : mozda_dobri)
		cout << x << ' ';
	cout << '\n';
}
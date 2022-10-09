#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, t, d;
basic_string<int> e[200005], acc, rej;
int vis[200005];
basic_string<pair<int, int>> sol;

void dfs(int x) {
	vis[x] = 1;
	for (int y : e[x]) {
		if (!vis[y]) {
			if (x == 1) {
				acc += y;
				t++;
			}
			dfs(y);
		} else {
			if (x == 1) {
				rej += y;
			}
		}
	}
}

int p[200005];

int ep(int x) {
	if (x == p[x])
		return x;
	return p[x] = ep(p[x]);
}

bool spoji(int x, int y) {
	x = ep(x);
	y = ep(y);
	if (x == y)
		return false;
	p[x] = y;
	return true;
}

void dodaj(int x, int y) {
	if (spoji(x, y))
		sol += {x, y};
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> d;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	iota(p, p+n+1, 0);

	dfs(1);

	if (d < t || d > (int)e[1].size())
		return cout << "NO\n", 0;

	cout << "YES\n";
	for (int j : acc)
		dodaj(1, j);

	for (int w=0; w<d-t; w++) {
		dodaj(1, rej[w]);
	}

	for (int x=2; x<=n; x++)
		for (int y : e[x])
			if (y != 1)
				dodaj(x, y);

	for (auto [x, y] : sol)
		cout << x << ' ' << y << '\n';
}
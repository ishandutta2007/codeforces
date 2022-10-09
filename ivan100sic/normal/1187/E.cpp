#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[200005];

int sz[200005];
ll dole[200005], gore[200005];

void dfs1(int x, int p) {
	sz[x] = 1;
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs1(y, x);
		sz[x] += sz[y];
		dole[x] += dole[y];
	}
	dole[x] += sz[x];
}

void dfs2(int x, int p) {
	ll z = x > 1 ? gore[x] : 0;
	for (int y : e[x]) {
		if (y == p)
			continue;
		z += dole[y];
	}
	for (int y : e[x]) {
		if (y == p)
			continue;
		gore[y] = z - dole[y] + n - sz[y];
		dfs2(y, x);
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
		e[u] += v;
		e[v] += u;
	}

	dfs1(1, 1);
	dfs2(1, 1);

	ll sol = 0;
	for (int i=1; i<=n; i++) {
		ll z = n;
		for (int j : e[i]) {
			if (sz[j] < sz[i]) {
				z += dole[j];
			} else {
				z += gore[i];
			}
		}
		// cerr << i << ' ' << dole[i] << ' ' << gore[i] << ' ' << z << '\n';
		sol = max(sol, z);
	}
	cout << sol << '\n';
}
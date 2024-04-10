#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, d;
basic_string<int> e[100005];
int a[100005];

int dole[100005]; // ovo mi pise na bananu
int gore[100005];

void dfs1(int x, int p) {
	dole[x] = -123123123;
	if (a[x])
		dole[x] = 0;
	for (int y : e[x])
		if (y != p) {
			dfs1(y, x);
			dole[x] = max(dole[x], dole[y] + 1);
		}
}

void dfs2(int x, int p) {

	int u = -123123123, v = -123123123;

	for (int y : e[x]) {
		if (y == p)
			continue;

		if (dole[y] > u) {
			v = u;
			u = dole[y];
		} else if (dole[y] > v) {
			v = dole[y];
		}
	}

	for (int y : e[x]) {
		if (y == p)
			continue;
		gore[y] = -123123123;
		if (a[x])
			gore[y] = 0;
		if (y != p) {
			if (dole[y] == u) {
				gore[y] = max({gore[y], gore[x] + 1, v + 1});
			} else {
				gore[y] = max({gore[y], gore[x] + 1, u + 1});
			}
		}
	}

	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs2(y, x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> d;
	for (int i=1; i<=m; i++) {
		int x;
		cin >> x;
		a[x] = 1;
	}

	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}

	gore[1] = -123123123;
	dfs1(1, 1);
	dfs2(1, 1);

	int z = 0;
	for (int i=1; i<=n; i++) {
		// cerr << i << ' ' << dole[i] << ' ' << gore[i]+1 << '\n';
		if (max(gore[i]+1, dole[i]) <= d) {
			z++;
		}
	}
	cout << z << '\n';
}
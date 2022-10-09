// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, c[200005];
basic_string<int> e[200005];
int up[200005], dn[200005], par[200005];

void dfs1(int x, int p) {
	par[x] = p;
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs1(y, x);
		dn[x] += dn[y];
	}
	dn[x] = max(0, dn[x] + c[x]);
}

void dfs2(int x, int p) {
	int zb = x > 1 ? up[x] : 0;
	for (int y : e[x]) {
		if (y == p)
			continue;
		zb += dn[y];
	}

	for (int y : e[x]) {
		if (y == p)
			continue;
		up[y] = max(0, zb - dn[y] + c[x]);
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

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> c[i], c[i] = 2*c[i] - 1;
	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}

	dfs1(1, 1);
	dfs2(1, 1);

	for (int x=1; x<=n; x++) {
		int v;
		if (x == 1)
			v = c[x];
		else
			v = up[x] + c[x];
		for (int y : e[x]) {
			if (y != par[x]) {
				v += dn[y];
			}
		}
		cout << v << " \n"[x == n];
	}
}

// I will still practice daily...
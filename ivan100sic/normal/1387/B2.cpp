// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
basic_string<int> e[100005];
int a[100005];
ll cost;

int sz[100005];

void dfs1(int x) {
	sz[x] = 1;
	for (int y : e[x]) {
		if (sz[y] == 0) {
			dfs1(y);
			sz[x] += sz[y];
		}
	}
}

int cent;

void dfs2(int x, int p) {
	int ok = 1;
	for (int y : e[x]) {
		if (y == p) {
			continue;
		}

		dfs2(y, x);

		if (sz[y]*2 > n) {
			ok = 0;
		}
	}

	if (x != p) {
		if (sz[x] * 2 > n) {
			ok = 0;
		}
	}

	if (ok) {
		cent = x;
	}
}

int el[100005], dt, elinv[100005];

void dfs3(int x, int p) {
	el[x] = dt++;
	for (int y : e[x]) {
		if (y == p) {
			continue;
		}

		dfs3(y, x);
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		e[u] += v;
		e[v] += u;
	}

	cent = -1;
	dfs1(0);
	dfs2(0, 0);
	dfs3(cent, cent);

	for (int i=0; i<n; i++) {
		elinv[el[i]] = i;
	}

	for (int i=0; i<n; i++) {
		a[i] = elinv[(el[i] + n/2) % n];
	}

	for (int i=1; i<n; i++) {
		cost += min(sz[i], n - sz[i]);
	}

	cout << cost*2 << '\n';
	for (int i=0; i<n; i++) {
		cout << a[i]+1 << " \n"[i == n-1];
	}
}
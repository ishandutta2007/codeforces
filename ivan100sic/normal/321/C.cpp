#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[100005];
string sol;

bool blok[100005];
int sz[100005], centar;

void dfs1(int x, int p) {
	sz[x] = 1;
	for (int y : e[x]) {
		if (y != p && !blok[y]) {
			dfs1(y, x);
			sz[x] += sz[y];
		}
	}
}

void dfs2(int x, int p, int gsz) {
	bool ok = 1;
	for (int y : e[x]) {
		if (y != p && !blok[y]) {
			if (2 * sz[y] > gsz) {
				ok = 0;
			}
			dfs2(y, x, gsz);
		}
	}
	if (2 * (gsz - sz[x]) > gsz)
		ok = 0;
	if (ok)
		centar = x;
}

void solve(int x, char rank) {
	// nadji centroid
	dfs1(x, x);
	dfs2(x, x, sz[x]);
	sol[centar-1] = rank;
	blok[centar] = 1;
	for (int y : e[centar]) {
		if (!blok[y]) {
			solve(y, rank+1);
		}
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
	sol.resize(n);
	solve(1, 'A');
	for (int i=0; i<n; i++)
		cout << sol[i] << ' ';
	cout << '\n';
}
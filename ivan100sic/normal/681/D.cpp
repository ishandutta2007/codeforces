#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[100005], topo;
int d[100005], p[100005][17];
bool root[100005];

void dfs1(int x) {

	// {
	// 	cerr << "dfs1 " << x << '\n';
	// }

	for (int i=1; i<17; i++) {
		p[x][i] = p[p[x][i-1]][i-1];
	}

	for (int y : e[x]) {
		d[y] = d[x] + 1;
		p[y][0] = x;
		dfs1(y);
	}
}

basic_string<int> f[100005];

void dodaj(int x, int y, int d) {
	for (int i=0; i<17; i++) {
		if (d & (1 << i)) {
			// cerr << "f " << x << ' ' << y << ' ' << i << '\n';
			f[x] += y+i*n;
			y = p[y][i];
		}
	}
}

bool vis[100005 * 17], inst[100000 * 17], failed;

void dfs2(int x) {

	// {
	// 	int xx = x % n;
	// 	int j = x / n;
	// 	if (xx == 0) {
	// 		xx = n;
	// 		j--;
	// 	}
	// 	cerr << "dfs2 " << xx << ' ' << j << '\n';
	// }

	if (vis[x]) {
		failed |= inst[x];
		return;
	}

	vis[x] = inst[x] = true;
	if (x <= n) {
		for (int y : f[x]) {
			dfs2(y);
		}
		topo += x;
	} else {
		int xx = x % n;
		int j = x / n;
		if (xx == 0) {
			xx = n;
			j--;
		}

		dfs2(x-n);
		dfs2(p[xx][j-1] + n*(j-1));
	}

	inst[x] = false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	fill(root+1, root+n+1, true);
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		root[v] = false;
	}

	for (int i=1; i<=n; i++) {
		if (root[i]) {
			// cerr << "visiting " << i << '\n';
			p[i][0] = i;
			dfs1(i);
		}
	}

	for (int i=1; i<=n; i++) {
		int x;
		cin >> x;

		dodaj(x, p[x][0], d[x]);
		dodaj(x, i, d[i] - d[x]);
	}

	for (int i=1; i<=n; i++)
		dfs2(i);

	if (failed) {
		cout << "-1\n";
		return 0;
	}

	reverse(topo.begin(), topo.end());

	cout << n << '\n';
	for (int x : topo)
		cout << x << '\n';
}
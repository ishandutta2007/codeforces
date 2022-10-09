#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, q;
int u[200005], v[200005];
basic_string<int> e[200005];

int idx[200005], low[200005], dt, kk;
int komp[200005];
basic_string<int> ds, cs;
bool ins[200005];

void dfs1(int x, int ip) {
	idx[x] = low[x] = ++dt;
	ds += x;
	ins[x] = true;
	cs += x;
	for (int i : e[x]) {
		if (i == ip)
			continue;
		int y = u[i] ^ v[i] ^ x;
		if (ins[y]) {
			low[x] = min(low[x], idx[y]);
		} else if (idx[y] == 0) {
			dfs1(y, i);
			low[x] = min(low[x], low[y]);
		}
	}

	if (idx[x] == low[x]) {
		kk++;
		while (1) {
			int t = cs.back();
			cs.pop_back();
			komp[t] = kk;
			if (t == x)
				break;
		}
	}

	ds.pop_back();
	ins[x] = false;
}

basic_string<int> f[200005];
int p[200005][19];
bool mu[200005][19], md[200005][19];
int dub[200005];

void dfs2(int x, int pa) {
	p[x][0] = pa;
	for (int i=1; i<19; i++)
		p[x][i] = p[p[x][i-1]][i-1];
	for (int y : f[x]) {
		if (y == pa)
			continue;
		dub[y] = dub[x] + 1;
		dfs2(y, x);
	}
}

int dizi(int x, int k) {
	for (int i=0; i<19; i++) {
		if (k & (1 << i)) {
			x = p[x][i];
		}
	}
	return x;
}

int lca(int u, int v) {
	if (dub[u] > dub[v])
		swap(u, v);
	v = dizi(v, dub[v] - dub[u]);
	if (u == v)
		return u;
	for (int i=18; i>=0; i--) {
		int x = p[u][i], y = p[v][i];
		if (x != y)
			u = x, v = y;
	}
	return p[u][0];
}

template<class T>
int markiraj(int x, int k, T mk) {
	for (int i=0; i<19; i++) {
		if (k & (1 << i)) {
			mk[x][i] = true;
			x = p[x][i];
		}
	}
	return x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;
	for (int i=1; i<=m; i++) {
		cin >> u[i] >> v[i];
		e[u[i]] += i;
		e[v[i]] += i;
	}

	for (int i=1; i<=n; i++) {
		if (!idx[i]) {
			dfs1(i, -1);
		}
	}

	for (int i=1; i<=m; i++) {
		int x = komp[u[i]];
		int y = komp[v[i]];
		if (x != y) {
			f[x] += y;
			f[y] += x;
		}
	}

	for (int i=1; i<=n; i++) {
		if (!p[i][0]) {
			dfs2(i, i);
		}
	}

	while (q--) {
		int x, y;
		cin >> x >> y;
		x = komp[x];
		y = komp[y];
		if (p[x][18] != p[y][18]) {
			cout << "No\n";
			return 0;
		}
		int z = lca(x, y);
		markiraj(x, dub[x]-dub[z], mu);
		markiraj(y, dub[y]-dub[z], md);
	}

	for (int i=18; i>0; i--) {
		for (int x=1; x<=n; x++) {
			int y = p[x][i-1];
			md[x][i-1] |= md[x][i];
			md[y][i-1] |= md[x][i];
			mu[x][i-1] |= mu[x][i];
			mu[y][i-1] |= mu[x][i];
		}
	}

	for (int x=1; x<=n; x++) {
		if (mu[x][0] && md[x][0]) {
			cout << "No\n";
			return 0;
		}
	}

	cout << "Yes\n";
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
int u[100005], v[100005], t[100005];
basic_string<int> e[100005];

int p[100005][18], mark[2][100005][18], d[100005];

void dfs(int x, int par) {
	p[x][0] = par;
	for (int i=1; i<18; i++)
		p[x][i] = p[p[x][i-1]][i-1];
	for (int y : e[x]) {
		if (y == par)
			continue;
		d[y] = d[x] + 1;
		dfs(y, x);
	}
}

int submark(int x, int k, int t) {
	for (int i=0; i<18; i++) {
		if (k & (1 << i)) {
			mark[t][x][i]++;
			x = p[x][i];
		}
	}
	return x;
}

void markiraj(int u, int v) {
	if (d[u] > d[v]) {
		u = submark(u, d[u] - d[v], 0);
	} else if (d[u] < d[v]) {
		v = submark(v, d[v] - d[u], 1);
	}
	if (u == v)
		return;
	for (int i=17; i>=0; i--) {
		int uu = p[u][i];
		int vv = p[v][i];
		if (uu != vv) {
			mark[0][u][i]++;
			mark[1][v][i]++;
			u = uu;
			v = vv;
		}
	}
	mark[0][u][0]++;
	mark[1][v][0]++;
}

const int mod = 1'000'000'007;
int pw2[1000005];

void ad(int& x, int y) {
	x += y;
	if (x >= mod)
		x -= mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	for (int i=1; i<1000005; i++) {
		ad(pw2[i], pw2[i-1]);
		ad(pw2[i], pw2[i-1]);
		ad(pw2[i], 1);
	}

	cin >> n;
	for (int i=0; i<n-1; i++) {
		cin >> u[i] >> v[i] >> t[i];
		e[u[i]] += v[i];
		e[v[i]] += u[i];
	}

	dfs(1, 1);
	int q;
	cin >> q;
	basic_string<int> put = {1};
	for (int i=0; i<q; i++) {
		int x;
		cin >> x;
		put += x;
	}
	for (int i=0; i<q; i++) {
		markiraj(put[i], put[i+1]);
	}
	for (int i=17; i>=1; i--) {
		for (int x=1; x<=n; x++) {
			for (int t=0; t<2; t++) {
				mark[t][x][i-1] += mark[t][x][i];
				mark[t][p[x][i-1]][i-1] += mark[t][x][i];	
			}
		}
	}

	int z = 0;

	for (int i=0; i<n-1; i++) {
		if (t[i]) {
			int tip = d[u[i]] > d[v[i]];
			int amt = pw2[mark[tip][tip ? u[i] : v[i]][0]];
			// cerr << u[i] << ' ' << v[i] << ' ' << amt << '\n';
			ad(z, amt);
		}
	}

	cout << z << '\n';
}
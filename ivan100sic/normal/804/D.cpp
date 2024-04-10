#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, q;
basic_string<int> e[100005];
int cc[100005], bcc;
int d1[100005], d2[100005], far, d[100005];

vector<int> f[100005], pref[100005], w[100005];
vector<ll> suff[100005];

void dfs1(int x, int p, int* d) {
	if (d[x] > d[far])
		far = x;
	for (int y : e[x]) {
		if (y == p)
			continue;
		d[y] = d[x] + 1;
		cc[y] = cc[x];
		dfs1(y, x, d);
	}
}

void dfs2(int x, int p) {
	d[x] = max(d1[x], d2[x]);
	f[cc[x]].push_back(x);
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs2(y, x);
	}
}

map<pair<int, int>, double> cache;

double resi(int x, int y) {
	x = cc[x];
	y = cc[y];
	if (x == y)
		return -1;
	double& sol = cache[{min(x, y), max(x, y)}];
	if (sol > 0)
		return sol;

	if (w[x].size() > w[y].size())
		swap(x, y);

	for (int i=0; i<(int)w[x].size(); i++) {
		int j = w[y].size() - 2 - i;
		if (j < 0)
			j = 0;
		sol += (w[y].size() - 1.0) * pref[y][j] * w[x][i];
		sol += w[x][i] * 1.0 * suff[y][j];
		sol += (i + 1.0) * w[x][i] * (pref[y][w[y].size()] - pref[y][j]);
	}

	sol /= f[x].size();
	sol /= f[y].size();
	
	return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> q;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	for (int i=1; i<=n; i++) {
		if (cc[i] == 0) {
			cc[i] = ++bcc;
			
			far = i;
			d1[i] = 0;
			dfs1(i, i, d1);

			int x1 = far;

			far = x1;
			d2[x1] = 0;
			dfs1(x1, x1, d2);

			int x2 = far;

			d1[x2] = 0;
			dfs1(x2, x2, d1);

			dfs2(i, i);
		}
	}

	for (int i=1; i<=bcc; i++) {
		for (int x : f[i]) {
			while (d[x] >= (int)w[i].size())
				w[i].push_back(0);
			w[i][d[x]]++;
		}

		pref[i].resize(w[i].size() + 1);
		for (int j=0; j<(int)w[i].size(); j++) {
			pref[i][j+1] = pref[i][j] + w[i][j];
		}

		suff[i].resize(w[i].size() + 1);
		for (int j=w[i].size()-1; j>=0; j--) {
			suff[i][j] = suff[i][j+1] + w[i][j] * 1ll * j;
		}
	}

	cout << setprecision(9) << fixed;

	while (q--) {
		int x, y;
		cin >> x >> y;
		double s = resi(x, y);
		if (s < 0)
			cout << "-1\n";
		else
			cout << s << '\n';
	}


}
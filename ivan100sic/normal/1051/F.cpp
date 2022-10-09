#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <numeric>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
int u[100005], v[100005], w[100005];
bool te[100005];
vector<int> e[100005];
set<int> spec;
int sp[55], spc;
ll fw[55][55];

ll spec_dist[55][100005];
ll dub[100005];
int nivo[100005];

void dfs(int x, int p, ll* dist) {
	for (int i : e[x]) {
		int y = x ^ u[i] ^ v[i];
		if (y == p) {
			continue;
		}
		dist[y] = dist[x] + w[i];
		dfs(y, x, dist);
	}
}

int parent[100005][18];

void dfs_lca(int x, int p) {
	parent[x][0] = p;
	for (int i = 1; i < 18; i++) {
		parent[x][i] = parent[parent[x][i - 1]][i - 1];
	}

	for (int i : e[x]) {
		int y = x ^ u[i] ^ v[i];
		if (y == p) {
			continue;
		}
		dub[y] = dub[x] + w[i];
		nivo[y] = nivo[x] + 1;
		dfs_lca(y, x);
	}
}

int dizi(int x, int y) {
	for (int i = 0; i < 18; i++) {
		if (y & (1 << i)) {
			x = parent[x][i];
		}
	}
	return x;
}

int lca(int x, int y) {
	if (nivo[x] < nivo[y]) {
		swap(x, y);
	}
	x = dizi(x, nivo[x] - nivo[y]);
	if (x == y) {
		return x;
	}
	for (int i = 17; i >= 0; i--) {
		int xx = parent[x][i];
		int yy = parent[y][i];
		if (xx != yy) {
			x = xx;
			y = yy;
		}
	}
	return parent[x][0];
}

ll tree_dist(int x, int y) {
	int z = lca(x, y);
	return dub[x] + dub[y] - 2 * dub[z];
}

struct dsu {
	vector<int> p;

	dsu(int n) : p(n) {
		iota(p.begin(), p.end(), 0);
	}

	int e(int x) {
		if (x == p[x]) {
			return x;
		}
		return p[x] = e(p[x]);
	}

	bool merge(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y) {
			return false;
		}
		p[x] = y;
		return true;
	}
};

void solve() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> u[i] >> v[i] >> w[i];
	}

	dsu ds(n + 1);
	
	for (int i = 1; i <= m; i++) {
		te[i] = ds.merge(u[i], v[i]);
		if (te[i]) {
			e[u[i]].push_back(i);
			e[v[i]].push_back(i);
		}
		else {
			spec.insert(u[i]);
			spec.insert(v[i]);
		}
	}

	for (int x : spec) {
		sp[++spc] = x;
	}

	for (int i = 1; i <= spc; i++) {
		dfs(sp[i], sp[i], spec_dist[i]);
	}

	dfs_lca(1, 1);

	memset(fw, 63, sizeof(fw));

	for (int i = 1; i <= spc; i++) {
		for (int j = 1; j <= spc; j++) {
			fw[i][j] = min(fw[i][j], tree_dist(sp[i], sp[j]));
		}
	}

	for (int i = 1; i <= m; i++) {
		if (!te[i]) {
			auto ii = find(sp + 1, sp + n + 1, u[i]) - sp;
			auto jj = find(sp + 1, sp + n + 1, v[i]) - sp;

			fw[ii][jj] = min(fw[ii][jj], (ll)w[i]);
			fw[jj][ii] = min(fw[jj][ii], (ll)w[i]);
		}
	}

	for (int i = 1; i <= spc; i++) {
		fw[i][i] = 0;
	}

	// fw
	for (int k = 1; k <= spc; k++) {
		for (int i = 1; i <= spc; i++) {
			for (int j = 1; j <= spc; j++) {
				fw[i][j] = min(fw[i][j], fw[i][k] + fw[k][j]);
			}
		}
	}

	// upiti
	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		ll sol = tree_dist(x, y);
		// preko cvorova i, j
		for (int i = 1; i <= spc; i++) {
			for (int j = 1; j <= spc; j++) {
				sol = min(sol, fw[i][j] + spec_dist[i][x] + spec_dist[j][y]);
			}
		}
		cout << sol << '\n';
	}
}

int main() {
	solve();
#ifdef _MSVC_STL_VERSION
	system("pause");
#endif
}
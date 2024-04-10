#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <numeric>
#include <iterator>
#include <cstring>
using namespace std;

int n, m, k;
vector<int> e[100005];
vector<int> pid[100005];

vector<int> poly[100005];

int uu[100005], vv[100005];

void walk(int i, int j) {
	while (pid[i][j] == 0) {
		pid[i][j] = k;
		poly[k].push_back(i);
		int y = e[i][j];
		int q = lower_bound(e[y].begin(), e[y].end(), i) - e[y].begin();
		q = (q + 1) % e[y].size();

		i = y;
		j = q;
	}
}

int perm[100005];
int inv[100005];

bool cmp(int x, int y) {
	return poly[x] < poly[y];
}

vector<int> ee[100005];

int blocked[100005];

int dfs_size(int x, int p) {
	int z = 1;
	for (int y : ee[x]) {
		if (y != p && !blocked[y]) {
			z += dfs_size(y, x);
		}
	}
	return z;
}

int best_v, best_x;

int dfs_find(int x, int p, int sz) {
	int z = 1;
	int val = 0;
	for (int y : ee[x]) {
		if (y != p && !blocked[y]) {
			int rek = dfs_find(y, x, sz);
			val = max(val, rek);
			z += rek;
		}
	}

	val = max(val, sz - z);

	if (val < best_v) {
		best_v = val;
		best_x = x;
	}

	return z;
}


int centroid(int x) {
	int sz = dfs_size(x, x);
	best_v = sz;
	best_x = x;
	dfs_find(x, x, sz);
	return best_x;
}

int ans[100005];

void solve(int x, int d) {
	// nadji centroid
	x = centroid(x);
	ans[x] = d;

	// cerr << "centroid: " << x << '\n';

	blocked[x] = 1;

	for (int y : ee[x]) {
		if (!blocked[y]) {
			solve(y, d+1);
		}
	}
} 

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].push_back(v);
		e[v].push_back(u);

		uu[i] = u;
		vv[i] = v;
	}

	for (int i=1; i<=n; i++) {
		int nx = i == n ? 1 : i+1;
		int pr = i == 1 ? n : i-1;

		e[i].push_back(nx);
		e[i].push_back(pr);
	}

	for (int i=1; i<=n; i++) {
		sort(e[i].begin(), e[i].end());
		pid[i] = vector<int>(e[i].size(), 0);
	}

	for (int i=1; i<=n; i++) {
		for (int j=0; j<e[i].size(); j++) {
			if (pid[i][j] == 0) {
				k++;
				walk(i, j);
			}
		}
	}

	for (int i=1; i<=k; i++) {
		sort(poly[i].begin(), poly[i].end());
		reverse(poly[i].begin(), poly[i].end());
		perm[i] = i;
	}

	sort(perm+1, perm+k+1, cmp);

	for (int i=1; i<=k; i++) {
		inv[perm[i]] = i;
	}

	for (int i=1; i<=k; i++) {
		/*
		cerr << i << '\n';
		for (int x : poly[perm[i]]) {
			cerr << x << ' ';
		}
		cerr << '\n';
		*/
	}

	// zapravo ih ima k-1 i to su od 2 do k
	// perm[1] = originalni id najmanjeg poligona

	// inv[i] = novi id starog poligona


	for (int _=1; _<=m; _++) {
		int u = uu[_];
		int v = vv[_];

		int i = lower_bound(e[u].begin(), e[u].end(), v) - e[u].begin();
		int j = lower_bound(e[v].begin(), e[v].end(), u) - e[v].begin();

		i = pid[u][i];
		j = pid[v][j];

		i = inv[i];
		j = inv[j];

		ee[i].push_back(j);
		ee[j].push_back(i);

		// cerr << i << ' ' << j << '\n';
	}

	solve(1, 1);

	for (int i=1; i<k; i++) {
		cout << ans[i] << ' ';
	}
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int H = 500005, L = 20;

struct dsu {
	vector<int> p;

	dsu(int n) : p(n) {
		iota(p.begin(), p.end(), 0);
	}

	int e(int x) {
		if (x == p[x])
			return x;
		return p[x] = e(p[x]);
	}

	bool spoji(int x, int y) {
		x = e(x);
		y = e(y);
		if (x == y)
			return false;
		p[x] = y;
		return true;
	}
};

int n, k, m;
int u1[H], v1[H], w1[H];
int u2[H], v2[H], w2[H];

basic_string<int> e[H];
bool radi[H];

int p[H][L], dub[H];

void dfs(int x, int par) {
	p[x][0] = par;
	for (int i=1; i<L; i++)
		p[x][i] = p[p[x][i-1]][i-1];
	for (int y : e[x]) {
		if (y == par)
			continue;
		dub[y] = dub[x] + 1;
		dfs(y, x);
	}
}

int dizi(int x, int k) {
	for (int i=0; i<L; i++)
		if (k & (1 << i))
			x = p[x][i];
	return x;
}

int lca(int x, int y) {
	if (dub[x] > dub[y])
		swap(x, y);
	y = dizi(y, dub[y] - dub[x]);
	if (x == y)
		return x;
	for (int i=L-1; i>=0; i--) {
		int xx = p[x][i];
		int yy = p[y][i];
		if (xx != yy) {
			x = xx;
			y = yy;
		}
	}
	return p[x][0];
}

int vr[H][L];

void postavi(int x, int k, int z) {
	for (int i=0; i<L; i++) {
		if (k & (1 << i)) {
			vr[x][i] = min(vr[x][i], z);
			x = p[x][i];
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> k >> m;
	for (int i=0; i<k; i++)
		cin >> u1[i] >> v1[i];
	for (int i=0; i<m; i++)
		cin >> u2[i] >> v2[i] >> w2[i];
	
	dsu ds(n+1);
	for (int i=0; i<k; i++) {
		int x = u1[i], y = v1[i];
		ds.spoji(x, y);
		e[x] += y;
		e[y] += x;
	}

	for (int i=0; i<m; i++) {
		int x = u2[i], y = v2[i];
		if (ds.spoji(x, y)) {
			e[x] += y;
			e[y] += x;
		} else {
			radi[i] = 1;
		}
	}

	for (int i=1; i<=n; i++) {
		if (!p[i][0]) {
			dfs(i, i);
		}
	}

	memset(vr, 63, sizeof vr);

	for (int i=0; i<m; i++) {
		if (!radi[i])
			continue;

		int x = u2[i], y = v2[i], w = w2[i];
		int z = lca(x, y);

		postavi(x, dub[x] - dub[z], w);
		postavi(y, dub[y] - dub[z], w);
	}

	for (int i=L-1; i>0; i--) {
		for (int x=1; x<=n; x++) {
			int y = p[x][i-1];
			vr[x][i-1] = min(vr[x][i-1], vr[x][i]);
			vr[y][i-1] = min(vr[y][i-1], vr[x][i]);
		}
	}

	map<pair<int, int>, int> wt;
	for (int i=1; i<=n; i++) {
		int j = p[i][0];
		if (i != j) {
			wt[{min(i, j), max(i, j)}] = vr[i][0];
		}
	}

	ll sol = 0;

	for (int i=0; i<k; i++) {
		int x = min(u1[i], v1[i]);
		int y = max(u1[i], v1[i]);
		int z = wt[{x, y}];
		if (z > 1002003004) {
			cout << "-1\n";
			return 0;
		}
		sol += z;
	}

	cout << sol << '\n';
}
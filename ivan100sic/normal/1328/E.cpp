// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, q;
basic_string<int> e[200005];

namespace lca {
	const int MAX_LOG = 19;
	const int MAX_N = 200005;

	int p[MAX_LOG][MAX_N];
	int dub[MAX_N];
	int sz[MAX_N], l[MAX_N], r[MAX_N], lrt;
	int flat[2*MAX_N];

	void dfs(int x, int par) {
		p[0][x] = par;
		for (int i=1; i<MAX_LOG; i++) {
			p[i][x] = p[i-1][p[i-1][x]];
		}

		sz[x] = 1;
		l[x] = ++lrt;
		flat[lrt] = x;

		for (int y : e[x]) {
			if (y != par) {
				dub[y] = dub[x] + 1;
				dfs(y, x);
				sz[x] += sz[y];
			}
		}

		r[x] = ++lrt;
		flat[lrt] = x;
	}

	int dizi(int x, int v) {
		for (int i=0; i<MAX_LOG; i++) {
			if (v & (1 << i)) {
				x = p[i][x];
			}
		}
		return x;
	}

	bool ispod(int a, int b) {
		return l[b] < l[a] && r[a] < r[b];
	}

	int lca(int a, int b) {
		if (dub[a] > dub[b]) {
			a = dizi(a, dub[a] - dub[b]);
		}
		if (dub[b] > dub[a]) {
			b = dizi(b, dub[b] - dub[a]);
		}

		if (a == b) {
			return a;
		}

		for (int i=MAX_LOG-1; i>=0; i--) {
			int aa = p[i][a];
			int bb = p[i][b];

			if (aa != bb) {
				a = aa;
				b = bb;
			}
		}

		return p[0][a];
	}

	int dist(int a, int b) {
		int c = lca(a, b);
		return dub[a] + dub[b] - 2*dub[c];
	}

	bool kolinear(int a, int b, int c) {
		return dist(a, b) + dist(b, c) == dist(a, c);
	}

	int kth(int a, int b, int k) {
		int c = lca(a, b);
		if (k <= dub[a] - dub[c]) {
			return dizi(a, k);
		} else {
			return dizi(b, (dub[a] + dub[b] - 2*dub[c]) - k);
		}
	}
}

using namespace lca;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}

	dfs(1, 1);

	while (q--) {
		int k;
		cin >> k;
		vector<int> a(k);
		for (int& x : a)
			cin >> x;
		int y = a[0];
		for (int x : a)
			if (dub[x] > dub[y])
				y = x;
		bool ok = true;
		for (int x : a) {
			int z = lca::lca(x, y);
			if (z != x && z != p[0][x])
				ok = false;
		}
		cout << (ok ? "YES\n" : "NO\n");
	}
}

// I will still practice daily...
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[500005];
int a[500005];
ll best[500005];
bool blok[500005];
int sz[500005];

int sz_dfs(int x, int p) {
	sz[x] = 1;
	for (int y : e[x]) {
		if (y != p && !blok[y]) {
			sz[x] += sz_dfs(y, x);
		}
	}
	return sz[x];
}

void centroid(int x, int p, int tree_sz, int& idx, int& val) {
	int mx = 0;
	for (int y : e[x]) {
		if (y != p && !blok[y]) {
			centroid(y, x, tree_sz, idx, val);
			mx = max(mx, sz[y]);
		}
	}
	mx = max(mx, tree_sz - sz[x]);
	if (mx < val) {
		val = mx;
		idx = x;
	}
}

void enumerate(int x, int p, basic_string<int>& wt, int dub) {
	wt[dub] = min(wt[dub], a[x]);
	for (int y : e[x]) {
		if (y != p && !blok[y]) {
			enumerate(y, x, wt, dub+1);
		}
	}
}

void accept(int x, int p, basic_string<int>& wt, int dub) {
	for (int y : e[x]) {
		if (y != p && !blok[y]) {
			accept(y, x, wt, dub+1);
		}
	}
	int rlast = -1;
	for (int l=0; l<21; l++) {
		int r = min((int)wt.size()-1, (1<<l)-dub);
		if (r < 0)
			continue;
		if (wt[r] >= a[x])
			continue;
		if (r == rlast)
			break;
		rlast = r;
		best[x] = min(best[x], wt[r] * (l+1ll));
	}
}

void resi(int x) {
	int sz = sz_dfs(x, x);
	int val = sz + 1;
	centroid(x, x, sz, x, val);
	basic_string<int> wt(sz, 1123123123);
	enumerate(x, x, wt, 0);
	// prefix min
	for (int i=0; i<sz-1; i++)
		wt[i+1] = min(wt[i], wt[i+1]);
	accept(x, x, wt, 0);
	blok[x] = true;
	for (int y : e[x])
		if (!blok[y])
			resi(y);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	fill(best+1, best+n+1, 123123123123123123ll);
	resi(1);

	ll sol = 0;

	for (int i=1; i<=n; i++) {
		if (best[i] != 123123123123123123ll) {
			sol += best[i];
			sol += a[i];
		}
	}

	cout << sol << '\n';
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct edge {
	int u, v, w;
};

struct minisegtree {
	basic_string<int> keys;
	basic_string<int> a;
	int n;

	minisegtree() {}

	minisegtree(basic_string<int> v) {
		sort(v.begin(), v.end());
		v.erase(unique(v.begin(), v.end()), v.end());
		keys = v;
		n = 1;
		while (n < (int)keys.size())
			n <<= 1;
		a.assign(2*n, 0);
	}

	void set(int x, int y) {
		x = lower_bound(keys.begin(), keys.end(), x) - keys.begin() + n;
		a[x] = y;
		while (x > 1) {
			x >>= 1;
			a[x] = max(a[2*x], a[2*x+1]);
		}
	}

	int get(int l, int r, int x, int xl, int xr) {
		if (r < xl || xr < l)
			return 0;
		if (l <= xl && xr <= r)
			return a[x];
		int xm = (xl + xr) >> 1;
		return max(get(l, r, 2*x, xl, xm), get(l, r, 2*x+1, xm+1, xr));
	}

	int get(int x) {
		x = upper_bound(keys.begin(), keys.end(), x) - keys.begin();
		return get(x, n-1, 1, 0, n-1);
	}
};

int n, m, sol;
edge a[100005];
int ans[100005];
basic_string<int> ew[100005];
basic_string<int> eu[100005];
minisegtree mst[100005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> a[i].u >> a[i].v >> a[i].w;
		ew[a[i].w] += i;
		eu[a[i].u] += i;
	}

	for (int i=1; i<=n; i++) {
		mst[i] = minisegtree(eu[i]);
	}

	for (int w=100000; w>=0; w--) {
		for (int j : ew[w]) {
			int v = a[j].v;
			ans[j] = mst[v].get(j) + 1;
			sol = max(sol, ans[j]);
		}
		for (int j : ew[w]) {
			int u = a[j].u;
			mst[u].set(j, ans[j]);
		}
	}

	cout << sol << '\n';
}
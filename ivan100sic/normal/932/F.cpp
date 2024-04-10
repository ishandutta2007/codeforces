#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int global_ts = 1;

struct line {
	ll k, b; int ts;

	line() : ts(0) {}

	line(ll k, ll b, int ts) : k(k), b(b), ts(ts) {}

	ll operator* (ll x) const {
		if (ts != global_ts)
			return 4e18;
		return k*x + b;
	}
};

const int maxn = 262144;
const int lo = -100005;
const int hi = lo + maxn - 1;

struct lichao {
	vector<line> a;

	lichao() : a(2*maxn) {}

	void add(line t, int x=1, int xl=lo, int xr=hi) {
		if (t*xl >= a[x]*xl && t*xr >= a[x]*xr)
			return;
		if (t*xl <= a[x]*xl && t*xr <= a[x]*xr) {
			a[x] = t;
			return;
		}
		if (t*xl < a[x]*xl)
			swap(t, a[x]);
		int xm = (xl+xr) / 2;
		add(t, 2*x, xl, xm);
		add(t, 2*x+1, xm+1, xr);
	}

	ll operator* (int p) {
		ll z = 4e18;
		for (int x=p+maxn-lo; x; x>>=1)
			z = min(z, a[x]*p);
		return z;
	}
} lc;

int n;
basic_string<int> e[100005], f[100005];
int a[100005], b[100005], h[100005];
ll dp[100005];

int dfs1(int x, int p) {
	h[x] = -1;
	int s = 1, z = -1;
	for (int y : e[x]) {
		if (y == p)
			continue;
		f[x] += y;
		int t = dfs1(y, x);
		s += t;
		if (t > z) {
			z = t;
			h[x] = y;
		}
	}
	return s;
}

void dfs4(int x, vector<int>& v) {
	v.push_back(x);
	for (int y : f[x])
		dfs4(y, v);
}

void dfs3(int x) {
	if (h[x] != -1)
		dfs3(h[x]);

	vector<int> v;
	for (int y : f[x])
		if (y != h[x])
			dfs4(y, v);

	for (int y : v) {
		// cerr << "add " << y << ' ' << dp[y] << ' ' << b[y] << '\n';
		lc.add(line(b[y], dp[y], global_ts));
	}
	dp[x] = lc * a[x];
	if (f[x].size() == 0)
		dp[x] = 0;
	lc.add(line(b[x], dp[x], global_ts));
	// cerr << "solved " << x << ' ' << dp[x] << '\n';
}

void dfs2(int x) {
	for (int y=x; y!=-1; y=h[y])
		for (int z : f[y])
			if (z != h[y])
				dfs2(z);

	global_ts++;
	dfs3(x);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> a[i];
	for (int i=1; i<=n; i++)
		cin >> b[i];
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}
	dfs1(1, 1);
	dfs2(1);
	for (int i=1; i<=n; i++)
		cout << dp[i] << " \n"[i == n];
}
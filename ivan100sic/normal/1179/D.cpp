#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

typedef long long lichao_t;

struct line {
	lichao_t k, b;

	line() : k(0), b(1e18) {}

	line(lichao_t k, lichao_t b) : k(k), b(b) {}

	// hahahahahahahahahah linear operators
	lichao_t operator* (lichao_t x) const {
		return k*x + b;
	}
};

const int SIZE = 1 << 20;

struct lichao {
	line a[2*SIZE];
	basic_string<int> dirty;

	void clear() {
		for (int x : dirty)
			a[x] = line();
		dirty.clear();
	}

	void add(line p, int x=1, int lx=0, int rx=SIZE-1) {
		// prava a je svakako bolja od prave p svuda
		if (a[x]*lx <= p*lx && a[x]*rx <= p*rx)
			return;

		// prava p je bolja od a svuda
		if (p*lx <= a[x]*lx && p*rx <= a[x]*rx) {
			dirty += x;
			a[x] = p;
			return;
		}

		int mx = (lx + rx) >> 1;

		if (p*lx < a[x]*lx) {
			dirty += x;
			swap(p, a[x]);
		}

		add(p, 2*x, lx, mx);
		add(p, 2*x+1, mx+1, rx);
	}

	lichao_t get(int p, int x=1, int lx=0, int rx=SIZE-1) const {
		if (p < lx || p > rx)
			return 9023123123123123123l;
		lichao_t ans = a[x]*p;
		if (x >= SIZE)
			return ans;

		int mx = (lx + rx) >> 1;
		return min({ans, get(p, 2*x, lx, mx), get(p, 2*x+1, mx+1, rx)});
	}

	lichao_t operator* (lichao_t x) const {
		return get(x);
	}
} drvo;

int n;
basic_string<int> e[500005];
int sz[500005];
ll dp[500005], sol;

void dfs0(int x, int p) {
	sz[x] = 1;
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs0(y, x);
		sz[x] += sz[y];
	}
}

ll tro(int x) {
	return (x * (x-1ll)) >> 1;
}

void dfs1(int x, int p) {
	// singl
	dp[x] = tro(sz[x]);
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs1(y, x);
		dp[x] = min(dp[x], dp[y] + tro(sz[x] - sz[y]));
	}

	drvo.clear();
	for (int y : e[x]) {
		if (y == p)
			continue;
		sol = min(sol, dp[y] + tro(n - sz[y]));
		sol = min(sol, dp[y] + ((drvo.get(sz[y]) + sz[y]*1ll*sz[y]) >> 1));
		drvo.add(line(1-2*n+2*sz[y], 2*dp[y] + (n-sz[y])*(n-sz[y]-1ll)));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	sol = 1e18;
	for (int i=1; i<n; i++) {
		int x, y;
		cin >> x >> y;
		e[x] += y;
		e[y] += x;
	}

	dfs0(1, 1);
	dfs1(1, 1);
	cout << n*(n-1ll) - sol << '\n';
}
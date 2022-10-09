#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<int> e[100005], f;
basic_string<pair<int, int>> g;
bool vis[100005];

void dfs(int x, int& z) {
	z++;
	vis[x] = 1;
	for (int y : e[x])
		if (!vis[y])
			dfs(y, z);
}

int dp[100005];
int tmp[100005];

struct minqueue {
	basic_string<pair<int, int>> p, q;

	void push(int x) {
		q += {x, q.size() ? min(x, q.back().second) : x};
	}

	void transfer() {
		p = move(q); q = {};
		reverse(p.begin(), p.end());
		int t = 1123123123;
		for (auto& [x, y] : p) {
			t = min(t, x);
			y = t;
		}
	}

	void pop() {
		if (!p.size())
			transfer();
		p.pop_back();
	}

	int get() {
		int z = 1123123123;
		if (p.size())
			z = min(z, p.back().second);
		if (q.size())
			z = min(z, q.back().second);
		return z;
	}
};

void dpadd(int x, int y) {
	// cerr << "dpadd " << x << ' ' << y << '\n';
	memset(tmp, 63, sizeof(tmp));
	for (int rem=0; rem<x; rem++) {
		minqueue offers;
		for (int i=rem; i<100005; i+=x) {
			offers.push(dp[i] - i/x);
			tmp[i] = min(tmp[i], offers.get() + i/x);
			if (i-x*y >= 0)
				offers.pop();
		}
	}
	copy(tmp, tmp+100005, dp);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}
	for (int i=1; i<=n; i++) {
		if (!vis[i]) {
			int z = 0;
			dfs(i, z);
			f += z;
		}
	}
	sort(f.begin(), f.end());
	for (int x : f) {
		if (g.size() && g.back().first == x)
			g.back().second++;
		else
			g += {x, 1};
	}
	memset(dp, 63, sizeof(dp));
	dp[0] = 0;
	for (auto [x, y] : g)
		dpadd(x, y);
	int sol = 123123123;
	for (int len=1; len<=5; len++) {
		for (int mask=0; mask<(1<<len); mask++) {
			int z = 0;
			for (int i=0; i<len; i++)
				z = 10 * z + (mask & (1 << i) ? 4 : 7);
			sol = min(sol, dp[z] - 1);
		}
	}
	if (sol > 123123)
		sol = -1;
	cout << sol << '\n';
}
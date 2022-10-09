#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, s, t, ds, dt, rs, rt;
basic_string<pair<int, int>> sol;
basic_string<int> e[200005];

bool ok() {
	int ds = ::ds;
	int dt = ::dt;
	for (auto [x, y] : sol) {
		if (x == s || y == s) ds--;
		if (x == t || y == t) dt--;
	}
	return ds >= 0 && dt >= 0 && (int)sol.size() == n-1;
}

void no() {
	cout << "No\n";
	exit(0);
}

bool vis[200005];

void dfs(int x) {
	vis[x] = 1;
	for (int y : e[x]) {
		if (!vis[y]) {
			if ((x == s || y == s) && rs == 0)
				continue;
			if ((x == t || y == t) && rt == 0)
				continue;
			
			if (x == s || y == s)
				rs--;
			if (x == t || y == t)
				rt--;
			
			sol += {x, y};
			dfs(y);
		}
	}
}

int p[200005];

int ep(int x) {
	if (x == p[x])
		return x;
	return p[x] = ep(p[x]);
}

bool spoji(int x, int y) {
	x = ep(x);
	y = ep(y);
	if (x == y)
		return false;
	p[x] = y;
	return true;
}

void run() {
	iota(p, p+200005, 0);
	sol = {};
	rs = ds;
	rt = dt;
	vis[s] = vis[t] = 1;
	dfs(s);
	dfs(t);

	// dodaj greedy granu koja fali eventualno
	for (auto [x, y] : sol) {
		// cerr << "inicijalno: " << x << ' ' << y << '\n';
		spoji(x, y);
	}
	for (int x=1; x<=n; x++) {
		for (int y : e[x]) {
			if ((x == s || y == s) && (rs <= 0))
				continue;
			if ((x == t || y == t) && (rt <= 0))
				continue;
			if (spoji(x, y)) {
				// cerr << "dodatno: " << x << ' ' << y << '\n';
				if (x == s || y == s)
					rs--;
				if (x == t || y == t)
					rt--;
				sol += {x, y};
			}
		}
	}

	if (!ok())
		return;

	cout << "Yes\n";
	for (auto [x, y] : sol)
		cout << x << ' ' << y << '\n';
	exit(0);
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
	cin >> s >> t >> ds >> dt;

	run();

	swap(ds, dt);
	swap(s, t);

	run();
	
	no();	
}
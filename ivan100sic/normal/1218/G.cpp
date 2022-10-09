#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

mt19937 eng;

int n, m;
string s;
basic_string<int> e[100005];
int sm[100005], mp[3];

vector<array<int, 3>> sol;
bool st[100005], vis[100005];

int dopuna(int x) {
	x %= 3;
	if (x < 0)
		x += 3;
	return 3-x;
}

void dfs(int x, int par) {
	st[x] = vis[x] = 1;
	for (int y : e[x]) {
		if (y == par)
			continue;
		if (!vis[y]) {
			dfs(y, x);
			int t = dopuna(sm[y] - mp[s[y]-'X']);
			sol.push_back({x, y, t});
			sm[x] += t;
			sm[y] += t;
		} else if (st[y]) {
			sm[x] += 3;
			sm[y] += 3;
			sol.push_back({x, y, 3});
		}
	}
	st[x] = 0;
}

bool probaj() {
	iota(mp, mp+3, 0);
	for (int i=0; i<n; i++)
		shuffle(e[i].begin(), e[i].end(), eng);
	shuffle(mp, mp+3, eng);
	fill(sm, sm+n, 0);
	fill(vis, vis+n, 0);
	int x = uniform_int_distribution<int>(0, n-1)(eng);
	sol = {};
	dfs(x, x);
	for (int i=0; i<n; i++)
		for (int j : e[i])
			if (sm[i] == sm[j])
				return false;
	for (auto a : sol)
		cout << a[0] << ' ' << a[1] << ' ' << a[2] << '\n';
	return true;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> s;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	while (!probaj());
}
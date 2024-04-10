#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

#define forn(i, a, n) for (int i = a; i < n; ++i)
#define fore(i, a, n) for (int i = a; i <= n; ++i)
#define all(a) (a).begin(), (a).end()
#define fs first
#define sn second
#define trace(a)\
	for (auto i : a) cerr << i << ' ';\
	cerr << '\n'
#define pb push_back

#ifndef M_PI
const ld M_PI = 3.1415926535897932384626433;
#endif
const ld eps = 1e-8;

vector<vector<pair<int, int> > > edges;

vector<int> day, used;

void dfs(int u) {
	if (used[u]) return;
	used[u] = true;
	set<int> nears;
	for (auto p : edges[u])
		if (day[p.sn] != -1)
			nears.insert(day[p.sn]);
	for (int i = 0, j = 0;; ++i)
		if (nears.find(i) == nears.end()) {
			while (j < edges[u].size() && day[edges[u][j].sn] != -1) ++j;
			if (j == edges[u].size()) {
				for (auto p : edges[u]) dfs(p.fs);
				return;
			}
			day[edges[u][j].sn] = i;
			++j;
		}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	edges.resize(n);
	forn(i, 0, n - 1) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		edges[u].pb({v, i});
		edges[v].pb({u, i});
	}
	day.resize(n - 1, -1);
	used.resize(n, 0);
	dfs(0);
	int mday = 0;
	forn(i, 0, n - 1) mday = max(mday, day[i]);
	cout << mday + 1 << '\n';
	vector<vector<int> > ans(mday + 1);
	forn(i, 0, n - 1) ans[day[i]].pb(i);
	forn(i, 0, mday + 1) {
		cout << ans[i].size() << ' ';
		for (auto j : ans[i]) cout << j + 1 << ' ';
		cout << '\n';
	}
	return 0;
}
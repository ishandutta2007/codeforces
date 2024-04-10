#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
set<int> bad[300005], sus1, unvis;

void dfs(int x) {
	unvis.erase(x);
	int adj = 0;
	while (1) {
		auto it = unvis.upper_bound(adj);
		if (it == unvis.end())
			break;
		adj = *it;
		if (bad[x].count(adj))
			continue;
		dfs(adj);
		if (x == 1)
			sus1.insert(adj);
	}
}

void die(string s) {
	cout << s << "possible\n";
	exit(0);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		bad[u].insert(v);
		bad[v].insert(u);
	}

	for (int i=1; i<=n; i++)
		unvis.insert(i);

	dfs(1);
	if (unvis.size())
		die("im");
	int lo = sus1.size();
	int hi = n - 1 - bad[1].size();
	if (k < lo || k > hi)
		die("im");
	die("");
}
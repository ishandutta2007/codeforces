#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

set<int> unvis, e[100005];
int n, m;

void dfs(int x) {
	int y = 0;
	while (1) {
		auto it = unvis.upper_bound(y);
		if (it == unvis.end())
			break;
		y = *it;
		if (!e[x].count(y)) {
			unvis.erase(y);
			dfs(y);
		}
	}
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
		e[u].insert(v);
		e[v].insert(u);
	}

	for (int i=1; i<=n; i++)
		unvis.insert(i);

	int z = 0;

	for (int i=1; i<=n; i++) {
		if (unvis.count(i)) {
			z++;
			unvis.erase(i);
			dfs(i);
		}
	}

	cout << z-1 << '\n';
}
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[6005], n;
basic_string<int> e[6005];

int d[6005], sol;

void dfs(int x, int p) {
	auto it = lower_bound(d, d+6005, a[x]);
	sol = max(sol, (int)(it - d));
	int old = *it;
	*it = min(*it, a[x]);
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs(y, x);
	}
	*it = old;
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

	memset(d, 63, sizeof d);
	d[0] = 0;
	for (int i=1; i<=n; i++) 
		dfs(i, i);
	cout << sol << '\n';
}
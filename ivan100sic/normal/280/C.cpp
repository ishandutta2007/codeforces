#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[100005];
int d[100005];

void dfs(int x, int p) {
	for (int y : e[x]) {
		if (y == p)
			continue;
		d[y] = d[x]+1;
		dfs(y, x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	d[1] = 1;
	dfs(1, 1);
	ld sol = 0;
	for (int i=1; i<=n; i++)
		sol += 1.0 / d[i];

	cout << setprecision(20) << fixed << sol << '\n';
}
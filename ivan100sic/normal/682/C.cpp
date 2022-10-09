#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, sol;
int a[100005];
basic_string<pair<int, int>> e[100005];

void dfs(int x, int p, ll d) {
	if (d > a[x]) {
		sol++;
		d = 1e18;
	}

	for (auto ee : e[x]) {
		int y = ee.first;
		int w = ee.second;
		if (y == p)
			continue;
		dfs(y, x, max(0ll, d + w));
	}
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
		int u, v, c;
		u = i+1;
		cin >> v >> c;
		e[u] += {v, c};
		e[v] += {u, c};
	}

	dfs(1, 1, 0);
	cout << sol << '\n';
}
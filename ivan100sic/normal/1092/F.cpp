#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<int> e[200005];
ll a[200005], s[200005], d[200005];

void dfs1(int x, int p) {
	for (int y : e[x]) {
		if (y == p)
			continue;
		d[y] = d[x] + 1;
		dfs1(y, x);
		s[x] += s[y];
	}
	s[x] += a[x];
}

ll sol = 0;

void dfs2(int x, int p, ll z) {
	sol = max(sol, z);
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs2(y, x, z - s[y] + (s[1] - s[y]));
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
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}
	dfs1(1, 1);
	dfs2(1, 1, inner_product(d+1, d+n+1, a+1, 0ll));
	cout << sol << '\n';
}
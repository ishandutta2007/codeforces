#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
basic_string<int> e[300005], a[300005];
int c[300005];

void dfs(int x, int p) {
	set<int> forb;
	for (int y : a[x]) {
		if (c[y]) {
			forb.insert(c[y]);
		}
	}
	int t = 1;
	for (int y : a[x]) {
		if (!c[y]) {
			while (forb.count(t))
				t++;
			c[y] = t++;
		}
	}
	for (int y : e[x]) {
		if (y == p)
			continue;
		dfs(y, x);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=n; i++) {
		int k;
		cin >> k;
		::k = max(::k, k);
		while (k--) {
			int x;
			cin >> x;
			a[i] += x;
		}
	}

	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		e[u] += v;
		e[v] += u;
	}

	dfs(1, 1);
	cout << max(1, k) << '\n';
	for (int i=1; i<=m; i++)
		cout << max(1, c[i]) << " \n"[i == m];
}
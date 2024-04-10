// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
vector<basic_string<int>> e;
vector<int> a, d;

void dfs(int x, int p, int w=0) {
	w += a[x];
	d[x] = w;
	for (int y : e[x]) {
		if (y == p) {
			continue;
		}
		dfs(y, x, w);
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int q;
	cin >> q;
	while (q--) {
		cin >> n;
		e.assign(n, {});
		for (int i=1; i<n; i++) {
			int u, v;
			cin >> u >> v;
			u--, v--;
			e[u] += v;
			e[v] += u;
		}

		a.assign(n, 0);
		for (int i=0; i<n; i++)
			a[i] = e[i].size() - 1;

		d.assign(n, 0);
		dfs(0, 0);
		int r = max_element(begin(d), end(d)) - begin(d);
		dfs(r, r);
		cout << *max_element(begin(d), end(d)) + 2 << '\n';
	}
}
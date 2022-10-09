#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int d[200005], g[200005], z[200005], t;
int n;
vector<int> e[200005];

void dfs(int x) {
	z[x] = 1;
	t++;
	d[t] = x;
	g[x] = t;
	for (int y : e[x]) {
		dfs(y);
		z[x] += z[y];
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> n >> q;
	for (int i=2; i<=n; i++) {
		int x;
		cin >> x;
		e[x].push_back(i);
	}
	dfs(1);
	while (q--) {
		int u, k, r = -1;
		cin >> u >> k;
		if (k <= z[u])
			r = d[g[u] + k - 1];
		cout << r << '\n';
	}
}
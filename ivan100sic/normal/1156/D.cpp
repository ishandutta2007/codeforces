#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<pair<int, int>> e[200005];
ll p0[200005], p1[200005], p01[200005], p10[200005];
ll sol;

void dfs(int x, int p) {
	for (auto [y, w] : e[x]) {
		if (y == p)
			continue;
		dfs(y, x);

		if (w == 0) {
			sol += 2; // samo do y
			sol += 2 * p0[y]; // ispod y, samo 0 grane (dva smera)
			sol += p01[y]; // ispod y, 0 pa 1 grane
			sol += p1[y]; // ispod y, prvo 0 do y pa dalje 1 grane

			sol += p0[x] * (p0[y]*2 + 2 + p01[y] + p1[y]);
			sol += p1[x] * (1 + p0[y]);
			sol += p01[x] * (1 + p0[y]);
			
			p0[x] += p0[y] + 1;
			p01[x] += p01[y] + p1[y];
		} else {
			sol += 2;
			sol += 2 * p1[y];
			sol += p10[y];
			sol += p0[y];

			sol += p1[x] * (p1[y]*2 + 2 + p10[y] + p0[y]);
			sol += p0[x] * (1 + p1[y]);
			sol += p10[x] * (1 + p1[y]);

			p1[x] += p1[y] + 1;
			p10[x] += p10[y] + p0[y];
		}
	}

	// cerr << "leaving " << x << ' ' << sol << '\n';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u] += {v, w};
		e[v] += {u, w};
	}

	dfs(1, 1);
	cout << sol << '\n';

	for (int i=1; i<=n; i++) {
		// cerr << i << ": " << p0[i] << ' ' << p1[i] << ' ' << p01[i] << ' ';
		// cerr << p10[i] << '\n';
	}
}
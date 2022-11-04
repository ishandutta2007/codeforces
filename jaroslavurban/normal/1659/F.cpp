#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

void ProGamerMove() {
	int n, x; cin >> n >> x, --x;
	vector<int> deg(n), p(n);
	for (int u, v, i = 0; i < n - 1; ++i) {
		cin >> u >> v, --u, --v;
		++deg[u], ++deg[v];
	}
	for (int& v : p) cin >> v, --v;
	bool sorted = true;
	for (int i = 0; i < n; ++i) if (p[i] != i) sorted = false;
	int bd = -1;
	for (int i = 0; i < n; ++i) if (deg[i] == n - 1) bd = i;
	if (!sorted && ~bd) {
		vector<int> vis(n);
		int par = 0;
		for (int i = 0; i < n; ++i) if (p[i] != i && !vis[i]) {
			int u = i;
			while (p[u] != i) vis[u] = true, ++par, u = p[u];
			vis[u] = true;
		}
		if ((x != bd && (p[bd] == x || (p[bd] == bd && n <= 3))) || (x == bd && p[bd] != bd)) cout << "Bob\n";
		else {
			par = x == bd ? par : (par == 1 && p[x] != x ? par + 1 : par - 1);
			if (!par || (par & 1)) cout << "Alice\n";
			else cout << "Bob\n";
		}
	} else cout << "Alice\n";
}

signed main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	cout << setprecision(9) << fixed;
	int tc = 1;
	cin >> tc;
	while (tc--) ProGamerMove();
}
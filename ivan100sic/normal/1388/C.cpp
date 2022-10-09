// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
ll p[100005], pt[100005];
ll h[100005], m, srecni[100005], tuzni[100005];
basic_string<int> e[100005];
bool ok;

void dfs(int x, int par) {
	pt[x] = p[x];
	for (int y : e[x]) {
		if (y == par) continue;
		dfs(y, x);
		pt[x] += pt[y];
	}

	srecni[x] = (h[x] + pt[x]) / 2;
	if ((h[x] + pt[x]) % 2) {
		ok = false;
	}
	tuzni[x] = pt[x] - srecni[x];

	if (srecni[x] < 0 || tuzni[x] < 0) {
		ok = false;
	}

	// proverimo samo da se nije povecao broj srecnih
	ll ch = srecni[x];
	for (int y : e[x]) {
		if (y == par) continue;
		ch -= srecni[y];
	}

	if (ch < 0) {
		ok = false;
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=1; i<=n; i++) {
			cin >> p[i];
			e[i] = {};
		}
		for (int i=1; i<=n; i++) {
			cin >> h[i];
		}
		for (int i=1; i<n; i++) {
			int u, v;
			cin >> u >> v;
			e[u] += v;
			e[v] += u;
		}
		ok = true;
		dfs(1, 0);
		cout << (ok ? "YES\n" : "NO\n");
	}

}
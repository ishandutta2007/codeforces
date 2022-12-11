#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef long double ld;

vector<vector<int> > g;
vector<int> c;

bool dfs(int v, int color, int p)
{
	if (c[v] != color) {
		return false;
	}
	for (int to : g[v]) {
		if (to != p && !dfs(to, color, v)) {
			return false;
		}
	}
	return true;
}

bool ok(int v)
{
	for (int to : g[v]) {
		if (!dfs(to, c[to], v)) {
			return false;
		}
	}
	return true;
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("wa");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	g.resize(n);
	c.resize(n);

	for (int i = 0; i < n - 1; ++i) {
		int u,v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	bool bad = false;
	int ans = -1;

	for (int i = 0; i < n; ++i) {
		for (int to : g[i]) {
			if (c[i] != c[to]) {
				bad = true;
				if (ok(i)) {
					ans = i;
				} else if (ok(to)) {
					ans = to;
				}
				break;
			}
		}
		if (bad) {
			break;
		}
	}

	if (!bad) {
		cout << "YES\n";
		cout << "1\n";
		return 0;
	}

	if (ans == -1) {
		cout << "NO\n";
	} else {
		cout << "YES\n";
		cout << ans + 1 << "\n";
	}

}
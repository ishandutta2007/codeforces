#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;

vector<vector<int> > g;
vector<ld> dp;

void dfs(int v, int p) {
	if (g[v].empty()) {
		dp[v] = 0;
		return;
	}
	if (sz(g[v]) == 1 && g[v][0] == p) {
		dp[v] = 0;
		return;
	}
	int cnt = 0;
	dp[v] = 0;
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		dfs(to, v);
		dp[v] += dp[to] + 1;
		++cnt;
	}
	dp[v] /= cnt;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);
	//ofstream cout("output.txt");

	int n;
	cin >> n;
	g.resize(n);
	dp.resize(n);

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}

	dfs(0, 0);

	cout << fixed;
	cout.precision(12);
	cout << dp[0] << "\n";

}
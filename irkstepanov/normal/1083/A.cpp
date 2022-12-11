#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;

struct edge {
	int from, to;
	ll cost;
};

vector<ll> w;
vector<vector<edge> > g;

vector<ll> dp;

const ll inf = 1e18;

ll ans = -inf;

void dfs(int v, int p) {
	dp[v] = w[v];
	ll maxx1 = -inf, maxx2 = -inf;
	for (edge& e : g[v]) {
		if (e.to == p) {
			continue;
		}
		dfs(e.to, v);
		ll val = dp[e.to] - e.cost;
		dp[v] = max(dp[v], w[v] + val);
		if (val > maxx1) {
			maxx2 = maxx1;
			maxx1 = val;
		} else if (val > maxx2) {
			maxx2 = val;
		}
	}
	ans = max(ans, w[v] + maxx1 + maxx2);
	//dp[v] = max(dp[v], w[v] + maxx1 + maxx2);
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	w.resize(n);
	for (int i = 0; i < n; ++i) {
		cin >> w[i];
	}

	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		ll c;
		cin >> u >> v >> c;
		--u, --v;
		g[u].pb({u, v, c});
		g[v].pb({v, u, c});
	}

	dp.resize(n);
	dfs(0, 0);

	for (int i = 0; i < n; ++i) {
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";
	
}
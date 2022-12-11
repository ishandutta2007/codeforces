#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef double ld;
typedef pair<ll, ll> pll;

vector<vector<int> > g;
vector<char> used;

int dfs(int v)
{
	used[v] = true;
	int ans = 1;
	for (int to : g[v]) {
		if (!used[to]) {
			ans += dfs(to);
		}
	}
	return ans;
}

int main()
{

	//ifstream cin("strictly-off.in");
	//ofstream cout("strictly-off.out");
	//freopen("input.txt", "r", stdin);
	//freopen("threed.out", "w", stdout);
	//ifstream cin("input.txt");
	//ofstream cout("output.txt");

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;
	g.resize(n);
	used.assign(n, false);

	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}

	ll must = 0;

	for (int i = 0; i < n; ++i) {
		if (!used[i]) {
			int x = dfs(i);
			must += ll(x) * ll(x - 1) / 2;
		}
	}

	cout << (must == m ? "YES\n" : "NO\n");

}
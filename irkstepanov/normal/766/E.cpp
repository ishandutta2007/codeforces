#include <bits/stdc++.h>

#define sz(a) (int)(a).size()
#define pb push_back
#define all(a) (a).begin(), (a).end()

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

bool bit(int mask, int pos)
{
	return (mask >> pos) & 1;
}

const int kmax = 23; // TODO

int n;
vector<vector<int> > g;
vector<int> val;
vector<ll> dp0, dp1;
ll ans;

void dfs(int v, int p)
{
	if (sz(g[v]) == 1 && g[v][0] == p) {
		if (val[v]) {
			dp1[v] = 1;
		} else {
			dp0[v] = 1;
		}
		return;
	}
	for (int to : g[v]) {
		if (to != p) {
			dfs(to, v);
			dp0[v] += dp0[to];
			dp1[v] += dp1[to];
		}
	}
	for (int to : g[v]) {
		if (to != p) {
			if (!val[v]) {
				ans += dp0[to] * (dp1[v] - dp1[to]);
				ans += dp1[to] * (dp0[v] - dp0[to]);
			} else {
				ans += dp0[to] * (dp0[v] - dp0[to]);
				ans += dp1[to] * (dp1[v] - dp1[to]);
			}
		}
	}
	if (val[v]) {
		swap(dp0[v], dp1[v]);
	}
	ans += ll(2) * dp1[v];
	if (val[v]) {
		++dp1[v];
	} else {
		++dp0[v];
	}
}

int main()
{

	//ifstream cin("input.txt");
	//ofstream cout("wa");

	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;

	g.resize(n);
	val.resize(n);
	vector<int> a(n);

	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}

	if (n == 1) {
		cout << a[0] << "\n";
		return 0;
	}

	ll res = 0;

	for (int k = 0; k < kmax; ++k) {
		for (int i = 0; i < n; ++i) {
			val[i] = bit(a[i], k);
		}
		dp0.assign(n, 0);
		dp1.assign(n, 0);
		ans = 0;
		dfs(0, 0);
		res += ans * (1LL << k);
		/*cout << ans << "\n";
		for (int i = 0; i < n; ++i) {
			cout << dp0[i] << " " << dp1[i] << "\n";
		}
		cout << "\n";*/
	}

	for (int i = 0; i < n; ++i) {
		res += ll(2) * ll(a[i]);
	}
	cout << res / 2 << "\n";

}
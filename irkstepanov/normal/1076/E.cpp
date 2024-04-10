#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ld, ld> pld;
typedef pair<ll, ll> pll;

vector<vector<int> > g;
vector<vector<pll> > vct;
vector<ll> ans;

map<ll, ll> curr;
ll sum = 0;

void dfs(int v, int p, int d) {
	/*cout << "!" << v + 1 << "\n";
	for (auto it : curr) {
		cout << it.first << " " << it.second << "\n";
	}
	cout << "\n";*/
	for (int i = 0; i < sz(vct[v]); ++i) {
		sum += vct[v][i].second;
		curr[d + vct[v][i].first + 1] += vct[v][i].second;
	}
	ll del = 0;
	if (!curr.empty() && curr.begin()->first == d) {
		del = curr.begin()->second;
		curr.erase(curr.begin());
		sum -= del;
	}
	ans[v] = sum;
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		dfs(to, v, d + 1);
	}
	if (del != 0) {
		curr[d] += del;
		sum += del;
	}
	for (int i = 0; i < sz(vct[v]); ++i) {
		sum -= vct[v][i].second;
		curr[d + vct[v][i].first + 1] -= vct[v][i].second;
		if (curr[d + vct[v][i].first + 1] == 0) {
			curr.erase(d + vct[v][i].first + 1);
		}
	}
}

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n;
	cin >> n;

	g.resize(n);
	for (int i = 0; i < n - 1; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(v);
		g[v].pb(u);
	}

	vct.resize(n);
	int q;
	cin >> q;

	while (q--) {
		int v, d;
		ll x;
		cin >> v >> d >> x;
		--v;
		vct[v].pb({d, x});
	}

	ans.resize(n);

	dfs(0, 0, 0);
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";

}
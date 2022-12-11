#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef pair<ld, ld> pld;

struct edge {
	int from, to;
};

vector<edge> edges;
vector<vector<int> > g;
vector<int> parent;
vector<int> p_e;
vector<int> ans;
vector<int> d;

int root;

int dfs(int v) {
	int curr = 0;
	for (int e : g[v]) {
		int to = edges[e].to;
		if (parent[to] != -1) {
			continue;
		}
		parent[to] = v;
		p_e[to] = e;
		//cout << v << " " << to << endl;
		curr ^= dfs(to);
	}
	if (d[v] == -1) {
		return 0;
	}
	if (v == root) {
		assert(curr == d[v]);
		return 0;
	}
	if (curr != d[v]) {
		ans.pb(p_e[v] / 2);
		return 1;
	} else {
		return 0;
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);
	//ofstream cout("output.txt");

	int n, m;
	cin >> n >> m;
	g.resize(n);
	d.resize(n);
	int cnt = 0;
	int cnt_1 = 0;
	for (int i = 0; i < n; ++i) {
		cin >> d[i];
		if (d[i] == 1) {
			++cnt;
		}
		if (d[i] == -1) {
			++cnt_1;
		}
	}

	if ((cnt & 1) && cnt_1 == 0) {
		cout << "-1\n";
		return 0;
	}

	root = 0;
	if (cnt_1) {
		for (int i = 0; i < n; ++i) {
			if (d[i] == -1) {
				root = i;
			}
		}
	}

	while (m--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		g[u].pb(sz(edges));
		edges.pb({u, v});
		g[v].pb(sz(edges));
		edges.pb({v, u});
	}

	parent.assign(n, -1);
	parent[root] = root;
	p_e.resize(n);
	dfs(root);

	cout << sz(ans) << "\n";
	for (int x : ans) {
		cout << x + 1 << "\n";
	}

}
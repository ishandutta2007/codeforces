#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

const int inf = 1e9;

struct edge {
	int from, to;
	bool bridge;
	bool good;
};

vector<edge> edges;
vector<vector<int> > g;

void addEdge(int u, int v) {
	g[u].pb(sz(edges));
	edges.pb({u, v, false, false});
	g[v].pb(sz(edges));
	edges.pb({v, u, false, false});
}

vector<char> used;
vector<int> tin, ret;
int timer;

void dfs1(int v, int p) {
	used[v] = true;
	tin[v] = ret[v] = timer++;
	for (int e : g[v]) {
		int to = edges[e].to;
		if (to == p) {
			continue;
		}
		if (used[to]) {
			ret[v] = min(ret[v], tin[to]);
		} else {
			dfs1(to, v);
			ret[v] = min(ret[v], ret[to]);
			if (tin[v] < ret[to]) {
				edges[e].bridge = edges[e ^ 1].bridge = true;
			}
		}
	}
}

vector<int> compId;
vector<int> compSize;

int dfs2(int v, int cc) {
	compId[v] = cc;
	int ans = 1;
	for (int e : g[v]) {
		if (edges[e].bridge) {
			continue;
		}
		int to = edges[e].to;
		if (compId[to] == -1) {
			ans += dfs2(to, cc);
		}
	}
	return ans;
}

void dfs3(int v, bool rev) {
	used[v] = true;
	for (int e : g[v]) {
		int to = edges[e].to;
		if (!rev) {
			if (used[to]) {
				edges[e].good = false;
				edges[e ^ 1].good = true;
			} else {
				edges[e].good = true;
				edges[e ^ 1].good = false;
				dfs3(to, rev | edges[e].bridge);
			}
		} else {
			if (used[to]) {
				edges[e].good = true;
				edges[e ^ 1].good = false;
			} else {
				edges[e].good = false;
				edges[e ^ 1].good = true;
				dfs3(to, rev);
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");
	//freopen("input.txt", "r", stdin);
	
	int n, m;
	cin >> n >> m;
	g.resize(n);
	
	while (m--) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		addEdge(u, v);
	}

	tin.resize(n);
	ret.resize(n);
	timer = 0;
	used.assign(n, false);
	dfs1(0, 0);

	compId.assign(n, -1);
	int cc = 0;
	for (int i = 0; i < n; ++i) {
		if (compId[i] == -1) {
			compSize.pb(dfs2(i, cc));
			++cc;
		}
	}

	used.assign(n, false);

	int id = 0;
	for (int i = 1; i < cc; ++i) {
		if (compSize[i] > compSize[id]) {
			id = i;
		}
	}

	cout << compSize[id] << "\n";

	for (int i = 0; i < n; ++i) {
		if (compId[i] == id) {
			dfs3(i, false);
			break;
		}
	}

	for (int e = 0; e < sz(edges); ++e) {
		if (edges[e].good) {
			cout << edges[e].from + 1 << " " << edges[e].to + 1 << "\n";
		}
	}
	
}
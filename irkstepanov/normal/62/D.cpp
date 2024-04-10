#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<ld, ld> pld;

struct edge {
	int from, to;
};

vector<vector<int> > g;
vector<edge> edges;

int n, m;
vector<bool> used;
vector<bool> vis;

void dfs(int v) {
	vis[v] = true;
	for (int e : g[v]) {
		if (used[e >> 1]) {
			continue;
		}
		int to = edges[e].to;
		if (!vis[to]) {
			dfs(to);
		}
	}
}

bool correct(vector<int>& a) {
	vector<int> deg(n);
	used.assign(m, false);
	for (int i = 0; i < n; ++i) {
		deg[i] = sz(g[i]);
	}
	int start = -1;
	for (int e : a) {
		int u = edges[e].from, v = edges[e].to;
		if (start == -1) {
			start = u;
		}
		used[e >> 1] = true;
		--deg[u], --deg[v];
	}
	vis.assign(n, false);
	dfs(start);
	for (int i = 0; i < n; ++i) {
		if (deg[i] > 0 && !vis[i]) {
			return false;
		}
	}
	return true;
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    cin >> n >> m;

    int prev;
    cin >> prev;
    --prev;
    vector<int> seq = {prev};
    g.resize(n);
    for (int i = 0; i < m; ++i) {
    	int nx;
    	cin >> nx;
    	--nx;
    	g[prev].pb(sz(edges));
    	edges.pb({prev, nx});
    	g[nx].pb(sz(edges));
    	edges.pb({nx, prev});
    	seq.pb(nx);
    	prev = nx;
    }

    for (int i = 0; i < n; ++i) {
    	sort(all(g[i]), [&](int e1, int e2) { return edges[e1].to < edges[e2].to; } );
    }
    

    vector<int> res;

    for (int l = m - 1; l >= 0; --l) {
    	int lst = seq[l];
    	vector<int> a;
    	for (int i = 0; i < l; ++i) {
    		a.pb(i << 1);
    	}
    	int pos = -1;
    	for (int i = 0; i < sz(g[lst]); ++i) {
    		if (g[lst][i] == (l << 1)) {
    			pos = i;
    			break;
    		}
    	}
    	for (int i = pos + 1; i < sz(g[lst]); ++i) {
    		int e = g[lst][i];
    		if (e < (l << 1)) {
    			continue;
    		}
    		a.pb(e);
    		if (correct(a)) {
    			res = a;
    			break;
    		}
    		a.pop_back();
    	}
    	if (!res.empty()) {
    		break;
    	}
    }

    if (res.empty()) {
    	cout << "No solution\n";
    	return 0;
    }

    vector<bool> in(m, false);
    for (int e : res) {
    	in[e >> 1] = true;
    }

    while (sz(res) < m) {
    	int lst = edges[res.back()].to;
    	for (int i = 0; i < sz(g[lst]); ++i) {
    		int e = g[lst][i];
    		if (in[e >> 1]) {
    			continue;
    		}
    		res.pb(e);
    		if (correct(res)) {
    			in[e >> 1] = true;
    			break;
    		}
    		res.pop_back();
    	}
    }

    cout << edges[res[0]].from + 1 << " ";
    for (int e : res) {
    	cout << edges[e].to + 1 << " ";
    }
    cout << "\n";

}
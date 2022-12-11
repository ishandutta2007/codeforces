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

vector<int> tin, tout; 
vector<vector<int> > shifts;
vector<int> parent;
vector<int> height, depth;
int timer = 0;

void precalc(int v, int p, int h) {
	parent[v] = p;
	tin[v] = timer++;
	height[v] = h;
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		precalc(to, v, h + 1);
	}
	tout[v] = timer++;
}

const int kmax = 20;

bool ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (ancestor(u, v)) {
		return u;
	}
	for (int k = kmax - 1; k >= 0; --k) {
		if (!ancestor(shifts[k][u], v)) {
			u = shifts[k][u];
		}
	}
	return shifts[0][u];
}

int dist(int u, int v) {
	int w = lca(u, v);
	return (height[u] - height[w]) + (height[v] - height[w]);
}

vector<int> subtree;
vector<int> component;

void dfs(int v, int p, int h) {
	subtree[v] = 1;
	component.pb(v);
	depth[v] = h;
	for (int to : g[v]) {
		if (to == p) {
			continue;
		}
		dfs(to, v, h + 1);
		subtree[v] += subtree[to];
	}
}

vector<int> link;
vector<int> dmin;

const int inf = 1e9;

void centroidDecomposition(int v, int parent) {
	component.clear();
	dfs(v, v, 0);
	int n = sz(component);
	assert(n == subtree[v]);
	int p = v;
	while (true) {
		int u = -1;
		for (int to : g[v]) {
			if (to == p) {
				continue;
			}
			if (2 * subtree[to] > n) {
				u = to;
				break;
			}
		}
		if (u == -1) {
			break;
		}
		p = v;
		v = u;
	}
	// v -- centroid
	component.clear();
	dfs(v, v, 0); // !!! //

	bool zero = false;
	for (int x : component) {
		if (x == 0) {
			zero = true;
			break;
		}
	}
	if (zero) {
		//cout << "!" << v << " " << depth[0] << endl;
		dmin[v] = depth[0];
	}

	link[v] = parent;
	vector<int> sons = g[v];
	for (int u : sons) {
		int pos;
		for (int i = 0; i < sz(g[u]); ++i) {
			if (g[u][i] == v) {
				pos = i;
				break;
			}
		}
		swap(g[u].back(), g[u][pos]);
		g[u].pop_back();
		centroidDecomposition(u, v);
	}
}

int main() {

	//ifstream cin("input.txt");
    //ofstream cout("output.txt");
    //freopen("input.txt", "r", stdin);
 
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, q;
    cin >> n >> q;

    g.resize(n);
    for (int i = 0; i < n - 1; ++i) {
    	int a, b;
    	cin >> a >> b;
    	--a, --b;
    	g[a].pb(b);
    	g[b].pb(a);
    }

    tin.resize(n);
    tout.resize(n);
    parent.resize(n);
    depth.resize(n);
    height.resize(n);

    precalc(0, 0, 0);

    shifts = vector<vector<int> >(kmax, vector<int>(n));
    for (int i = 0; i < n; ++i) {
    	shifts[0][i] = parent[i];
    }
    for (int k = 0; k + 1 < kmax; ++k) {
    	for (int i = 0; i < n; ++i) {
    		int j = shifts[k][i];
    		shifts[k + 1][i] = shifts[k][j];
    	}
    }

    subtree.resize(n);
    link.resize(n);
    dmin.assign(n, inf);

    centroidDecomposition(0, -1);

    while (q--) {
    	int type;
    	int v;
    	cin >> type >> v;
    	--v;
    	if (type == 1) { // color red
    		int u = v;
    		while (u != -1) {
    			dmin[u] = min(dmin[u], dist(u, v));
    			u = link[u];
    		}
    	} else {
    		int ans = inf;
    		int u = v;
    		while (u != -1) {
    			//cout << u << endl;
    			//cout << dmin[u] << endl;
    			//cout << dmin[u] << endl;
    			ans = min(ans, dmin[u] + dist(u, v));
    			u = link[u];
    		}
    		cout << ans << "\n";
    	}
    }
 
}
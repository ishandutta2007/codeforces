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
	int x;
};

vector<edge> edges;

vector<int> par;
vector<int> rk;
vector<bool> ans;

int get(int v) {
	if (par[v] == v) {
		return v;
	}
	return par[v] = get(par[v]);
}

void unite(int u, int v) {
	u = get(u), v = get(v);
	if (rk[u] < rk[v]) {
		swap(u, v);
	}
	par[v] = u;
	rk[u] += rk[v];
}

vector<int> xorsum;
vector<int> tin, tout;
vector<int> euler;
vector<int> roots;
vector<vector<edge> > g;

const int rmax = 20;
vector<vector<int> > shifts;

void dfs(int v) {
	tin[v] = sz(euler);
	tout[v] = sz(euler);
	euler.pb(v);
	for (edge& e : g[v]) {
		int to = e.to;
		if (tin[to] != -1) {
			continue;
		}
		xorsum[to] = (xorsum[v] ^ e.x);
		shifts[0][to] = v;
		for (int r = 0; r + 1 < rmax; ++r) {
			int w = shifts[r][to];
			shifts[r + 1][to] = shifts[r][w];
		}
		dfs(to);
		tout[v] = sz(euler);
		euler.pb(v);
	}
}



bool ancestor(int u, int v) {
	return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v) {
	if (ancestor(u, v)) {
		return u;
	}
	for (int r = rmax - 1; r >= 0; --r) {
		int w = shifts[r][u];
		if (!ancestor(w, v)) {
			u = w;
		}
	}
	return shifts[0][u];
}

vector<int> t;
int N;

void update(int l, int r, int val) {
	for (l += N, r += N; l <= r; l = (l + 1) >> 1, r = (r - 1) >> 1) {
		if (l & 1) {
			t[l] += val;
		}
		if (!(r & 1)) {
			t[r] += val;
		}
	}
}

int getST(int pos) {
	int ans = 0;
	for (pos += N; pos; pos >>= 1) {
		ans += t[pos];
	}
	return ans;
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
    	int u, v, x;
    	cin >> u >> v >> x;
    	--u, --v;
    	edges.pb({u, v, x});
    	ans.pb(false);
    }

    par.resize(n);
    rk.assign(n, 1);
    for (int i = 0; i < n; ++i) {
    	par[i] = i;
    }

    g.resize(n);

    for (int i = 0; i < m; ++i) {
    	int u = edges[i].from, v = edges[i].to;
    	if (get(u) != get(v)) {
    		ans[i] = true;
    		g[u].pb({u, v, edges[i].x});
    		g[v].pb({v, u, edges[i].x});
    		unite(u, v);
    	}
    }

    tin.assign(n, -1);
    tout.assign(n, -1);
    xorsum.assign(n, 0);
    shifts = vector<vector<int> >(rmax, vector<int>(n));
    for (int i = 0; i < n; ++i) {
    	if (tin[i] == -1) {
    		dfs(i);
    	}
    }

    N = sz(euler);
    t.assign(2 * N, 0);

    for (int i = 0; i < m; ++i) {
    	if (ans[i]) {
    		continue;
    	}
    	int u = edges[i].from, v = edges[i].to;
    	int sum = (xorsum[u] ^ xorsum[v]);
    	if (sum == edges[i].x) {
    		continue;
    	}
    	int w = lca(u, v);
    	int cnt = getST(tin[u]) - 2 * getST(tin[w]) + getST(tin[v]);
    	if (cnt) {
    		continue;
    	}
    	int curr = u;
    	while (curr != w) {
    		update(tin[curr], tout[curr], 1);
    		curr = shifts[0][curr];
    	}
    	curr = v;
    	while (curr != w) {
    		update(tin[curr], tout[curr], 1);
    		curr = shifts[0][curr];
    	}
    	ans[i] = true;
    }

    for (int i = 0; i < m; ++i) {
    	cout << (ans[i] ? "YES" : "NO") << "\n";
    }

}
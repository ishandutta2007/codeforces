#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

class Dominator {
public:
	Dominator(vector<vector<int> > h, int s) {
		n = sz(h);
		newId.assign(n, -1);
		g = h;
		timer = 0;
		parent.resize(n);
		dfs(s);
		n = timer;
		vector<vector<int> > tmp(n);
		for (int i = 0; i < sz(newId); ++i) {
			if (newId[i] == -1) {
				continue;
			}
			for (int to : g[i]) {
				tmp[newId[i]].pb(newId[to]);
			}
		}
		g.swap(tmp);
		gr.resize(n);
		for (int i = 0; i < n; ++i) {
			for (int to : g[i]) {
				gr[to].pb(i);
			}
		}
		sdom.resize(n);
		label.resize(n);
		dsu.resize(n);
		for (int i = 0; i < n; ++i) {
			label[i] = i;
			dsu[i] = i;
		}
		for (int w = n - 1; w >= 0; --w) {
			sdom[w] = w;
			for (int v : gr[w]) {
				if (v < w) {
					sdom[w] = min(sdom[w], v);
				} else {
					pii p = getDSU(v);
					sdom[w] = min(sdom[w], sdom[p.second]);
				}
			}
			if (w) {
				dsu[w] = parent[w];
			}
		}
		calcIdom();
	}

	void get(vector<int>& res1, vector<int>& res2) const {
		res1 = newId;
		res2 = idom;
	}
private:
	vector<int> newId;
	vector<vector<int> > g, gr;
	vector<int> sdom;
	vector<int> idom;
	int timer;
	const int rmax = 20;
	vector<vector<int> > shifts;
	vector<int> parent;
	vector<int> label;
	vector<int> dsu;
	vector<int> depth;
	int n;

	void dfs(int v) {
		newId[v] = timer++;
		for (int to : g[v]) {
			if (newId[to] == -1) {
				dfs(to);
				parent[newId[to]] = newId[v];
			}
		}
	}

	pii getDSU(int v) {
		if (dsu[v] == v) {
			return {-1, -1};
		}
		pii p = getDSU(dsu[v]);
		if (p.first == -1) {
			return {v, label[v]};
		}
		int u = p.second;
		if (sdom[u] < sdom[label[v]]) {
			label[v] = u;
		}
		dsu[v] = p.first;
		return {p.first, label[v]};
	}

	int lca(int u, int v) {
		if (depth[u] > depth[v]) {
			swap(u, v);
		}
		for (int r = rmax - 1; r >= 0; --r) {
			if (depth[v] - (1 << r) >= depth[u]) {
				v = shifts[r][v];
			}
		}
		assert(depth[u] == depth[v]);
		if (u == v) {
			return u;
		}
		for (int r = rmax - 1; r >= 0; --r) {
			if (shifts[r][u] != shifts[r][v]) {
				u = shifts[r][u];
				v = shifts[r][v];
			}
		}
		assert(u != v && shifts[0][u] == shifts[0][v]);
		return shifts[0][u];
	}

	void calcIdom() {
		idom.resize(n);
		depth.resize(n);
		shifts = vector<vector<int> >(rmax, vector<int>(n));
		for (int i = 0; i < n; ++i) {
			if (i == 0) {
				idom[i] = i;
				depth[i] = 0;
			} else {
				idom[i] = lca(parent[i], sdom[i]);
				depth[i] = depth[idom[i]] + 1;
			}
			shifts[0][i] = idom[i];
			for (int r = 0; r + 1 < rmax; ++r) {
				int j = shifts[r][i];
				shifts[r + 1][i] = shifts[r][j];
			}
		}
	}
};

vector<vector<int> > tree;
vector<int> subtree;

void dfs(int v) {
	subtree[v] = 1;
	for (int to : tree[v]) {
		dfs(to);
		subtree[v] += subtree[to];
	}
}

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, s;
    cin >> n >> m >> s;
    --s;
    vector<vector<pii> > g(n);
    while (m--) {
    	int u, v, w;
    	cin >> u >> v >> w;
    	--u, --v;
    	g[u].pb({v, w});
    	g[v].pb({u, w});
    }

    const ll inf = 1e18;
    vector<ll> dist(n, inf);

    auto comp = [&] (int a, int b) {
    	if (dist[a] != dist[b]) {
    		return dist[a] < dist[b];
    	}
    	return a < b;
    };

    dist[s] = 0;
    set<int, decltype(comp)> q(comp);
    q.insert(s);
    while (!q.empty()) {
    	int v = *q.begin();
    	q.erase(q.begin());
    	for (pii p : g[v]) {
    		ll val = p.second + dist[v];
    		int to = p.first;
    		if (val < dist[to]) {
    			q.erase(to);
    			dist[to] = val;
    			q.insert(to);
    		}
    	}
    }

    vector<vector<int> > h(n);
    for (int i = 0; i < n; ++i) {
    	for (pii p : g[i]) {
    		int to = p.first;
    		if (dist[i] + p.second == dist[to]) {
    			h[i].pb(to);
    		}
    	}
    }

    Dominator D(h, s);
    vector<int> newId, idom;
    D.get(newId, idom);
    int cc = sz(idom);

    tree.resize(cc);
    subtree.resize(cc);
    for (int i = 1; i < cc; ++i) {
    	int p = idom[i];
    	tree[p].pb(i);
    }
    dfs(0);

    int ans = 0;
    for (int i = 1; i < cc; ++i) {
    	ans = max(ans, subtree[i]);
    }
    cout << ans << "\n";
    
}
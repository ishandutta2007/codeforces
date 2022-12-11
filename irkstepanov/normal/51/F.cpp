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

int ans = 0;

class Tree {
public:
	Tree(vector<vector<int> > h) {
		g = h;
		n = sz(g);
		dist.resize(n);
		dfs1(0, 0, 0);
		int opt = 0;
		for (int i = 0; i < n; ++i) {
			if (dist[opt] < dist[i]) {
				opt = i;
			}
		}
		dfs1(opt, opt, 0);
		int v = opt;
		for (int i = 0; i < n; ++i) {
			if (dist[v] < dist[i]) {
				v = i;
			}
		}
		int cnt = dist[v] + 1;
		for (int i = 0; i < n; ++i) {
			if (sz(g[i]) == 1 && i != opt && i != v) {
				++cnt;
			}
		}
		ans += n - cnt;
	}
private:
	vector<vector<int> > g;
	int n;
	vector<int> dist;

	void dfs1(int v, int p, int d) {
		dist[v] = d;
		for (int to : g[v]) {
			if (to == p) {
				continue;
			}
			dfs1(to, v, d + 1);
		}
	}
};

class Bridges {
public:
	Bridges(vector<vector<int> > h) {
		n = sz(h);
		g.resize(n);
		for (int i = 0; i < n; ++i) {
			for (int j : h[i]) {
				if (i > j) {
					continue;
				}
				g[i].pb(sz(edges));
				edges.pb({i, j});
				g[j].pb(sz(edges));
				edges.pb({j, i});
			}
		}
		bridge.assign(sz(edges), false);
		tin.resize(n);
		used.assign(n, false);
		ret.resize(n);
		timer = 0;
		int num = 0;

		vector<int> compId(n, -1);

		for (int i = 0; i < n; ++i) {
			if (used[i]) {
				continue;
			}
			dfs1(i, i);
			if (num) {
				++ans;
			}
			++num;

			vector<int> comp;
			queue<int> q;
			q.push(i);
			compId[i] = 0;
			int cc = 1;
			while (!q.empty()) {
				int v = q.front();
				comp.pb(v);
				q.pop();
				for (int e : g[v]) {
					int to = edges[e].second;
					if (compId[to] != -1) {
						continue;
					}
					if (bridge[e]) {
						compId[to] = cc++;
					} else {
						compId[to] = compId[v];
					}
					q.push(to);
				}
			}
			//cout << "!" << cc << " " << sz(comp) << endl;
			ans += sz(comp) - cc;

			vector<vector<int> > tree(cc);
			for (int v : comp) {
				for (int e : g[v]) {
					int to = edges[e].second;
					if (compId[v] != compId[to]) {
						tree[compId[v]].pb(compId[to]);
					}
				}
			}

			Tree t(tree);
		}
	}
private:
	vector<vector<int> > g;
	vector<pii> edges;
	vector<bool> bridge;
	vector<bool> used;
	vector<int> tin;
	vector<int> ret;
	int n;
	int timer;

	void dfs1(int v, int p) {
		used[v] = true;
		tin[v] = ret[v] = timer++;
		for (int e : g[v]) {
			int to = edges[e].second;
			if (to == p) {
				continue;
			}
			if (used[to]) {
				ret[v] = min(ret[v], tin[to]);
			} else {
				dfs1(to, v);
				ret[v] = min(ret[v], ret[to]);
				if (ret[to] > tin[v]) {
					bridge[e] = bridge[e ^ 1] = true;
				}
			}
		}
	}
};

int main() {
    
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > g(n);
    while (m--) {
    	int u, v;
    	cin >> u >> v;
    	--u, --v;
    	g[u].pb(v);
    	g[v].pb(u);
    }

    Bridges b(g);
    cout << ans << "\n";

}
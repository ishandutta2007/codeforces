#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back
#define mp make_pair

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef long double ld;

const int inf = 1e9;

class MCMF {
public:
	MCMF(int n, int s, int t) : vsize(n), s(s), t(t) {
		g.resize(vsize);
		flow = cost = 0;
	}

	void addEdge(int u, int v, int cap, int cost) {
		g[u].pb(sz(edges));
		edges.pb({u, v, cap, cost, 0});
		g[v].pb(sz(edges));
		edges.pb({v, u, 0, -cost, 0});
	}

	void solve(bool flag) {
		if (!flag) {
			while (fb()) {
				addFlow();
			}
		} else {
			while (true) {
				fb();
				int oldCost = cost;
				addFlow();
				if (cost == oldCost) {
					break;
				}
			}
		}
	}

	vector<pii> getFull() {
		vector<pii> ans = get();
		//cout << cost << " " << flow << endl;
		//assert(cost == 0);
		//cout << sz(ans) << " " << flow << endl;
		assert(sz(ans) == flow);
		return ans;
	}

	map<pii, int> getMap() {
		map<pii, int> mapa;
		for (int e = 0; e < sz(edges); ++e) {
			if (edges[e].flow > 0) {
				mapa[{edges[e].from, edges[e].to}] += edges[e].flow;
			}
		}
		return mapa;
	}
private:
	struct edge {
		int from, to;
		int cap, cost, flow;
	};
	vector<edge> edges;
	vector<vector<int> > g;
	int vsize;
	int s, t;
	vector<int> dist;
	vector<int> p;
	int flow;
	int cost;

	bool fb() {
		dist.assign(vsize, inf);
		dist[s] = 0;
		vector<int> q(vsize);
		p.assign(vsize, -1);
		int qh = 0, qt = 1;
		q[0] = s;
		vector<char> used(vsize, false);
		while (qh != qt) {
			int v = q[qh++];
			if (qh == vsize) {
				qh = 0;
			}
			used[v] = false;
			for (int e : g[v]) {
				if (edges[e].cap > edges[e].flow && dist[edges[e].to] > dist[v] + edges[e].cost) {
					dist[edges[e].to] = dist[v] + edges[e].cost;
					p[edges[e].to] = e;
					if (!used[edges[e].to]) {
						used[edges[e].to] = true;
						q[qt++] = edges[e].to;
						if (qt == vsize) {
							qt = 0;
						}
					}
				}
			}
		}
		return dist[t] != inf;
	}

	bool addFlow() {
		int curr = t;
		while (p[curr] != -1) {
			int e = p[curr];
			edges[e].flow += 1;
			//cout << "ADD EDGE " << edges[e].from + 1 << " " << edges[e].to + 1 << endl;
			edges[e ^ 1].flow -= 1;
			cost += edges[e].cost;
			curr = edges[e].from;
		}
		++flow;
		return false;
	}

	vector<pii> get() {
		vector<char> used(vsize, false);
		queue<int> q;
		q.push(s);
		used[s] = true;
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int e : g[v]) {
				if (edges[e].flow < edges[e].cap && !used[edges[e].to]) {
					q.push(edges[e].to);
					used[edges[e].to] = true;
				}
			}
		}
		vector<pii> ans;
		for (int e = 0; e < sz(edges); ++e) {
			if (edges[e].cap > 0 && edges[e].cap == edges[e].flow && used[edges[e].from] && !used[edges[e].to]) {
				ans.pb({edges[e].from, edges[e].to});
				assert(edges[e].cost == 0);
			}
		}
		return ans;
	}
};

/*class obtainCycle {
public:
	obtainCycle(int n, const vector<pii>& edges) : n(n) {
		g.resize(n);
		for (pii p : edges) {
			g[p.first].pb(p.second);
		}
	}

	bool getCycle(vector<int>& ans) {
		parent.assign(n, -1);
		color.assign(n, 0);
		for (int v = 0; v < n; ++v) {
			if (parent[v] == -1 && cycle.empty()) {
				dfs(v, v);
			}
		}
		if (cycle.empty()) {
			return false;
		} else {
			reverse(all(cycle));
			ans = cycle;
			return true;
		}
	}

private:
	vector<vector<int> > g;
	vector<int> parent;
	vector<int> color;
	int n;
	vector<int> cycle;

	void dfs(int v, int p) {
		color[v] = 1;
		//cout << "V = " << v + 1 << endl;
		parent[v] = p;
		for (int to : g[v]) {
			if (parent[to] == -1) {
				//cout << v + 1 << " " << to + 1 << endl;
				dfs(to, v);
			} else if (cycle.empty() && color[to] == 1) {
				int curr = v;
				while (curr != to) {
					cycle.pb(curr);
					curr = parent[curr];
				}
				cycle.pb(to);
			}
		}
		color[v] = 2;
	}
};*/

class MF {
public:
	MF(int n, int s, int t) : vsize(n), s(s), t(t) {
		g.resize(vsize);
	}

	void addEdge(int u, int v, int c, int f) {
	    g[u].pb(sz(edges));
	    edges.pb({u, v, c, f});
	    g[v].pb(sz(edges));
	    edges.pb({v, u, 0, -f});
	}

	int get() {
	    int ans = 0;
	    while (bfs()) {
	        int x;
	        while ((x = dfs(s, inf))) {
	            ans += x;
	        }
	    }
	    return ans;
	}

	map<pii, int> getMap() {
		map<pii, int> ans;
		for (int e = 0; e < sz(edges); ++e) {
			if (edges[e].cap < 2) {
				continue;
			}
			pii p = {edges[e].from, edges[e].to};
			if (!ans.count(p)) {
				ans[p] = 1;
			}
			ans[p] += edges[e].flow;
		}
		return ans;
	}

private:
	struct edge {
	    int from, to;
	    int cap, flow;
	};

	vector<edge> edges;
	vector<vector<int> > g;
	vector<int> level, ptr;
	int vsize;
	int s, t;

	bool bfs() {
	    level.assign(vsize, inf);
	    ptr.assign(vsize, 0);
	    level[s] = 0;
	    queue<int> q;
	    q.push(s);
	    while (!q.empty()) {
	        int v = q.front();
	        q.pop();
	        for (int e : g[v]) {
	            if (edges[e].cap > edges[e].flow && level[edges[e].to] == inf) {
	                level[edges[e].to] = level[v] + 1;
	                q.push(edges[e].to);
	            }
	        }
	    }
	    return level[t] != inf;
	}

	int dfs(int v, int flow) {
	    if (v == t) {
	        return flow;
	    }
	    for (int i = ptr[v]; i < sz(g[v]); ++i) {
	        int e = g[v][i];
	        if (edges[e].cap > edges[e].flow && level[edges[e].to] == level[v] + 1) {
	            int k = dfs(edges[e].to, min(flow, edges[e].cap - edges[e].flow));
	            if (k) {
	                edges[e].flow += k;
	                edges[e ^ 1].flow -= k;
	                return k;
	            }
	        }
	        ++ptr[v];
	    }
	    return 0;
	}
};

class FillAll {
public:
	FillAll(int n, int s, int t) : vsize(n), s(s), t(t) {
		g.resize(n);
		gr.resize(n);
	}

	void addEdge(int u, int v) {
		g[u].pb(v);
		gr[v].pb(u);
	}

	void solve() {
		p.assign(vsize, -1);
		p[s] = s;
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int to : g[v]) {
				if (p[to] == -1) {
					p[to] = v;
					q.push(to);
				}
			}
		}

		pr.assign(vsize, -1);
		pr[t] = t;
		q.push(t);
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			for (int to : gr[v]) {
				if (pr[to] == -1) {
					pr[to] = v;
					q.push(to);
				}
			}
		}
	}

	map<pii, int> getMap() {
		for (int u = 0; u < vsize; ++u) {
			for (int v : g[u]) {
    			int curr = u;
    			vector<pii> add;
    			while (curr != s) {
    			    add.pb({p[curr], curr});
    				curr = p[curr];
    				if (curr == -1) {
    				    break;
    				}
    			}
    			if (curr == -1) {
    			    continue;
    			}
    			add.pb({u, v});
    			curr = v;
    			while (curr != t) {
    				add.pb({curr, pr[curr]});
    				curr = pr[curr];
    				if (curr == -1) {
    				    break;
    				}
    			}
    			if (curr == -1) {
    			    continue;
    			}
    			for (pii& p : add) {
    			    ++ans[p];
    			}
			}
		}
		return ans;
	}
private:
	int vsize;
	int s, t;
	map<pii, int> ans;
	vector<vector<int> > g, gr;
	vector<int> p, pr;
};

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //ifstream cin("input.txt");
    //freopen("input.txt", "r", stdin);
    //ofstream cout("output.txt");

	int n, m;
	cin >> n >> m;
	int s, t;
	cin >> s >> t;
	--s, --t;

	vector<pii> edges(m);
	vector<int> ind(m);
	for (int i = 0; i < m; ++i) {
		cin >> edges[i].first >> edges[i].second;
		--edges[i].first, --edges[i].second;
		cin >> ind[i];
	}

	MCMF mincost1(n, s, t);
	for (int i = 0; i < m; ++i) {
		if (ind[i] == 0) {
			mincost1.addEdge(edges[i].first, edges[i].second, inf, 1);
		} else {
			mincost1.addEdge(edges[i].first, edges[i].second, 1, 0);
			mincost1.addEdge(edges[i].second, edges[i].first, inf, 1);
		}
	}
	mincost1.solve(false);

	vector<pii> full = mincost1.getFull();
	set<pii> setik;
	for (pii p : full) {
		setik.insert(p);
	}
	/*for (pii p : full) {
		cout << p.first + 1 << " " << p.second + 1 << "\n";
	}*/

	/*vector<int> removed(m);
	vector<char> deleted(m, false);
	map<pii, int> num;
	for (int i = 0; i < m; ++i) {
		num[edges[i]] = i;
	}
	while (true) {
		vector<pii> currEdges;
		for (int i = 0; i < m; ++i) {
			if (!deleted[i] && ind[i] == 1) {
				currEdges.pb(edges[i]);
			}
		}
		obtainCycle obt(n, currEdges);
		vector<int> cycle;
		//cout << "F" << endl;
		if (!obt.getCycle(cycle)) {
			//cout << "B" << endl;
			break;
		}
		for (int i = 0; i < sz(cycle); ++i) {
			int j = (i + 1) % sz(cycle);
			int x = num[{cycle[i], cycle[j]}];
			++removed[x];
			if (i == 0) {
				deleted[x] = true;
			}
		}
	}*/

	/*MF mincost2(n, s, t);
	for (int i = 0; i < m; ++i) {
		if (ind[i] == 1) {
			mincost2.addEdge(edges[i].first, edges[i].second, 100500, 0);
			mincost2.addEdge(s, edges[i].second, 1, 0);
			mincost2.addEdge(edges[i].first, t, 1, 0);
		}
	}
	mincost2.get();
	map<pii, int> mapa = mincost2.getMap();*/

	vector<vector<int> > g(n);
	for (int e = 0; e < sz(edges); ++e) {
		if (ind[e] == 1) {
			g[edges[e].first].pb(edges[e].second);
		}
	}
	map<pii, int> removed;
	for (int e = 0; e < sz(edges); ++e) {
		if (ind[e] == 0) {
			continue;
		}
		int u = edges[e].first, v = edges[e].second;
		vector<int> p(n, -1);
		queue<int> q;
		q.push(v);
		p[v] = v;
		while (!q.empty()) {
			int vert = q.front();
			q.pop();
			for (int to : g[vert]) {
				if (p[to] == -1) {
					p[to] = vert;
					q.push(to);
				}
			}
		}
		if (p[u] != -1) {
			++removed[{u, v}];
			int curr = u;
			while (curr != v) {
				++removed[{p[curr], curr}];
				curr = p[curr];
			}
		}
	}

	FillAll mincost2(n, s, t);
	for (int i = 0; i < m; ++i) {
		if (ind[i] == 1) {
			mincost2.addEdge(edges[i].first, edges[i].second);
		}
	}

	mincost2.solve();
	map<pii, int> mapa = mincost2.getMap();

	vector<int> sum(n);

	cout << sz(full) << "\n";
	MF maxflow(n, s, t);
	for (int i = 0; i < m; ++i) {
		if (ind[i] == 0) {
			cout << "0 1\n";
			maxflow.addEdge(edges[i].first, edges[i].second, 1, 0);
			continue;
		}
		pii p = {edges[i].first, edges[i].second};
		int flow = mapa[p] + removed[{edges[i].first, edges[i].second}];
		sum[edges[i].first] += flow;
		sum[edges[i].second] -= flow;
		cout << flow << " ";
		if (setik.count(p)) {
			cout << flow << "\n";
			maxflow.addEdge(edges[i].first, edges[i].second, flow, flow);
		} else {
			cout << flow + 1 << "\n";
			maxflow.addEdge(edges[i].first, edges[i].second, flow + 1, flow);
		}
	}
	cout << endl;

	for (int i = 0; i < n; ++i) {
		if (i != s && i != t) {
			assert(sum[i] == 0);
		}
	}
	assert(sum[s] == -sum[t]);
	/*if (maxflow.get()) {
		cout << "F\n";
	}*/
	assert(maxflow.get() == 0);

}
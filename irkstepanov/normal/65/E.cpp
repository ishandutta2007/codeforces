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
	int id;
};

struct operation {
	string type;
	int x, y, z;
	operation() {}
	operation(string type, int x, int y = 0, int z = 0) : type(type), x(x), y(y), z(z) {}
};

vector<operation> ans;

struct Solver {

	bool success;

	Solver(int n, vector<vector<edge> >& gg) {
		success = true;
		newG.resize(n);
		g = gg;

		parent.assign(n, -1);
	    extra.resize(n);
	    tin.resize(n);

	    for (int i = 0; i < n; ++i) {
	    	if (parent[i] == -1) {
	    		dfs1(i, i);
	    		roots.pb(i);
	    	}
	    }

	    g = newG;

	    sort(all(roots), [&](int a, int b) {
	    	if (g[a].empty() && g[b].empty()) {
	    		return a < b;
	    	}
	    	if (!(g[a].empty()) && !(g[b].empty())) {
	    		return a < b;
	    	}
	    	if (!g[a].empty()) {
	    		return true;
	    	}
	    	if (!g[b].empty()) {
	    		return false;
	    	}
	    });
	    /*for (int x : roots) {
	    	cout << "!" << x + 1 << "\n";
	    }*/

	    vector<int> extra_ptr(n), kids_ptr(n);
	    stack<int> s;

	    dfs2(roots[0]);
	    int curr = roots[0];

	    s.push(roots[0]);

	    for (int j = 1; j < sz(roots); ++j) {
	    	int r = roots[j];
	    	while (true) {
	    		int v = s.top();
	    		//cout << "!" << v << " " << sz(g[v]) << " " << kids_ptr[v] <<endl;
	    		if (kids_ptr[v] & 1) {
	    			break;
	    		}
	    		if (kids_ptr[v] / 2 < sz(g[v])) {
	    			edge& e = g[v][kids_ptr[v] / 2];
	    			++kids_ptr[v];
	    			int to = e.to;
	    			ans.pb({"visit", to});
	    			s.top() = to;
	    			continue;
	    		}
	    		if (extra_ptr[v] == sz(extra[v])) {
	    			if (parent[v] != v) {
	    				int p = parent[v];
	    				ans.pb({"visit", p});
	    				s.top() = p;
	    				continue;
	    			} else {
	    				s.pop();
	    				if (s.empty()) {
	    					success = false;
	    					return;
	    				}
	    				v = s.top();
	    				ans.pb({"visit", v});
	    				continue;
	    			}
	    		}
	    		break;
	    	}
	    	int v = s.top();
	    	if (kids_ptr[v] & 1) {
	    		edge& e = g[v][kids_ptr[v] / 2];
	    		ans.pb({"change", e.id, v, r});
	    		++kids_ptr[v];
	    		dfs2(r);
	    		s.push(r);
	    	} else {
	    		assert(extra_ptr[v] < sz(extra[v]));
		    	edge& e = extra[v][extra_ptr[v]];
		    	++extra_ptr[v];
		    	ans.pb({"change", e.id, v, r});
		    	dfs2(r);
		    	s.push(r);
		    }
	    }
	}

	vector<vector<edge> > g;
	vector<vector<edge> > newG;
	vector<int> parent;
	vector<int> roots, tin;
	int timer = 0;
	vector<vector<edge> > extra;

	void dfs1(int v, int p, int en = -1) {
		parent[v] = p;
		tin[v] = timer++;
		for (edge& e : g[v]) {
			if (e.id == en) {
				continue;
			}
			int to = e.to;
			if (parent[to] == -1) {
				newG[v].pb(e);
				dfs1(to, v, e.id);
			} else if (tin[to] < tin[v]) {
				extra[v].pb(e);
			}
		}
	}



	void dfs2(int v) {
		ans.pb({"visit", v});
		for (edge& e : g[v]) {
			int to = e.to;
			dfs2(to);
			ans.pb({"visit", v});
		}
	}
};

vector<vector<edge> > g;
vector<bool> used;
edge bridge;
bool found = false;

void dfs(int v, int ed) {
	used[v] = true;
	for (edge& e : g[v]) {
		if (e.id == ed) {
			continue;
		}
		int to = e.to;
		if (!used[to]) {
			dfs(to, e.id);
		} else {
			found = true;
			bridge = e;
		}
	}
}

int main() {

	ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    //freopen("input.txt", "r", stdin);

    int n, m;
    cin >> n >> m;
    g.resize(n);

    for (int i = 0; i < m; ++i) {
    	int u, v;
    	cin >> u >> v;
    	--u, --v;
    	g[u].pb({u, v, i});
    	g[v].pb({v, u, i});
    }

    if (n == 1) {
    	cout << "YES\n";
    	cout << "0\n";
    	cout << "1 1\n";
    	return 0;
    }

    if  (g[0].empty()) {
    	used.assign(n, false);
    	for (int i = 0; i < n; ++i) {
    		if (found || used[i]) {
    			continue;
    		}
    		dfs(i, -1);
    	}
    	if (!found) {
    		for (int i = 1; i < n; ++i) {
    			if (sz(g[i]) > 1) {
    				bridge = g[i][0];
    				found = true;
    				break;
    			}
    		}
    	}
    	if (!found) {
    		cout << "NO\n";
    		return 0;
    	}

		ans.pb({"visit", 0});
		ans.pb({"change", bridge.id, bridge.from, 0});
		vector<int> newNum(n, -1);
		// newNum[i] = new number of vertex i
		vector<vector<edge> > nx(n);
		vector<int> rev(n - 1);
		newNum[bridge.from] = 0;
		rev[0] = bridge.from;
		int cc = 1;
		for (int i = 1; i < n; ++i) {
			if (newNum[i] == -1) {
				newNum[i] = cc++;
				rev[newNum[i]] = i;
			}
		}
		for (int i = 1; i < n; ++i) {
			for (edge& e : g[i]) {
				if (e.id == bridge.id) {
					continue;
				}
				int to = e.to;
				nx[newNum[i]].pb({newNum[i], newNum[to], e.id});
			}
		}
		Solver solver(n - 1, nx);
		if (!solver.success) {
			cout << "NO\n";
			return 0;
		} else {
			for (int i = 2; i < sz(ans); ++i) {
				if (ans[i].type == "visit") {
					ans[i].x = rev[ans[i].x];
				} else {
					ans[i].y = rev[ans[i].y];
					ans[i].z = rev[ans[i].z];
				}
			}
		}
    } else {
    	Solver solver(n, g);
    	if (!solver.success) {
			cout << "NO\n";
			return 0;
		}
    }

    



    

    

    cout << "YES\n";
    int cnt = 0;
    for (int i = 0; i < sz(ans); ++i) {
    	if (ans[i].type == "change") {
    		++cnt;
    	}
    }

    cout << cnt << "\n";
    vector<int> stored;
    for (int i = 0; i <= sz(ans); ++i) {
    	if (i == sz(ans) || ans[i].type == "change") {
    		cout << sz(stored) << " ";
    		for (int x : stored) {
    			cout << x + 1 << " ";
    		}
    		stored = {};
    		cout << "\n";
    		if (i < sz(ans)) {
    			cout << ans[i].x + 1 << " " << ans[i].y + 1 << " " << ans[i].z + 1 << "\n";
    		}
    	} else {
    		stored.pb(ans[i].x);
    	}
    }

}
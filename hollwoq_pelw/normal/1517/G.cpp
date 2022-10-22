/* 
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include<bits/stdc++.h>
using namespace std;

void FAST_IO(string filein = "", string fileout = "", string fileerr = ""){
    if (fopen(filein.c_str(), "r")){
        freopen(filein.c_str(), "r", stdin);
        freopen(fileout.c_str(), "w", stdout);
#ifdef hollwo_pelw_local
        freopen(fileerr.c_str(), "w", stderr);
#endif
    }
    cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
}

void Hollwo_Pelw();

signed main(){
#ifdef hollwo_pelw_local
    FAST_IO("input.inp", "output.out", "error.err");
    auto start = chrono::steady_clock::now();
#else
    FAST_IO("hollwo_pelw_train.inp", "hollwo_pelw_train.out");
#endif
    int testcases = 1;
    // cin >> testcases;
    for (int test = 1; test <= testcases; test++){
        // cout << "Case #" << test << ": ";
        Hollwo_Pelw();
    }
#ifdef hollwo_pelw_local
    auto end = chrono::steady_clock::now();
    cout << endl;
    cout << "Excution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
    return 0;
}

const int N = 2020;
const long long inf = 1e18;

struct flow_edge {
	int u, v; long long c, f;
	flow_edge () {}
	flow_edge (int _u, int _v, long long _c)
		: u(_u), v(_v), c(_c), f(0) {}
};

struct Dinic {
	int n, s, t, level[N], ptr[N];
	
	vector<flow_edge> edges;
	vector<int> adj[N];

	queue<int> q;

	Dinic () : n(N - 1) {}
	Dinic (int _n) : n(_n) {}

	void add(int u, int v, long long c) {
		adj[u].push_back(edges.size());
		edges.emplace_back(u, v, c);
	}

	void add_edge(int u, int v, long long c) {
		add(u, v, c), add(v, u, 0);
		// cout << u << ' ' << v << ' ' << c << endl;
	}

	bool bfs() {
		for (int i = 0; i <= n; i++) 
			level[i] = -1;
		level[s] = 0; q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (auto id : adj[u]) {
				if (edges[id].c > edges[id].f && level[edges[id].v] == -1) {
					level[edges[id].v] = level[u] + 1; q.push(edges[id].v);
				}
			}
		}
		return level[t] != -1;
	}

	long long dfs(int u, long long push) {
		if (!push) return 0;
		if (u == t) return push;
		for (int &i = ptr[u]; i < adj[u].size(); i++) {
			int id = adj[u][i];
			if (level[u] + 1 != level[edges[id].v] || edges[id].c <= edges[id].f) continue; 
			int nxt_push = dfs(edges[id].v, min(push, edges[id].c - edges[id].f));
			if (nxt_push) {
				edges[id].f += nxt_push;
				edges[id ^ 1].f -= nxt_push;
				return nxt_push;
			}
		}
		return 0;
	}

	long long maxflow(int _s, int _t) {
		s = _s, t = _t;
		long long ans = 0;
		while (bfs()) {
			for (int i = 0; i <= n; i++) ptr[i] = 0;
			while (int push = dfs(s, inf))
				ans += push;
		}
		return ans;
	}
};

map<pair<int, int>, int> mp;		

int n;
long long tot;

void Hollwo_Pelw() {
	cin >> n;
	Dinic dinic(2 * n + 2);

	for (int i = 1, x, y, w; i <= n; i++) {
		cin >> x >> y >> w, tot += w;
		mp[{x, y}] = i;
		dinic.add_edge(i << 1, i << 1 | 1, w);
	}

	for (auto it : mp) {
		int x = it.first.first, y = it.first.second, i = it.second, j;
		if (!i) continue ;
		if (x % 2 == 0) {
			if (y % 2 == 0) {
				for (int ny = y - 1; ny <= y + 1; ny += 2) 
					if (j = mp[{x, ny}]) {
						// cout << i << " -> " << j << endl;
						dinic.add_edge(i << 1 | 1, j << 1, inf);
					}
			}
		} else {
			if (y % 2 == 0) {
				// cout << "s -> " << i << endl;
				dinic.add_edge(1, i << 1, inf);
				for (int nx = x - 1; nx <= x + 1; nx += 2)
					if (j = mp[{nx, y}])  {
						// cout << i << " -> " << j << endl;
						dinic.add_edge(i << 1 | 1, j << 1, inf);
					}
			} else {
				// cout << i << " -> t" << endl; 
				dinic.add_edge(i << 1 | 1, 0, inf);
				for (int nx = x - 1; nx <= x + 1; nx += 2)
					if (j = mp[{nx, y}]) {
						// cout << j << " -> " << i << endl;
						dinic.add_edge(j << 1 | 1, i << 1, inf);
					}
			}
		}
	}

	cout << tot - dinic.maxflow(1, 0);
}
//   1 0 1
// 0   +--
// 1 --+
// 0
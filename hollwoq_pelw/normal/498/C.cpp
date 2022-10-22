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
	FAST_IO("hollwo_pelw.inp", "hollwo_pelw.out");
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


const int N = 4020;
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
} dinic;

int n, m, a[101], s = 0, t = 4000, nnode;

vector<pair<int, int>> v[101];
map<int, int> idx[101];

void factorize() {
	for (int i = 1; i <= n; ++i) {
		for (int j = 2; j * j <= a[i]; j++) {
			if (a[i] % j == 0) {
				int c = 0;
				while (a[i] % j == 0)
					a[i] /= j, c++;
				v[i].emplace_back(j, c);
			}
		}
		if (a[i] > 1)
			v[i].emplace_back(a[i], 1);
	}
	for (int i = 1; i <= n; i++) {
		for (auto vp : v[i]) {
			idx[i][vp.first] = ++ nnode;
			dinic.add_edge(i & 1 ? s : nnode, i & 1 ? nnode : t, vp.second);
		}
	}
}

void Hollwo_Pelw() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	factorize();
	for (int i = 1, x, y; i <= m; i++) {
		cin >> x >> y;
		if (y & 1) swap(x, y);
		for (auto vp : idx[x]) {
			if (idx[y].count(vp.first))
				dinic.add_edge(vp.second, idx[y][vp.first], inf);
		}
	}
	cout << dinic.maxflow(s, t);
}
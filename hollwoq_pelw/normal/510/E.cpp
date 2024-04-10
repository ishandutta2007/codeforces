/*
// is short or still long ???
hollwo_pelw's template(short)
// Note : -Dhollwo_pelw_local
*/

#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_pbds;
// using namespace __gnu_cxx;

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
	cout << "\nExcution time : " << chrono::duration_cast<chrono::milliseconds> (end - start).count() << "[ms]" << endl;
#endif
	return 0;
}

const int N = 202, M = 2e4 + 5;

struct flow_edge {
    int u, v; int64_t c, f;
    flow_edge(int _u = 0, int _v = 0, int64_t _c = 0, int64_t _f = 0)
        : u(_u), v(_v), c(_c), f(_f) {}
};

struct Dinic {
    static const int64_t inf = 1e18;
    int n, s, t, ptr[N], level[N];
    vector<flow_edge> edges;
    vector<int> adj[N];
    queue<int> q;
    
    Dinic(int _n = N) : n(_n) {}
    
    inline void add_edge(int u, int v, int64_t c = inf) {
#define do_add(u, v, c) adj[u].push_back(edges.size()), edges.emplace_back(u, v, c)
        do_add(u, v, c), do_add(v, u, 0);
    }
    
    inline bool bfs() {
        fill(level, level + n, -1);
        q.push(s), level[s] = 0;
        while (!q.empty()) {
            int u = q.front(); q.pop();
            for (auto id : adj[u]) {
                int v = edges[id].v;
                if (level[v] == -1 && edges[id].f < edges[id].c)
                    q.push(v), level[v] = level[u] + 1;
            }
        }
        return level[t] != -1;
    }
    
    int64_t dfs(int u, int64_t push) {
        if (push == 0) return 0;
        if (u == t) return push;
        for (int &i = ptr[u]; i < adj[u].size(); i++) {
            int id = adj[u][i], v = edges[id].v;
            if (level[v] == level[u] + 1 && edges[id].f < edges[id].c) {
                if (int64_t nxt_push = dfs(v, min(push, edges[id].c - edges[id].f))) {
                    edges[id].f += nxt_push, edges[id ^ 1].f -= nxt_push; return nxt_push;
                }
            }
        }
        return 0;
    }
    
    int64_t maxflow(int _s, int _t) {
        s = _s, t = _t;
        for (auto &ed : edges) ed.f = 0;
        
        int64_t res = 0;
        while (bfs()) {
            fill(ptr, ptr + n, 0);
            while (int64_t push = dfs(s, inf))
                res += push;
        }
        return res;
    }
} dinic;

int n, a[N], lrb, isp[M], vis[N];
vector<int> nxt[N], d;
 
void dfs(int u) {
	vis[u] = 1;
	d.emplace_back(u);
	for (auto v : nxt[u])
		if (!vis[v]) dfs(v);
}
 
void Hollwo_Pelw() {
	for (int i = 2; i < M; i++) isp[i] = 1;
	for (int i = 2; i < M; i++) if (isp[i]) 
		for (int j = 2 * i; j < M; j += i) isp[j] = 0;
 
	cin >> n;
	vector<int> odd, even;
	for (int i = 1; i <= n; i ++)
		cin >> a[i], (a[i] & 1 ? odd : even).push_back(i);
	
	if (odd.size() != even.size())
		return cout << "Impossible", (void) 0;
 
	for (int i = 1; i <= n; i++) {
		if (a[i] & 1)
			dinic.add_edge(0, i, 2);
		else 
			dinic.add_edge(i, n + 1, 2);
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (isp[a[i] + a[j]] && (a[i] & 1))
				dinic.add_edge(i, j, 1);
	if (dinic.maxflow(0, n + 1) != n)
		return cout << "Impossible", (void) 0;
	vector<vector<int>> res;
	for (int i = 1; i <= n; i++) {
		for (auto j : dinic.adj[i]) {
			if (dinic.edges[j].f && dinic.edges[j].v != n + 1 && dinic.edges[j].v != 0)
				nxt[i].push_back(dinic.edges[j].v);
		}
	}
	for (int i = 1; i <= n; i++)
		if (!vis[i]) d.clear(), dfs(i), res.emplace_back(d);
 
	cout << res.size() << '\n';
	for (auto v : res) {
		cout << v.size() << ' ';
		for (auto x : v)
			cout << x << ' ';
		cout << '\n';
	}
}
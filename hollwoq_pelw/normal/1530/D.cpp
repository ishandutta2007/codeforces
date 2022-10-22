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
	cin >> testcases;
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


const int N = 2e5 + 5;
const int inf = 2e9;

struct flow_edge {
    int u, v; int c, f;
    flow_edge () {}
    flow_edge (int _u, int _v, int _c)
        : u(_u), v(_v), c(_c), f(0) {}
};

struct Dinic {
    int n, s, t;
    vector<int> level, ptr;
    
    vector<flow_edge> edges;
    vector<vector<int>> adj;

    queue<int> q;

    Dinic () : n(N - 1) {}
    Dinic (int _n) : n(_n) {
    	level.resize(n + 1);
    	ptr.resize(n + 1);
    	adj.resize(n + 1);
    }

    void add(int u, int v, int c) {
        adj[u].push_back(edges.size());
        edges.emplace_back(u, v, c);
    }

    void add_edge(int u, int v, int c) {
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

    int dfs(int u, int push) {
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

    int maxflow(int _s, int _t) {
        s = _s, t = _t;
        int ans = 0;
        while (bfs()) {
            for (int i = 0; i <= n; i++) ptr[i] = 0;
            while (int push = dfs(s, inf))
                ans += push;
        }
        return ans;
    }
};

int n, a[N], b[N], visa[N], visb[N];

void Hollwo_Pelw(){
	cin >> n;
	Dinic dd(2 * n + 3);

	for (int i = 1; i <= n; i++) {
		dd.add_edge(0, i, 1);
		dd.add_edge(i + n, 2 * n + 1, 1);
	}

	for (int i = 1; i <= n; ++ i) {
		cin >> a[i];
		b[i] = visa[i] = visb[i] = 0;
		dd.add_edge(i, a[i] + n, 1);
	}

	cout <<	dd.maxflow(0, 2 * n + 1) << '\n';

	for (auto ed : dd.edges)
		if (0 < ed.u && ed.u <= n && n < ed.v && ed.v <= 2 * n && ed.f)
			b[ed.u] = ed.v - n, visa[ed.v - n] = 1;

	set<int> st;
	for (int i = 1; i <= n; i++) {
		if (!visa[i]) st.insert(i);
		visb[i] = b[i];
	}

    for (int i = 1; i <= n; i++) {
        if (!b[i]) {
            if (st.size() == 1) {
                int va = *st.begin();
                if (i == va) {
                    for (int j = 1; j <= n; j++) {
                        if (i == j) continue;
                        if (!visb[j]) {
                            b[i] = b[j];
                            b[j] = i;
                            break;
                        } else if (a[i] == b[j]) {
                            b[j] = i;
                            b[i] = a[i];
                            break;
                        }
                    }
                } else {
                	b[i] = va;
                }
                break;
            }
            else {
                int va = *st.begin();
                int vb = *next(st.begin()); 
                if (i == va) 
                	b[i] = vb, st.erase(vb);
                else 
                	b[i] = va, st.erase(va);
            }
        }
    }

	for (int i = 1; i <= n; i++)
		cout << b[i] << " \n"[i == n];
}
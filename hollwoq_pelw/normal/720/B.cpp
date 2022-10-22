/*
 /+==================================================+\
//+--------------------------------------------------+\\
|.|\\...>>>>>>> Hollwo_Pelw(ass) 's code <<<<<<<...//|.|
\\+--------------------------------------------------+//
 \+==================================================+/
*/
#include <bits/stdc++.h>
using namespace std;
// pragma
#pragma GCC optimize ("O3")
// type
typedef long long ll;
typedef long double ld;
// loop
//#define For(i, l, r)        for (int i = l; i < r; i++)
//#define ForE(i, l, r)       for (int i = l; i <= r; i++)
//#define Ford(i, r, l)       for (int i = r; i > l; i--)
//#define FordE(i, r, l)      for (int i = r; i >= l; i--)
//#define Fora(i, a)          for (auto i : a)
// I/O
#define open(file, in, out) if (fopen(file in, "r")) {        \
                                freopen(file in, "r", stdin);  \
                                freopen(file out, "w", stdout); \
                            }
#define FAST_IO             std::ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define setpre(n)           fixed << setprecision(n)
// pair
#define F                   first
#define S                   second
#define pii                 pair<int, int>
#define pll                 pair<ll, ll>
#define pdd                 pair<ld, ld>
// vector & !!?(string)
#define eb                  emplace_back
#define pb                  push_back
#define all(a)              a.begin(), a.end()
#define rall(a)             a.rbegin(), a.rend()
#define sz(a)               a.size()
#define len(a)              a.length()
// geometry calculate
#define pi                  acos(-1.0)
#define g_sin(a)            sin(a*pi/180)
#define g_cos(a)            cos(a*pi/180)
#define g_tan(a)            tan(a*pi/180)
// set val
#define ms0(a)              memset(a,        0, sizeof(a));
#define ms1(a)              memset(a,        1, sizeof(a));
#define msn1(a)             memset(a,       -1, sizeof(a));
#define msinf(a)            memset(a, 0x3f3f3f, sizeof(a));
// constant
const int mod1 = 998244353, mod = 1e9+7;
const int MAXN = 100005, MAXM = 200010;
// code
//#define int long long


struct Edge{
    int u, v, c, f;
    Edge(int u, int v, int c) : u(u), v(v), c(c), f(0){}
    int nxt(int x) {return u^v^x;}
};

struct Maxflow{
	int N, S, T, par[MAXM], p[MAXM];
	vector<int> g[MAXM];
	vector<Edge> E;
	void addEdge(int u, int v, int c){
		g[u].pb(sz(E));		E.pb({u, v, c});
		g[v].pb(sz(E)); 	E.pb({v, u, 0});
	}
    void init(int _n,int _S,int _T) {
        N = _n;
        S = _S;
        T = _T;
//        for(int i = 0 ; i <= N ; ++i)
//            g[i].clear();
//        E.clear();
    }
	int bfs(){
		for (int i = 0; i <= N; i++)
			par[i] = -1;

		par[S] = 0;
		queue<int> q;
		q.push(S);
		while(!q.empty()){
			int u = q.front(); q.pop();
			for (auto id:g[u]){
				int v = E[id].v;
				if (par[v] < 0 && E[id].c > E[id].f){
					par[v] = par[u] + 1;
					q.push(v);
				}
			}
		}
		return par[T] != -1;
	}

//	int upd(){
//		int res = INT_MAX, u = T;
//		while (u != S){
//			int i = par[u];
//			u = E[i].u;
//			res = min(res, E[i].c-E[i].f);
//		}
//		u = T;
//		while (u != S){
//			int i = par[u];
//			u = E[i].u;
//			E[i].f += res; E[i^1].f -= res; // update edge flow
//		}
//		return res;
//	}

    int dfs(int u, int flow) {
        if(u == T)
            return flow;
        for (int &i = p[u]; i < g[u].size(); i ++) {
            int id = g[u][i], v = E[id].v;
            if(par[v] == par[u] + 1 && E[id].c > E[id].f) {
                int val = dfs(v, min(flow, E[id].c - E[id].f));
                if(val) {
                    E[id].f += val;
                    E[id ^ 1].f -= val;
                    return val;
                }
            }
        }
        return 0;
    }

    int maxflow() {
        int ans = 0, x;
        while (bfs()) {
            for (int i = 0; i < N; i ++)
                p[i] = 0;
            while (x = dfs(S, mod)) {
                ans += x;
            }
        }
        return ans;
    }
} Flow;

vector<Edge> E;
vector<int> g[MAXN];
int n, m, par[MAXN], used[MAXN], vis[MAXN], cur;

void dfs(int u) {
    vis[u] = 1;
    for (int i = 0; i < g[u].size(); i ++) {
        int id = g[u][i];
        if(used[id]) continue;
        used[id] = 1;
        int v = E[id].nxt(u);
        if(vis[v]) {
            cur ++;
            int t = u, sz = 0;
            //cout << v << endl;
            while (t != v) {
                used[par[t]] = 2;
                Flow.addEdge(cur, E[par[t]].c + n, mod);
                t = E[par[t]].nxt(t);
                sz ++;
            }
            Flow.addEdge(cur, E[id].c + n, mod);
            used[id] = 2;
            Flow.addEdge(Flow.S, cur, sz);
        }
        else {
            par[v] = id;
            dfs(v);
        }
    }
}


void Solve() {
    cin >> n >> m;
    for (int i = 0, u, v, c; i < m; i ++) {
        cin >> u >> v >> c;
        E.pb(Edge(u, v, c));
        g[u].pb(i); g[v].pb(i);
    }
    Flow.init(n + m + 2, 0, n + m + 1);
    dfs(1);
    for (int i = 0; i < m; i ++) if(used[i] == 1)
        Flow.addEdge(Flow.S, E[i].c + n, mod);
    for (int i = 1; i <= m; i ++)
        Flow.addEdge(n + i, Flow.T, 1);

    cout << Flow.maxflow();
}

signed main(){
    open("", ".inp", ".out");
    FAST_IO; int TC = 1;
    //cin >> TC;
    while(TC--) Solve();
    return 0;
}
/*
./-=====>>><<<-------- DEBUG -------->>><<<=====-\.
/.................................................\

+====================== INP ======================+


+====================== OUT ======================+


\................................................./
.\-=====>>><<<--------= END =-------->>><<<=====-/.
*/
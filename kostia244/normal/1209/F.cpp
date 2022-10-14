#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<20, mod = 1e9 + 7, rt = 565042129, i2 = (mod+1)/2;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct tree {
	int par[maxn][20], col[maxn], go[maxn][10], val[maxn], h[maxn], sz;
	tree() {
		memset(par, 0, sizeof par);
		memset(col, 0, sizeof col);
		memset(val, 0, sizeof val);
		memset(go, 0, sizeof go);
		memset(h, 0, sizeof h);
		sz = 1;
	}
	void newnode(int p, int c) {
		val[sz] = (val[p]*10ll + c)%mod;
		h[sz] = h[p]+1;
		go[p][c] = sz;
		par[sz][0] = p;
		col[sz] = c;
		for(int i = 1; i < 20; i++) par[sz][i] = par[par[sz][i-1]][i-1];
		sz++;
	}
	int add(int cur, int x) {
		string s = to_string(x);
		for(auto &i : s) {
			i -= '0';
			if(!go[cur][i]) go[cur][i] = sz, newnode(cur, i);
			cur = go[cur][i];
		}
		return cur;
	}
	bool less(int u, int v) {
		if(h[u] < h[v]) return 1;
		if(h[u] > h[v]) return 0;
		if(u == v) return 0;
		for(int i = 20; i--;) if(par[u][i]!=par[v][i]) u = par[u][i], v = par[v][i];
		return col[u] < col[v];
	}
};
int n, m;
const int INF = 1000000000;
vector<vector<pair<int, int>>> adj;
vi topo, dist, par;
void dijkstra(int s, vector<int> & d, vector<int> & p) {
    int n = adj.size();
    d.assign(n, INF);
    p.assign(n, -1);

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
                q.push({d[to], to});
            }
        }
        if(v != 1)
			topo.pb(v);
    }
}

tree x;
int ans[maxn], nd[maxn];
vector<pair<int, int>> g[maxn];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	adj.resize(n+1);
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(pair<int, int>{t, i+1});
		g[t].pb(pair<int, int>{f, i+1});
		adj[f].pb(pair<int, int>{t, to_string(i+1).size()});
		adj[t].pb(pair<int, int>{f, to_string(i+1).size()});
	}
	dijkstra(1, dist, par);
	for(auto i : topo) {
		int cur = -1;
		for(auto &_j : g[i]) {
			auto [j, l] = _j;
			if(dist[j] >= dist[i]) continue;
			int t = x.add(nd[j], l);
			if(cur == -1 || x.less(t, cur)) cur = t;
		}
		nd[i] = cur;
		ans[i] = x.val[cur];
	}
	for(int i = 2; i <= n; i++) cout << ans[i] << '\n';
}
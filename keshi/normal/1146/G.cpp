//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

struct Flow{
	struct edge{
		ll from, to, cap;
	};
	vector<edge> e;
	vector<ll> ptr, q, d, par;
	vector<bool> vis;
	vector<vector<ll> > g;
	void init(ll N){
		ptr.resize(N);
		par.resize(N);
		q.resize(N);
		d.resize(N);
		g.resize(N);
		vis.resize(N);
	}
	void add_edge(ll v, ll u, ll cap){
		assert(cap >= 0);
		g[v].pb(Sz(e));
		e.pb({v, u, cap});
		g[u].pb(Sz(e));
		e.pb({u, v, 0});
	}
	bool spfa(ll s, ll t){
		fill(all(vis), 0);
		fill(all(d), inf);
		fill(all(par), -1);
		ll ql = 0, qr = 0;
		d[s] = 0;
		vis[s] = 1;
		q[qr++] = s;
		bool f = 0;
		while(ql != qr){
			ll v = q[ql++];
			vis[v] = 0;
			if(v == t) f = 1;
			if(ql == Sz(q)) ql = 0;
			for(ll id : g[v]){
				ll u = e[id].to;
				if(d[u] > d[v] + 1 && e[id].cap > 0){
					d[u] = d[v] + 1;
					par[u] = id;
					if(!vis[u]){
						vis[u] = 1;
						q[qr++] = u;
						if(qr == Sz(q)) qr = 0;
					}
				}
			}
		}
		return f;
	}
	ll dfs(ll v, ll t, ll flow){
		if(!flow) return 0;
		if(v == t) return flow;
		for(; ptr[v] < Sz(g[v]); ptr[v]++){
			ll id = g[v][ptr[v]], u = e[id].to;
			if(e[id].cap <= 0 || d[u] != d[v] + 1) continue;
			ll p = dfs(u, t, min(flow, e[id].cap));
			if(p){
				e[id].cap -= p;
				e[id^1].cap += p;
				return p;
			}
		}
		return 0;
	}
	ll dinic(ll s, ll t){
		ll flow = 0;
		while(spfa(s, t)){
			fill(all(ptr), 0);
			while(ll p = dfs(s, t, inf)){
				flow += p;
			}
		}
		return flow;
	}
} flow;

int n, h, m, ptr, a[maxn][maxn];

int main(){
	fast_io;
	
	cin >> n >> h >> m;
	flow.init((n + 1) * (h + 1) + m + 10);
	int src = ptr++;
	for(int i = 0; i < n; i++){
		for(int j = 1; j <= h; j++){
			a[i][j] = ptr++;
			flow.add_edge(0, a[i][j], j * j - (j - 1) * (j - 1));
			if(j > 1){
				flow.add_edge(a[i][j], a[i][j - 1], inf / 100);
			}
		}
	}
	int snk = ptr++;
	for(int i = 0; i < m; i++){
		int l, r, x, c;
		cin >> l >> r >> x >> c;
		if(x == h) continue;
		l--;
		for(int j = l; j < r; j++){
			flow.add_edge(a[j][x + 1], ptr, inf / 100);
		}
		flow.add_edge(ptr, snk, c);
		ptr++;
	}
	cout << n * h * h - flow.dinic(src, snk);
	
	return 0;
}
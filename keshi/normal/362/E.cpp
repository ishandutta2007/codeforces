//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 200;
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

struct Flow{
	struct edge{
		ll from, to, cap, cost, flow;
	};
	vector<edge> e;
	vector<ll> ptr, q, d, par;
	vector<bool> vis;
	vector<vector<ll> > g;
	void init(ll N){
		q.resize(N + N);
		d.resize(N);
		g.resize(N);
		vis.resize(N);
		ptr.resize(N);
		par.resize(N);
	}
	void add_edge(ll v, ll u, ll cap, ll cost){
		assert(cap >= 0);
		g[v].pb(Sz(e));
		e.pb({v, u, cap, cost, 0});
		g[u].pb(Sz(e));
		e.pb({u, v, 0, -cost, 0});
	}
	bool spfa(ll s, ll t){
		fill(all(vis), 0);
		fill(all(par), -1);
		ll ql = 0, qr = 0;
		vis[s] = 1;
		d[s] = 0;
		q[qr++] = s;
		while(ql != qr){
			ll v = q[ql++];
			if(ql == Sz(q)) ql = 0;
			for(ll i = 0; i < Sz(g[v]); i++){
				ll id = g[v][i], u = e[id].to, c = e[id].cost;
				if(e[id].cap == e[id].flow) continue;
				if(!vis[u] || d[u] > d[v] + c){
					vis[u] = 1;
					d[u] = d[v] + c;
					q[qr++] = u;
					par[u] = id;
					if(qr == Sz(q)) qr = 0;
				}
			}
		}
		return vis[t];
	}
	ll dfs(ll v, ll t, ll flow){
		if(!flow) return 0;
		if(v == t) return flow;
		for(; ptr[v] < Sz(g[v]); ptr[v]++){
			ll id = g[v][ptr[v]], u = e[id].to, c = e[id].cost;
			if(id != par[u]) continue;
			ll p = dfs(u, t, min(flow, e[id].cap - e[id].flow));
			if(p){
				e[id].flow += p;
				e[id^1].flow -= p;
				return p;
			}
		}
		return 0;
	}
	pll dinic(ll s, ll t){
		ll flow = 0, cost = 0;
		while(spfa(s, t)){
			fill(all(ptr), 0);
			while(ll p = dfs(s, t, inf)){
				flow += p;
				cost += p * d[t];
			}
		}
		return Mp(flow, cost);
	}
	ll solve(ll s, ll t, ll x){
		ll flow = 0, cost = 0;
		while(spfa(s, t)){
			fill(all(ptr), 0);
			if(cost + d[t] > x) return flow;
			while(ll p = dfs(s, t, (d[t] ? (x - cost) / d[t] : inf))){
				flow += p;
				cost += p * d[t];
			}
		}
		return flow;
	}
};

ll n, k, a[maxn][maxn], b[maxn][maxn];
Flow flow;

int main(){
	//fast_io;
    
    cin >> n >> k;
    flow.init(n);
    for(ll i = 0; i < n; i++){
    	for(ll j = 0; j < n; j++){
    		cin >> a[i][j];
    		if(a[i][j] == 0) continue;
    		b[i][j] = inf;
    		flow.add_edge(i, j, a[i][j], 0);
    		flow.add_edge(i, j, inf, 1);
		}
	}
	cout << flow.solve(0, n - 1, k);
	
    return 0;
}
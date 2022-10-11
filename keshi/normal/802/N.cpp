//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
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
		ptr.resize(N);
		par.resize(N);
		q.resize(N);
		d.resize(N);
		g.resize(N);
		vis.resize(N);
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
				ll u = e[id].to, c = e[id].cost;
				if(d[u] > d[v] + c && e[id].cap > e[id].flow){
					d[u] = d[v] + c;
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
		ll pp = 0;
		for(; ptr[v] < Sz(g[v]); ptr[v]++){
			ll id = g[v][ptr[v]], u = e[id].to;
			if(par[u] != id) continue;
			ll p = dfs(u, t, min(flow, e[id].cap - e[id].flow));
			if(p){
				e[id].flow += p;
				e[id^1].flow -= p;
				pp += p;
				flow -= p;
			}
		}
		return pp;
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
} flow;

ll n, k, a[maxn], b[maxn];

int main(){
	fast_io;
	
	cin >> n >> k;
	
	flow.init(n + n + 3);
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		flow.add_edge(0, i, 1, a[i]);
		flow.add_edge(i, n + i, 1, 0);
	}
	for(ll i = 1; i <= n; i++){
		cin >> b[i];
		flow.add_edge(n + i, n + n + 1, 1, b[i]);
		if(i > 1) flow.add_edge(n + i - 1, n + i, inf, 0);
	}
	flow.add_edge(n + n + 1, n + n + 2, k, 0);
	cout << flow.dinic(0, n + n + 2).S;
	
	return 0;
}
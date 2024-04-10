//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pll;

const ll maxn = 1e5;
const ll mod = 1e9 + 7;
const ll inf = 1e18;
const ld eps = 1e-4;

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
		ll from, to, cap, flow;
		ld cost;
	};
	vector<edge> e;
	vector<ll> ptr, par;
	vector<ld> d;
	vector<bool> vis;
	vector<vector<ll> > g;
	void init(ll N){
		d.resize(N);
		g.resize(N);
		vis.resize(N);
		ptr.resize(N);
		par.resize(N);
	}
	void add_edge(ll v, ll u, ll cap, ld cost){
		assert(cap >= 0);
		g[v].pb(Sz(e));
		e.pb({v, u, cap, 0, cost});
		g[u].pb(Sz(e));
		e.pb({u, v, 0, 0, -cost});
	}
	bool spfa(ll s, ll t){
		fill(all(vis), 0);
		fill(all(par), -1);
		fill(all(d), inf);
		queue<ll> q;
		vis[s] = 1;
		d[s] = 0;
		q.push(s);
		vis[s] = 1;
		ll c = 0;
		while(!q.empty()){
			ll v = q.front();
			q.pop();
			vis[v] = 0;
			c++;
			if(c > maxn){
			    cout << "oh\n";
			    exit(0);
			}
			for(ll i = 0; i < Sz(g[v]); i++){
				ll id = g[v][i], u = e[id].to;
				ld c = e[id].cost;
				if(e[id].cap == e[id].flow) continue;
				if(d[u] - (d[v] + c) > eps){
					d[u] = d[v] + c;
					if(!vis[u]){
						q.push(u);
						vis[u] = 1;
					}
					par[u] = id;
				}
			}
		}
		return (d[t] < inf);
	}
	ll dfs(ll v, ll t, ll flow){
		if(!flow) return 0;
		if(v == t) return flow;
		for(; ptr[v] < Sz(g[v]); ptr[v]++){
			ll id = g[v][ptr[v]], u = e[id].to;
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
	pair<ll, ld> dinic(ll s, ll t){
		ll flow = 0;
		ld cost = 0;
		while(spfa(s, t)){
			fill(all(ptr), 0);
			while(ll p = dfs(s, t, inf)){
				flow += p;
				cost += p * d[t];
			}
		}
		return Mp(flow, cost);
	}
};

ll n, x[maxn], y[maxn];
Flow flow;

int main(){
	fast_io;
	cout << setprecision(15) << fixed;
    
    cin >> n;
    flow.init(n + n + 2);
    for(ll i = 1; i <= n; i++){
    	cin >> x[i] >> y[i];
    	flow.add_edge(0, i, 2, 0);
    	flow.add_edge(n + i, n + n + 1, 1, 0);
	}
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			if(y[i] > y[j]){
				flow.add_edge(i, j + n, 1, pow((y[i] - y[j]) * (y[i] - y[j]) + (x[i] - x[j]) * (x[i] - x[j]), 0.5));
			}
		}
	}
    
	pair<ll, ld> p = flow.dinic(0, n + n + 1);
	if(p.F != n - 1){
		cout << "-1";
	}
	else cout << p.S;
	
    return 0;
}
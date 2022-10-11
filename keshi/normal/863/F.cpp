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
		for(; ptr[v] < Sz(g[v]); ptr[v]++){
			ll id = g[v][ptr[v]], u = e[id].to;
			if(par[u] != id) continue;
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
} flow;

int n, q;
bool nok[maxn][maxn];

int main(){
	fast_io;
	
	cin >> n >> q;
	flow.init(n + n + 2);
	for(int i = 0; i < q; i++){
		int t, l, r, x;
		cin >> t >> l >> r >> x;
		l--;
		if(t == 1){
			for(int j = l; j < r; j++){
				for(int k = 1; k < x; k++){
					nok[j][k] = 1;
				}
			}
		}
		else{
			for(int j = l; j < r; j++){
				for(int k = x + 1; k <= n; k++){
					nok[j][k] = 1;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			flow.add_edge(0, i, 1, j * j - (j - 1) * (j - 1));
		}
		for(int j = 0; j < n; j++){
			if(!nok[j][i]){
				flow.add_edge(i, n + 1 + j, 1, 0);
			}
		}
	}
	for(int i = 0; i < n; i++){
		flow.add_edge(n + 1 + i, n + n + 1, 1, 0);
	}
	pll p = flow.dinic(0, n + n + 1);
	if(p.F == n){
		cout << p.S;
	}
	else cout << -1;
	
	return 0;
}
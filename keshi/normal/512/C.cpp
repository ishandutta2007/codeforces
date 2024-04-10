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
		ll from, to, cap, flow;
	};
	vector<edge> e;
	vector<ll> ptr, q, d, par;
	vector<vector<ll> > g;
	void init(ll N){
		ptr.resize(N);
		par.resize(N);
		q.resize(N);
		d.resize(N);
		g.resize(N);
	}
	void add_edge(ll v, ll u, ll cap){
		assert(cap >= 0);
		g[v].pb(Sz(e));
		e.pb({v, u, cap, 0});
		g[u].pb(Sz(e));
		e.pb({u, v, 0, 0});
	}
	bool bfs(ll s, ll t){
		fill(all(d), inf);
		fill(all(par), -1);
		ll ql = 0, qr = 0;
		d[s] = 0;
		q[qr++] = s;
		bool f = 0;
		while(ql != qr){
			ll v = q[ql++];
			if(v == t) f = 1;
			for(ll id : g[v]){
				ll u = e[id].to;
				if(d[u] > d[v] + 1 && e[id].cap > e[id].flow){
					d[u] = d[v] + 1;
					par[u] = id;
					q[qr++] = u;
				}
			}
		}
		return f;
	}
	ll dfs(ll v, ll t, ll flow){
		if(!flow) return 0;
		if(v == t) return flow;
		for(; ptr[v] < Sz(g[v]);){
			ll id = g[v][ptr[v]++], u = e[id].to;
			if(d[u] != d[v] + 1) continue;
			ll p = dfs(u, t, min(flow, e[id].cap - e[id].flow));
			if(p){
				e[id].flow += p;
				e[id^1].flow -= p;
				return p;
			}
		}
		return 0;
	}
	ll dinic(ll s, ll t){
		ll flow = 0;
		while(bfs(s, t)){
			fill(all(ptr), 0);
			while(ll p = dfs(s, t, inf)){
				flow += p;
			}
		}
		return flow;
	}
} flow;

ll n, a[maxn], p[maxn], vis[maxn];
vector<ll> vec[2];
vector<ll> g[maxn], vv;
vector<vector<ll> > ans;
void dfs(ll v){
	vis[v] = 1;
	vv.pb(v);
	for(ll u : g[v]){
		if(!vis[u]) dfs(u);
	}
}

int main(){
    fast_io;
    
    for(ll i = 2; i * i < maxn; i++){
    	if(p[i]) continue; 
    	for(ll j = i * i; j < maxn; j += i){
    		p[j] = 1;
		}
	}
    
    cin >> n;
    for(ll i = 0; i < n; i++){
    	cin >> a[i];
    	vec[a[i] & 1].pb(i);
	}
	if(Sz(vec[0]) != Sz(vec[1])){
		cout << "Impossible\n";
		return 0;
	}
	flow.init(n + 2);
	for(ll i = 0; i < n / 2; i++){
		flow.add_edge(0, i + 1, 2);
		flow.add_edge(n / 2 + 1 + i, n + 1, 2);
		for(ll j = 0; j < n / 2; j++){
			if(p[a[vec[0][i]] + a[vec[1][j]]] == 0){
				flow.add_edge(i + 1, n / 2 + 1 + j, 1);
			}
		}
	}
	if(flow.dinic(0, n + 1) != n){
		cout << "Impossible\n";
		return 0;
	}
	for(auto e : flow.e){
		if(e.flow == 1){
			g[e.from].pb(e.to);
			g[e.to].pb(e.from);
		}
	}
	for(ll i = 1; i <= n; i++){
		if(vis[i]) continue;
		vv.clear();
		dfs(i);
		for(ll j = 0; j < Sz(vv); j++){
			if(vv[j] <= n / 2) vv[j] = vec[0][vv[j] - 1];
			else vv[j] = vec[1][vv[j] - n / 2 - 1];
		}
		ans.pb(vv);
	}
	cout << Sz(ans) << "\n";
	for(auto i : ans){
		cout << Sz(i) << " ";
		for(ll j : i){
			cout << j + 1 << " ";
		}
		cout << "\n";
	}
 
    return 0;
}
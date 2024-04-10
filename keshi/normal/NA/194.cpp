//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e5;
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
	vector<ll> ptr, q, d;
	vector<vector<ll> > g;
	void init(ll N){
		ptr.resize(N);
		q.resize(N);
		d.resize(N);
		g.resize(N);
	}
	void add_edge(ll v, ll u, ll cap){
		g[v].pb(Sz(e));
		e.pb({v, u, cap, 0});
		g[u].pb(Sz(e));
		e.pb({u, v, 0, 0});
	}
	bool bfs(ll s, ll t){
		fill(all(d), -1);
		ll ql = 0, qr = 0;
		q[qr++] = s;
		d[s] = 0;
		while(ql < qr && d[t] == -1){
			ll v = q[ql++];
			for(ll i = 0; i < Sz(g[v]); i++){
				ll id = g[v][i], u = e[id].to;
				if(d[u] == -1 && e[id].flow < e[id].cap){
					d[u] = d[v] + 1;
					q[qr++] = u;
				}
			}
		}
		return (d[t] != -1);
	}
	ll dfs(ll v, ll t, ll flow){
		if(!flow) return 0;
		if(v == t) return flow;
		ll x = 0;
		for(; ptr[v] < Sz(g[v]); ptr[v]++){
			ll id = g[v][ptr[v]], u = e[id].to;
			if(d[u] != d[v] + 1) continue;
			ll p = dfs(u, t, min(flow, e[id].cap - e[id].flow));
			x += p;
			e[id].flow += p;
			e[id^1].flow -= p;
			flow -= p;
		}
		return x;
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
};

ll n, match[maxn];
vector<ll> vec[maxn];
Flow mat, flow;

int main(){
    //fast_io;
	
	cin >> n;
	mat.init(n + n + 2);
	for(ll i = 1; i <= n; i++){
		ll x;
		cin >> x;
		vec[i].resize(x);
		mat.add_edge(0, i, 1);
		mat.add_edge(n + i, n + n + 1, 1);
		for(ll j = 0; j < x; j++){
			cin >> vec[i][j];
			mat.add_edge(i, n + vec[i][j], 1);
		}
	}
	mat.dinic(0, n + n + 1);
	for(ll i = 1; i <= n; i++){
		for(ll j2 = 0; j2 < Sz(mat.g[i]); j2++){
			ll j = mat.g[i][j2];
			if(mat.e[j].flow){
				match[i] = mat.e[j].to;
				match[mat.e[j].to] = i;
			}
		}
	}
	flow.init(n + 2);
	ll s = 0;
	for(ll i = 1; i <= n; i++){
		for(ll j = 0; j < Sz(vec[i]); j++){
			if(n + vec[i][j] != match[i]){
				flow.add_edge(i, match[n + vec[i][j]], inf);
			}
		}
		ll x;
		cin >> x;
		if(x < 0){
			flow.add_edge(0, i, -x);
			s += x;
		}
		else{
			flow.add_edge(i, n + 1, x);
		}
	}
	cout << flow.dinic(0, n + 1) + s;
	
    return 0;
}
//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 3100;
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
};

ll n, a[maxn], b[maxn], ls[maxn];
Flow flow;

int main(){
    fast_io;

	cin >> n;
	flow.init(n + 2);
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		for(ll j = 1; j <= 100; j++){
			if(ls[j] && a[i] % j == 0){
				flow.add_edge(i, ls[j], inf);
			}
		}
		ls[a[i]] = i;
	}
	ll x = 0;
	for(ll i = 1; i <= n; i++){
		cin >> b[i];
		if(b[i] < 0){
			flow.add_edge(i, n + 1, -b[i]);
		}
		else{
			flow.add_edge(0, i, b[i]);
			x += b[i];
		}
	}
	cout << x - flow.dinic(0, n + 1);

    return 0;
}
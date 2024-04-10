//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;
const ll lg = 18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, q, k, a[maxn], st[maxn], ft[maxn], t, h[maxn], par[maxn][lg], bad[maxn], ans, vis[maxn];
vector<ll> g[maxn], g2[maxn];

void dfs(ll v){
	st[v] = t++;
	for(ll i = 1; (1 << i) <= h[v]; i++){
		par[v][i] = par[par[v][i - 1]][i - 1];
	}
	for(ll u : g[v]){
		if(u == par[v][0]) continue;
		par[u][0] = v;
		h[u] = h[v] + 1;
		dfs(u);
	}
	ft[v] = t;
}

ll lca(ll v, ll u){
	if(h[v] < h[u]) swap(v, u);
	ll d = h[v] - h[u];
	for(ll i = 0; i < lg; i++){
		if((d >> i) & 1) v = par[v][i];
	}
	for(ll i = lg; i--;){
		if(h[v] >= (1 << i) && par[v][i] != par[u][i]){
			v = par[v][i];
			u = par[u][i];
		}
	}
	if(v == u) return v;
	return par[v][0];
}

ll solve(ll v, ll p){
	vis[v] = 1;
	if(bad[v]) return 1;
	ll c = 0;
	for(ll u : g2[v]){
		if(u == p) continue;
		c += solve(u, v);
	}
	if(c > 1){
		ans++;
		return 0;
	}
	return c;
}

int main(){
	fast_io;
	
	cin >> n;
	for(ll i = 1; i < n; i++){
		ll v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1);
	cin >> q;
	while(q--){
		cin >> k;
		set<pll> s;
		for(ll i = 0; i < k; i++){
			cin >> a[i];
			bad[a[i]] = 1;
			s.insert(Mp(st[a[i]], a[i]));
		}
		{	
			auto it = s.begin();
			for(ll i = 0; i < k; i++){
				a[i] = it -> S;
				it++;
			}
		}
		bool ok = 1;
		for(ll i = 0; i < k; i++){
			if(s.find(Mp(st[par[a[i]][0]], par[a[i]][0])) != s.end()) ok = 0;
		}
		if(!ok){
			for(pll i : s){
				bad[i.S] = 0;
				g2[i.S].clear();
			}
			cout << "-1\n";
			continue;
		}
		for(ll i = 0; i < k; i++){
			ll v = a[i];
			if(v != 1) s.insert(Mp(st[par[v][0]], par[v][0]));
		}
		for(ll i = 1; i < k; i++){
			ll v = lca(a[i], a[i - 1]);
			s.insert(Mp(st[v], v));
		}
		vector<ll> vec;
		for(pll i : s){
			while(!vec.empty() && st[i.S] >= ft[vec.back()]) vec.pop_back();
			if(!vec.empty()){
				g2[i.S].pb(vec.back());
				g2[vec.back()].pb(i.S);
			}
			vec.pb(i.S);
		}
		ans = 0;
		for(pll i : s){
			if(!vis[i.S]) solve(i.S, 0);
		}
		cout << ans << "\n";
		for(pll i : s){
			bad[i.S] = 0;
			vis[i.S] = 0;
			g2[i.S].clear();
		}
	}
	
	
	return 0;
}
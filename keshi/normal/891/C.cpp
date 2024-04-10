//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 5e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, q, t, a[maxn], dsu[maxn], sz[maxn];

bool f[maxn];

pair<pll, ll> e[maxn];

vector<ll> g[maxn], o[maxn], h[maxn];

vector<pll> st;

void init(){
	for(ll i = 1; i <= n; i++){
		dsu[i] = i;
		sz[i] = 1;
	}
}

ll root(ll v){
	if(dsu[v] == v) return v;
	return root(dsu[v]);
}

bool Union(ll v, ll u){
	ll x = root(v), y = root(u);
	if(x == y) return 1;
	if(sz[x] < sz[y]) swap(x, y);
	sz[x] += sz[y];
	dsu[y] = x;
	st.pb({x, y});
	return 0;
}

void Undo(){
	ll x, y;
	while(!st.empty()){
		x = st.back().F;
		y = st.back().S;
		sz[x] -= sz[y];
		dsu[y] = y;
		st.pop_back();
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	
	init();
	
	for(ll i = 1; i <= m; i++){
		cin >> e[i].F.F >> e[i].F.S >> e[i].S;
		g[e[i].S].pb(i);
	}
	
	cin >> q;
	
	for(ll i = 0; i < q; i++){
		cin >> t;
		for(ll j = 0; j < t; j++){
			cin >> a[j];
			h[e[a[j]].S].pb(a[j]);
		}
		for(ll j = 0; j < t; j++){
			v = e[a[j]].S;
			if(!h[v].empty()){
				o[v].pb(i);
				o[v].pb(h[v].size());
				for(ll k = 0; k < h[v].size(); k++){
					o[v].pb(h[v][k]);
				}
				h[v].clear();
			}
		}
	}
	
	for(ll i = 1; i < maxn; i++){
		ll j = 0;
		while(j < o[i].size()){
			st.clear();
			v = o[i][j++];
			t = o[i][j++];
			for(ll k = 0; k < t; k++){
				if(Union(e[o[i][j]].F.F, e[o[i][j]].F.S)) f[v] = 1;
				j++;
			}
			Undo();
		}
		for(ll j = 0; j < g[i].size(); j++){
			Union(e[g[i][j]].F.F, e[g[i][j]].F.S);
		}
	}
	
	
	for(ll i = 0; i < q; i++){
		cout << (f[i] ? "NO\n" : "YES\n");
	}
	
	return 0;
}
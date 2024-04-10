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

ll n, m, t, l, r, b[maxn];

bool vis[maxn];

pll a[maxn];

vector<ll> g[maxn], rg[maxn], vec;

void dfs1(ll v){
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		if(!vis[g[v][i]]) dfs1(g[v][i]);
	}
	vec.pb(v);
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	
	t = m + 1;
	
	while(n--){
		for(ll i = 0; i < m; i++){
			cin >> a[i].F;
			a[i].S = i + 1;
		}
		sort(a, a + m);
		r = t++;
		for(ll i = 0; i < m; i++){
			if(a[i].F == -1) continue;
			if(i == 0 || a[i].F != a[i - 1].F){
				l = r;
				r = t++;
			}
			g[l].pb(a[i].S);
			rg[a[i].S].pb(l);
			g[a[i].S].pb(r);
			rg[r].pb(a[i].S);
		}
	}
	
	for(ll i = 1; i < t; i++){
		if(!vis[i]) dfs1(i);
	}
	
	for(ll i = 0; i < vec.size(); i++){
		b[vec[i]] = i;
	}
	
	for(ll i = 0; i < vec.size(); i++){
		v = vec[i];
		for(ll j = 0; j < g[v].size(); j++){
			u = g[v][j];
			if(b[u] > b[v]){
				cout << "-1";
				return 0;
			}
		}
	}
	
	for(ll i = vec.size() - 1; i--;){
		if(vec[i] <= m) cout << vec[i] << " ";
	}
	
	return 0;
}
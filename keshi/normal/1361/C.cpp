//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 11e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, c[maxn];
pll a[maxn];
vector<pll> g[maxn];
vector<ll> vec;
bool vis[maxn], used[maxn];

void tur(ll v){
	ll u, x;
	while(c[v] < g[v].size()){
		u = g[v][c[v]].F;
		x = g[v][c[v]].S;
		if(!used[abs(x)]){
			used[abs(x)] = 1;
			tur(u);
			vec.pb(x);
		}
		c[v]++;
	}
	return;
}
void dfs(ll v){
	ll u;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i].F;
		if(!vis[u]) dfs(u);
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n;
	for(ll i = 0; i < n; i++){
		cin >> a[i].F >> a[i].S;
	}
	for(ll i = 20; i > -1; i--){
		for(ll j = 0; j < (1 << i); j++){
			g[j].clear();
			c[j] = 0;
			vis[j] = 0;
		}
		for(ll j = 0; j < n; j++){
			v = a[j].F - ((a[j].F >> i) << i);
			u = a[j].S - ((a[j].S >> i) << i);
			g[v].pb(Mp(u, -j - 1));
			g[u].pb(Mp(v, j + 1));
			used[j + 1] = 0;
		}
		bool f = 0;
		for(ll j = 0; j < (1 << i); j++){
			if(g[j].size() % 2) f = 1;
		}
		if(f) continue;
		v = 0;
		for(ll j = 0; j < (1 << i); j++){
			if(g[j].size() > 0 && !vis[j]) {
				if(v) f = 1;
				else dfs(j), v = 1;
			}
		}
		if(f) continue;
		vec.clear();
		for(ll j = 0; j < (1 << i); j++){
			if(g[j].size()) tur(j);
		}
		cout << i << '\n';
		for(ll j = 0; j < vec.size(); j++){
			v = vec[j];
			if(v > 0) cout << 2 * v - 1 << " " << 2 * v << " ";
			else cout << -2 * v << " " << -2 * v - 1 << " ";
		}
		return 0;
	}
	
	return 0;
}
//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, x, vis[maxn];

vector<ll> g[maxn], rg[maxn];

void dfs1(ll v){
	ll u;
	vis[v] = 1;
	x++;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(vis[u] < 1) dfs1(u);
	}
	return;
}

void dfs2(ll v){
	ll u;
	vis[v] = 2;
	x++;
	for(ll i = 0; i < rg[v].size(); i++){
		u = rg[v][i];
		if(vis[u] < 2) dfs2(u);
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j <= n; j++){
			cin >> x;
			if(x > 0){
				g[i].pb(j);
				rg[j].pb(i);
			}
		}
	}
	
	x = 0;
	
	dfs1(1);
	dfs2(1);
	
	cout << (x == 2 * n ? "YES" : "NO");
	
	return 0;
}
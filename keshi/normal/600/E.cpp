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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, c[maxn];
pll mx[maxn];
bool vis[maxn];
vector<ll> g[maxn];
unordered_map<ll, ll> s[maxn];

void dfs(ll v){
	ll u;
	vis[v] = 1;
	s[v][c[v]] = 1;
	mx[v] = Mp(1, c[v]);
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(vis[u]) continue;
		dfs(u);
		if(s[v].size() < s[u].size()) s[u].swap(s[v]), mx[v] = mx[u];
		for(unordered_map<ll, ll>::iterator it = s[u].begin(); it != s[u].end(); it++){
			s[v][it -> F] += it -> S;
			if(s[v][it -> F] > mx[v].F) mx[v] = Mp(s[v][it -> F], 0);
			if(s[v][it -> F] == mx[v].F) mx[v].S += it -> F;
		}
		s[u].clear();
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> c[i];
	}
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	dfs(1);
	
	for(ll i = 1; i <= n; i++){
		cout << mx[i].S << " ";
	}
	
	return 0;
}
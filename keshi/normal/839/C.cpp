#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 100;
const long long MOD = 1e8;
const long long INF = 1e18;

#define ll long long
#define ld long double
#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pii pair<int, int>
#define pll pair<ll, ll>
#define X first
#define Y second

ll n;
ld ans;
bool vis[MAXN];
vector<ll> g[MAXN];

void dfs(ll v, ld d, ld t){
	ll u, h = g[v].size();
	if(v != 1){
		h--;
	}
	bool f = 1;
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]){
			f = 0;
			dfs(u, d + 1, h * t);
		}
	}
	if(f){
		ans += d / t;
	}
	return;
}

int main(){
	fast_io;
	cout << setprecision(10);
	ll u, v;
	
	cin >> n;
	
	for(ll i = 1; i < n; i++){
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	dfs(1, 0, 1);
	
	cout << ans;
	
	return 0;
}
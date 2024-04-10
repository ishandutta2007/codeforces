//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, k, d, par[maxn], v, u;

bool vis[maxn];

vector<pll> g[maxn];

queue<ll> q;

vector<ll> ans;

int main(){
	fast_io;
	
	cin >> n >> k >> d;
	
	for(ll i = 0; i < k; i++){
		cin >> v;
		vis[v] = 1;
		q.push(v);
	}
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb({u, i});
		g[u].pb({v, i});
	}
	
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i].F;
			if(!vis[u]){
				par[u] = g[v][i].S;
				vis[u] = 1;
				q.push(u);
			}
		}
	}
	
	fill(vis, vis + n, 0);
	
	for(ll i = 1; i <= n; i++){
		vis[par[i]] = 1;
	}
	
	for(ll i = 1; i < n; i++){
		if(!vis[i]){
			ans.pb(i);
		}
	}
	
	cout << ans.size() << '\n';
	
	for(ll i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	
	return 0;
}
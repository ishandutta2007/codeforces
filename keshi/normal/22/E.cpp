//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
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

ll n, t, a[maxn], d[maxn], sink[maxn], vis[maxn];
vector<ll> g[maxn], vec[maxn], sinks;
vector<pll> ans;

void dfs(ll v){
	vis[v] = 1;
	for(ll u : g[v]){
		if(!vis[u]) dfs(u);
	}
	if(g[v].empty()) vec[t].pb(v);
}

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 1; i <= n; i++){
    	cin >> a[i];
    	g[a[i]].pb(i);
	}
	for(ll i = 1; i <= n; i++){
		if(vis[i]) continue;
		ll v = i;
		while(!vis[v]){
			vis[v] = i;
			v = a[v];
		}
		if(vis[v] == i) sinks.pb(v);
	}
	fill(vis, vis + n + 1, 0);
	for(ll i = 0; i < Sz(sinks); i++){
		ll v = sinks[i];
		t = i;
		dfs(v);
		while(Sz(vec[i]) > 1){
			ll u = vec[i].back();
			vec[i].pop_back();
			ans.pb(Mp(v, u));
		}
		if(vec[i].empty()){
			vec[i].pb(v);
		}
	}
	if(Sz(sinks) == 1){
		if(sinks[0] != vec[0][0]) ans.pb(Mp(sinks[0], vec[0][0]));
		cout << Sz(ans) << "\n";
		for(pll i : ans){
			cout << i.F << " " << i.S << "\n";
		}
		return 0;
	}
	for(ll i = 0; i + 1 < Sz(sinks); i++){
		ans.pb(Mp(sinks[i], vec[i + 1][0]));
	}
	ans.pb(Mp(sinks.back(), vec[0][0]));
	cout << Sz(ans) << "\n";
	for(pll i : ans){
		cout << i.F << " " << i.S << "\n";
	}
	
 
    return 0;
}
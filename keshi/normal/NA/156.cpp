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

ll n, m, d[maxn];

bool vis[maxn];

vector<ll> ans;

vector<pll> e;

set<pll> g[maxn];

void tur(ll v){
	ll u = 0;
	vis[v] = 1;
	set<pll>::iterator itr = g[v].lower_bound({u, 0});
	while(itr != g[v].end()){
		u = itr -> F;
		g[u].erase({v, -itr -> S});
		g[v].erase(itr);
		tur(u);
		itr = g[v].lower_bound({u, 0});
	}
	ans.pb(v);
}

int main(){
	ll v, u;
	//fast_io;
	
	cin >> n >> m;
	
	for(ll i = 1; i <= m; i++){
		cin >> v >> u;
		g[v].insert({u, i});
		g[u].insert({v, -i});
	}
	
	for(ll i = 1; i <= n; i++){
		if(g[i].size() % 2){
			ans.pb(i);
		}
	}
	
	for(ll i = 0; i + 1 < ans.size(); i += 2){
		v = ans[i];
		u = ans[i + 1];
		g[v].insert({u, m + i + 1});
		g[u].insert({v, -m - i - 1});
	}
	
	for(ll i = 1; i <= n; i++){
		if(vis[i]) continue;
		ans.clear();
		tur(i);
		for(ll j = 0; j + 1 < ans.size(); j += 2){
			e.pb({ans[j], ans[j + 1]});
			d[ans[j]]++;
		}
		for(ll j = 1; j + 1 < ans.size(); j += 2){
			e.pb({ans[j + 1], ans[j]});
			d[ans[j + 1]]++;
		}
	}
	
	for(ll i = 1; i <= n; i++){
		if(d[i] % 2){
			e.pb({i, i});
		}
	}
	
	cout << e.size() << endl;
	
	for(ll i = 0; i < e.size(); i++){
		cout << e[i].F << " " << e[i].S << '\n';
	}
	
	return 0;
}
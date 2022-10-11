//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n;

vector<ll> ans, h[10][10];

set<pll> g[10];

void tur(ll v){
	ll u = -1;
	set<pll>::iterator itr = g[v].lower_bound({u, -1000});
	while(itr != g[v].end()){
		u = itr -> F;
		g[u].erase({v, -itr -> S});
		g[v].erase(itr);
		tur(u);
		itr = g[v].lower_bound({u, -1000});
	}
	ans.pb(v);
}

int main(){
	ll v, u, c = 0;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> v >> u;
		g[v].insert({u, i});
		g[u].insert({v, -i});
		h[v][u].pb(i);
	}
	
	for(ll i = 0; i <= 6; i++){
		if(g[i].size() % 2){
			c++;
			v = i;
		}
	}
	
	tur(v);
	
	if(c > 2 || ans.size() != n + 1){
		cout << "No solution";
		return 0;
	}
	
	for(ll i = 0; i + 1 < ans.size(); i++){
		v = ans[i];
		u = ans[i + 1];
		if(!h[v][u].empty()){
			cout << h[v][u].back() << " +\n";
			h[v][u].pop_back();
		}
		else{
			cout << h[u][v].back() << " -\n";
			h[u][v].pop_back();
		}
	}
	
	return 0;
}
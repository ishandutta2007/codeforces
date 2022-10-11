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
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, c[maxn], a[maxn];
bool val[maxn], vis[maxn];
vector<pll> g[maxn];
set<pll> s;

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> c[i];
		c[i] *= -1;
	}
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(Mp(u, i + 1));
		g[u].pb(Mp(v, i + 1));
		c[v]++;
		c[u]++;
	}
	for(ll i = 1; i <= n; i++){
		s.insert(Mp(c[i], i));
	}
	for(ll i = 1; i <= n; i++){
		v = s.begin() -> S;
		s.erase(s.begin());
		val[v] = 1;
		a[n - i] = v;
		if(c[v] > 0){
			cout << "DEAD";
			return 0;
		}
		for(ll j = 0; j < g[v].size(); j++){
			u = g[v][j].F;
			if(val[u]) continue;
			s.erase(Mp(c[u]--, u));
			s.insert(Mp(c[u], u));
		}
	}
	cout << "ALIVE\n";
	for(ll i = 0; i < n; i++){
		v = a[i];
		for(ll j = 0; j < g[v].size(); j++){
			u = g[v][j].S;
			if(!vis[u]) cout << u << " ", vis[u] = 1;
		}
	}
	
	
	return 0;
}
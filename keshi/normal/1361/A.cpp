//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn];
bool vis[maxn];
pll b[maxn];
vector<ll> g[maxn];

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(ll i = 1; i <= n; i++){
		if(g[i].size() < a[i] - 1){
			cout << -1;
			return 0;
		}
		for(ll j = 0; j < g[i].size(); j++){
			vis[a[g[i][j]]] = 1;
		}
		for(ll j = 1; j < a[i]; j++){
			if(!vis[j]){
				cout << -1;
				return 0;
			}
		}
		if(vis[a[i]]){
			cout << -1;
			return 0;
		}
		for(ll j = 0; j < g[i].size(); j++){
			vis[a[g[i][j]]] = 0;
		}
	}
	for(ll i = 1; i <= n; i++){
		b[i] = Mp(a[i], i);
	}
	sort(b + 1, b + n + 1);
	for(ll i = 1; i <= n; i++){
		cout << b[i].S << " ";
	}
	
	return 0;
}
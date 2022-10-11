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

ll t, n, m;
bool vis[maxn];
vector<ll> g[maxn], vec, gr[maxn];

int main(){
	ll v, u;
	fast_io;
	
	cin >> t;
	while(t--){
		cin >> n >> m;
		fill(vis, vis + n + 1, 0);
		vec.clear();
		for(ll i = 1; i <= n; i++){
			g[i].clear();
			gr[i].clear();
		}
		for(ll i = 0; i < m; i++){
			cin >> v >> u; 
			g[v].pb(u);
			gr[u].pb(v);
		}
		for(ll i = 1; i <= n; i++){
			if(vis[i]){
				vec.pb(i);
				continue;
			}
			bool f = 0;
			for(ll j = 0; j < gr[i].size(); j++){
				if(!vis[gr[i][j]]) f = 1;
			}
			if(f){
				for(ll j = 0; j < g[i].size(); j++){
					vis[g[i][j]] = 1;
				}
			}
		}
		cout << vec.size() << '\n';
		for(ll i = 0; i < vec.size(); i++){
			cout << vec[i] << " ";
		}
		cout << '\n';
	}
	
	return 0;
}
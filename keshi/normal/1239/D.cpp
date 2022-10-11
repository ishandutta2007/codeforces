//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 1e6 + 100;
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

ll t, n, m, vis[maxn];
vector<ll> g[maxn], gp[maxn], vec, v2;

void dfs(ll v){
	vis[v] = 1;
	for(ll u : g[v]){
		if(!vis[u]) dfs(u);
	}
	vec.pb(v);
}
void sfd(ll v){
	vis[v] = 0;
	for(ll u : gp[v]){
		if(vis[u]) sfd(u);
	}
	v2.pb(v);
}

int main(){
    fast_io;
    
    cin >> t;
    while(t--){
    	cin >> n >> m;
    	for(ll i = 1; i <= n; i++){
    		g[i].clear();
    		gp[i].clear();
    		vis[i] = 0;
		}
    	for(ll i = 0; i < m; i++){
    		ll v, u;
    		cin >> v >> u;
    		if(v != u){
    			g[v].pb(u);
    			gp[u].pb(v);
			}
		}
		vec.clear();
		for(ll i = 1; i <= n; i++){
			if(!vis[i]) dfs(i);
		}
		for(ll i = Sz(vec); i--;){
			if(vis[vec[i]]){
				v2.clear();
				sfd(vec[i]);
			}
		}
		ll cnt = Sz(v2);
		if(cnt == n){
			cout << "No\n";
			continue;
		}
		cout << "Yes\n" << cnt << " " << n - cnt << "\n";
		for(ll i : v2){
			cout << i << " ";
			vis[i] = 1;
		}
		cout << "\n";
		for(ll i = 1; i <= n; i++){
			if(!vis[i]) cout << i << " ";
		}
		cout << "\n";
	}
 
    return 0;
}
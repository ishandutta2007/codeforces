//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e6 + 100;
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

ll n, m, p[maxn], a[maxn];
vector<ll> g[maxn];
vector<ll> vec, v2;
bool vis[maxn];

void dfs(ll v){
	vis[v] = 1;
	vec.pb(v);
	for(ll u : g[v]){
		if(!vis[u]) dfs(u);
	}
	return;
}

int main(){
    fast_io;
    
    cin >> n >> m;
    for(ll i = 1; i <= n; i++){
    	cin >> p[i];
	}
	for(ll i = 0; i < m; i++){
		ll v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	for(ll i = 1; i <= n; i++){
		if(vis[i]) continue;
		vec.clear();
		v2.clear();
		dfs(i);
		sort(all(vec));
		for(ll j : vec){
			v2.pb(-p[j]);
		}
		sort(all(v2));
		for(ll j = 0; j < Sz(vec); j++){
			a[vec[j]] = -v2[j];
		}
	}
	for(ll i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
 
    return 0;
}
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

ll n, m, k, vis[maxn], t, c, s;
vector<ll> g[maxn];

void dfs(ll v){
	vis[v] = 1;
	c++;
	for(ll u : g[v]){
		if(!vis[u]) dfs(u);
	}
	return;
}

int main(){
    fast_io;
    
    cin >> n >> m >> k;
    for(ll i = 0; i < m; i++){
    	ll v, u;
    	cin >> v >> u;
    	g[v].pb(u);
    	g[u].pb(v);
	}
	s = 1;
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			c = 0;
			dfs(i);
			s = (s * c) % k;
			t++;
		}
	}
	if(t == 1){
		cout << 1 % k;
		return 0;
	}
	for(ll i = 0; i < t - 2; i++){
		s = (s * n) % k;
	}
	cout << s;
	
 
    return 0;
}
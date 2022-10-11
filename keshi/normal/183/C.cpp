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

ll n, m, ans;

vector<ll> gin[maxn], gout[maxn], vec[maxn];

bool vis[maxn];

void dfs(ll v, ll x){
	ll u;
	vec[v].pb(x);
	if(vis[v]) return;
	vis[v] = 1;
	for(ll i = 0; i < gout[v].size(); i++){
		dfs(gout[v][i], x + 1);
	}
	for(ll i = 0; i < gin[v].size(); i++){
		dfs(gin[v][i], x - 1);
	}
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		gout[v].pb(u);
		gin[u].pb(v);
	}
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]) dfs(i, 0);
	}
	
	for(ll i = 1; i <= n; i++){
		for(ll j = 1; j < vec[i].size(); j++){
			ans = __gcd(ans, vec[i][j] - vec[i][j - 1]);
		}
	}
	
	if(ans == 0) ans = n;
	
	cout << abs(ans);
	
	return 0;
}
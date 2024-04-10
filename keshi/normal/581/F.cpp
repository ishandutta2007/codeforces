//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 5100;
const ll mod = 1e9 + 7;
const ll inf = 1e8;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, dp[maxn][maxn << 1][2], vis[maxn], sz[maxn], pd[maxn << 1][2];
vector<ll> g[maxn];

void dfs(ll v){
	vis[v] = 1;
	if(Sz(g[v]) == 1){
		sz[v] = 1;
		dp[v][maxn][0] = dp[v][maxn][1] = inf;
		dp[v][maxn + 1][1] = inf;
		dp[v][maxn - 1][0] = inf;
	}
	for(ll u : g[v]){
		if(vis[u]) continue;
		dfs(u);
		for(ll i = -sz[v] - sz[u]; i <= sz[v] + sz[u]; i++){
			pd[i + maxn][0] = pd[i + maxn][1] = inf;
		}	
		for(ll i = -sz[v]; i <= sz[v]; i++){
			for(ll j = -sz[u]; j <= sz[u]; j++){
				for(ll c1 = 0; c1 < 2; c1++){
					for(ll c2 = 0; c2 < 2; c2++){
						pd[i + j + maxn][c1] = min(pd[i + j + maxn][c1], dp[v][i + maxn][c1] + dp[u][j + maxn][c2] + (c1 ^ c2));
					}
				}
			}
		}
		sz[v] += sz[u];
		for(ll i = -sz[v]; i <= sz[v]; i++){
			dp[v][i + maxn][0] = pd[i + maxn][0];
			dp[v][i + maxn][1] = pd[i + maxn][1];
		}
	}
}

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 1; i < n; i++){
    	ll v, u;
    	cin >> v >> u;
    	g[v].pb(u);
    	g[u].pb(v);
	}
	ll v = 0;
	for(ll i = 1; i <= n; i++){
		if(Sz(g[i]) != 1) v = i;
	}
	dfs(v);
	cout << min(dp[v][maxn][0], dp[v][maxn][1]);
 
    return 0;
}
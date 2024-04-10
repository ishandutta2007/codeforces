//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 3e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, nxt[maxn][26], vis[maxn], c[maxn], sz[maxn], dp[maxn], mx, cnt, a[maxn];
vector<ll> g[maxn];
string s;

void mrg(ll v, ll u){
	for(ll i = 0; i < 26; i++){
		if(!nxt[v][i]){
			nxt[v][i] = nxt[u][i];
			sz[v] += sz[nxt[v][i]];
		}
		else if(nxt[u][i]){
			ll x = nxt[v][i];
			ll y = nxt[u][i];
			sz[v] -= sz[x];
			if(sz[x] > sz[y]) swap(x, y);
			mrg(x, y);
			sz[v] += sz[x];
			nxt[v][i] = x;
		}
	}
}

void dfs(ll v){
	vis[v] = 1;
	sz[v] = 1;
	for(ll u : g[v]){
		if(vis[u]) continue;
		dfs(u);
		if(!nxt[v][a[u]]){
			nxt[v][a[u]] = u;
			sz[v] += sz[u];
		}
		else{
			ll x = nxt[v][a[u]];
			sz[v] -= sz[x];
			if(sz[u] > sz[x]){
				mrg(u, x);
				sz[v] += sz[u];
				nxt[v][a[u]] = u;
			}
			else{
				mrg(x, u);
				sz[v] += sz[x];
			}
		}
	}
	dp[v] = c[v] + sz[v];
	if(dp[v] > mx){
		mx = dp[v];
		cnt = 0;
	}
	if(dp[v] == mx) cnt++;
	return;
}

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 1; i <= n; i++){
    	cin >> c[i];
	}
	cin >> s;
	for(ll i = 0; i < n; i++){
		a[i + 1] = (s[i] - 'a');
	}
	for(ll i = 1; i < n; i++){
		ll v, u;
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	dfs(1);
	cout << mx << "\n" << cnt;
 
    return 0;
}
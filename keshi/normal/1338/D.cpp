//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll maxm = 30;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, dp[2][maxn], pd[2][maxn], ans, p[maxn];

bool vis[maxn];

vector<ll> g[maxn];

void sfd(ll v){
    ll u;
    vector<pll> vec, cev;
    cev.pb({1, v});
    for(ll i = 0; i < g[v].size(); i++){
        u = g[v][i];
        if(u == p[v]){
            vec.pb({max(pd[0][v], pd[1][v]), u});
            cev.pb({pd[0][v] + 1, u});
        }
        else{
            vec.pb({max(dp[0][u], dp[1][u]), u});
            cev.pb({dp[0][u] + 1, u});
        }
    }
    sort(vec.begin(), vec.end(), greater<pll>());
    sort(cev.begin(), cev.end(), greater<pll>());
    for(ll i = 0; i < g[v].size(); i++){
        u = g[v][i];
        if(u == p[v]) continue;
        if(vec[0].S != u) pd[0][u] = max(0ll, ll(vec.size()) - 2) + vec[0].F;
        else if(vec.size() > 1) pd[0][u] = vec.size() - 2 + vec[1].F;
        if(cev[0].S != u) pd[1][u] = cev[0].F;
        else pd[1][u] = cev[1].F;
        pd[0][u] = max(pd[0][u], pd[1][u] - 1);
        sfd(u);
    }
    return;
}

void dfs(ll v){
	ll u;
	vis[v] = 1;
	dp[1][v] = 1;
	ll s = 0, c = 0;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(vis[u]) continue;
		p[u] = v;
		dfs(u);
		c++;
		s = max(s, max(dp[0][u], dp[1][u]));
		dp[1][v] = max(dp[1][v], dp[0][u] + 1);
	}
	dp[0][v] = max(s + c - 1, dp[1][v] - 1);
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i < n; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
	}
	
	dfs(1);
	sfd(1);
	
	for(ll i = 1; i <= n; i++){
	    ll s = 0;
	    for(ll j = 0; j < g[i].size(); j++){
	        u = g[i][j];
	        if(u == p[i]){
	            s = max(s, max(pd[0][i], pd[1][i]));
	            ans = max(ans, pd[0][i] + 1);
	        }
	        else{
	            s = max(s, max(dp[0][u], dp[1][u]));
	            ans = max(ans, dp[0][u] + 1);
	        }
	    }
	    ans = max(ans, g[i].size() - 1 + s);
	}
	
	cout << ans;
	
	return 0;
}
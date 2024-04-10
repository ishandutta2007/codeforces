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

ll n, q, x, d[maxn][2], dis[maxn], sz, a[maxn], ans, ps[maxn];
vector<pll> g[maxn];
bool vis[maxn];

void dfs1(ll v, ll t){
	vis[v] = 1;
	for(pll u : g[v]){
		if(!vis[u.F]){
			d[u.F][t] = d[v][t] + u.S;
			dfs1(u.F, t);
		}
	}
}

void dfs(ll v){
	vis[v] = 1;
	a[sz++] = v;
	ll l = 0, r = sz - 1, mid;
	while(r - l > 1){
		mid = (l + r) >> 1;
		if(dis[v] - dis[a[mid]] > x) l = mid;
		else r = mid;
	}
	ps[v] = 1;
	ps[a[l]]--;
	for(pll u : g[v]){
		if(!vis[u.F]){
			dfs(u.F);
			ps[v] += ps[u.F];
		}
	}
	a[sz--] = v;
	ans = max(ans, ps[v]);
}

int main(){
    fast_io;
    
    cin >> n;
    for(ll i = 1; i < n; i++){
    	ll v, u, c;
    	cin >> v >> u >> c;
    	g[v].pb(Mp(u, c));
    	g[u].pb(Mp(v, c));
	}
	fill(vis, vis + n + 1, 0);
	d[1][0] = 0;
	dfs1(1, 0);
	ll v = 1;
	for(ll i = 2; i <= n; i++){
		if(d[i][0] > d[v][0]) v = i;
	}
	fill(vis, vis + n + 1, 0);
	d[v][0] = 0;
	dfs1(v, 0);
	ll u = 1;
	for(ll i = 2; i <= n; i++){
		if(d[i][0] > d[u][0]) u = i;
	}
	fill(vis, vis + n + 1, 0);
	d[u][1] = 0;
	dfs1(u, 1);
	ll r = 1;
	for(ll i = 1; i <= n; i++){
		dis[i] = max(d[i][0], d[i][1]);
		if(dis[i] < dis[r]) r = i;
	}
	dis[0] = -inf;
	cin >> q;
	while(q--){
		cin >> x;
		fill(vis, vis + n + 1, 0);
		sz = 1;
		ans = 0;
		dfs(r);
		cout << ans << "\n";
	}
 
    return 0;
}
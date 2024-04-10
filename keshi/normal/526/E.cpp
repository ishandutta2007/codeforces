//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef int ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e9;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, q, a[maxn], h[maxn], d[maxn], ans;
long long ps[maxn];
vector<ll> vec, g[maxn];
bool vis[maxn], val[maxn];

long long getsum(ll l, ll r){
	if(r >= l) return ps[r] - ps[l - 1];
	return ps[n] - ps[l - 1] + ps[r];
}
ll getdis(ll l, ll r){
	return (r - l >= 0 ? r - l : n + r - l);
}
ll bain(ll l, ll x, ll r){
	return (getdis(l, x) + getdis(x, r) == getdis(l, r));
}
void dfs(ll v){
	ll u;
	vec.pb(v);
	val[v] = 1;
	ans = min(ans, (ll)vec.size() - d[v]);
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(val[u]) continue;
		d[u] = d[v];
		if(bain(v, vec[d[u]], u)) d[u]++;
		dfs(u);
	}
	vec.pop_back();
	return;
}
void solve(long long x){
	ans = inf;
	for(ll i = 1; i <= n; i++){
		g[i].clear();
	}
	h[0] = 1;
	for(ll i = 1; i <= n; i++){
		h[i] = h[i - 1];
		vis[i] = 0;
		val[i] = 0;
		while(getsum(i, h[i]) <= x) h[i] = (h[i] == n ? 1 : h[i] + 1);
		g[h[i]].pb(i);
	}
	for(ll i = 1; i <= n; i++){
		if(vis[i] || val[i]) continue;
		ll j = i;
		while(!vis[j]){
			vis[j] = 1;
			j = h[j];
		}
		ll k = j;
		vec.clear();
		k = h[j];
		vec.pb(h[j]);
		while(bain(k, h[k], j) && h[k] != j) k = h[k], vec.pb(h[k]);
		reverse(vec.begin(), vec.end());
		d[j] = 0;
		dfs(j);
	}
	cout << ans << '\n';
	return;
}

int main(){
	fast_io;
	
	cin >> n >> q;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		ps[i] = ps[i - 1] + a[i];
	}
	long long x;
	while(q--){
		cin >> x;
		if(getsum(1, n) > x) solve(x);
		else cout << "1\n";
	}
	
	return 0;
}
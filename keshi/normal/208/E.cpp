//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll level = 18;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, q, p, t, sp[maxn][level], s[maxn], f[maxn], h[maxn];

vector<ll> g[maxn], vec[maxn];

ll cal(ll v, ll x){
	for(ll i = 0; i < level; i++){
		if((x >> i) & 1){
			v = sp[v][i];
		}
	}
	return v;
}

void dfs(ll v){
	s[v] = t++;
	vec[h[v]].pb(s[v]);
	for(ll i = 0; i < g[v].size(); i++){
		ll u = g[v][i];
		h[u] = h[v] + 1;
		dfs(u);
	}
	f[v] = t - 1;
	return;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> sp[i][0];
		g[sp[i][0]].pb(i);
	}
	
	dfs(0);
	
	for(ll i = 1; i < level; i++){
		for(ll j = 1; j <= n; j++){
			sp[j][i] = sp[sp[j][i - 1]][i - 1];
		}
	}
	
	cin >> q;
	
	while(q--){
		cin >> v >> p;
		u = cal(v, p);
		if(u == 0){
			cout << 0 << " ";
		}
		else{
			cout << (upper_bound(vec[h[v]].begin(), vec[h[v]].end(), f[u]) - upper_bound(vec[h[v]].begin(), vec[h[v]].end(), s[u])) - 1 << " ";
		}
	}
	
	
	return 0;
}
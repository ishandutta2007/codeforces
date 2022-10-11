//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll lg = 60;
const ll mod = 1e9 + 7;
const ll inf = 1e12;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) ll((x).size())
#define all(x) (x).begin(), (x).end()

ll n, m, d[maxn], cnt[lg], basis[lg], c1, c2, ans;
bool vis[maxn], v2[lg];
vector<pll> g[maxn];

void add(ll x){
	for(ll i = 0; i < lg; i++){
		if((x >> i) & 1) v2[i] = 1;
	}
	for(ll i = lg; i--;){
		if((x >> i) & 1){
			if(basis[i] == 0){
				basis[i] = x;
				c2++;
				break;
			}
			x ^= basis[i];
		}
	}
	return;
}

void dfs(ll v){
	vis[v] = 1;
	for(ll j = 0; j < lg; j++){
		if((d[v] >> j) & 1) cnt[j]++;
	}
	c1++;
	for(ll i = 0; i < Sz(g[v]); i++){
		ll u = g[v][i].F, c = g[v][i].S;
		if(vis[u]) add(c ^ d[u] ^ d[v]);
		else{
			d[u] = d[v] ^ c;
			dfs(u);
		}
	}
	return;
}

int main(){
    fast_io;
    
    cin >> n >> m;
    for(ll i = 0; i < m; i++){
    	ll v, u, c;
    	cin >> v >> u >> c;
    	g[v].pb(Mp(u, c));
    	g[u].pb(Mp(v, c));
	}
	for(ll i = 1; i <= n; i++){
		if(vis[i]) continue;
		fill(cnt, cnt + lg, 0);
		fill(v2, v2 + lg, 0);
		fill(basis, basis + lg, 0);
		c1 = c2 = 0;
		dfs(i);
		ll y = (1ll << c2);
		for(ll j = 0; j < lg; j++){
			ll x;
			if(v2[j]) x = y / 2;
			else x = 0;
			ans = (ans + (cnt[j] * (c1 - cnt[j]) % mod * ((y - x) % mod) + (cnt[j] * (cnt[j] - 1) / 2 + (c1 - cnt[j]) * (c1 - cnt[j] - 1) / 2) % mod * (x % mod)) % mod * ((1ll << j) % mod)) % mod;
		}
	}
	cout << (ans + mod) % mod;
 
    return 0;
}
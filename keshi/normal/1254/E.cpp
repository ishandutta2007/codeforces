//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef int ll;
typedef pair<ll, ll> pll;

const ll maxn = 5e5 + 100;
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

ll n, t, a[maxn], st[maxn], ft[maxn], cnt, nxt[maxn << 2], prv[maxn << 2], vis[maxn << 2];
long long f[maxn];
pll par[maxn];
vector<pll> g[maxn];
vector<ll> e1, e2;

void dfs(ll v){
	st[v] = t++;
	for(pll u : g[v]){
		if(u.F == par[v].F) continue;
		par[u.F] = Mp(v, u.S);
		dfs(u.F);
	}
	ft[v] = t;
}

int main(){
    fast_io;
    e1.reserve(maxn);
    e2.reserve(maxn);
    
    f[0] = 1;
    for(ll i = 1; i < maxn; i++){
    	f[i] = f[i - 1] * i % mod;
	}
    
    cin >> n;
    for(ll i = 1; i < n; i++){
    	ll v, u;
    	cin >> v >> u;
    	g[v].pb(Mp(u, n + n + i * 2));
    	g[u].pb(Mp(v, n + n + i * 2 + 1));
	}
	dfs(1);
	for(ll i = 1; i <= n; i++){
		ll u;
		cin >> u;
		if(u == 0) continue;
		ll v = i;
		e1.clear();
		e2.clear();
		e1.pb(v * 2 + 1);
		e2.pb(u * 2 + 1);
		while(v != u){
			cnt++;
			if(cnt > n + n){
				cout << 0;
				return 0;
			}
			if(st[v] <= st[u] && st[u] < ft[v]){
				e2.pb(par[u].S);
				u = par[u].F;
			}
			else{
				e1.pb(par[v].S ^ 1);
				v = par[v].F;
			}
		}
		for(ll j = Sz(e2); j--;){
			e1.pb(e2[j]);
		}
		for(ll j = 0; j + 1 < Sz(e1); j++){
			if(nxt[e1[j] ^ 1] || prv[e1[j + 1]]){
				cout << 0;
				return 0;
			}
			nxt[e1[j] ^ 1] = e1[j + 1];
			prv[e1[j + 1]] = e1[j] ^ 1;
		}
	}
	long long ans = 1;
	for(ll i = 1; i <= n; i++){
		g[i].pb(Mp(0, i * 2));
		g[i].pb(Mp(0, i * 2 + 1));
		if(prv[i * 2] || nxt[i * 2 + 1]){
			cout << 0;
			return 0;
		}
		ll x = 0;
		for(pll j : g[i]){
			if(nxt[j.S]){
				if(vis[j.S]) continue;
				ll v = j.S;
				while(nxt[v]){
					vis[v] = 1;
					v = nxt[v];
					if(v == j.S){
						cout << 0;
						return 0;
					}
				}
			}
			else x++;
		}
		ll v = i * 2;
		while(nxt[v]) v = nxt[v];
		if(v == i * 2 + 1){
			if(x != 1){
				cout << 0;
				return 0;
			}
			continue;
		}
		ans = (ans * f[x - 2]) % mod;
	}
	cout << ans;
 
    return 0;
}
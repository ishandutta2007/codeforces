//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

const ll maxn = 4e5 + 100;
const ll lg = 30;
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

ll n, m, w[maxn], d[maxn], basis[lg];
bool vis[maxn], mark[maxn];
vector<pll> g[maxn];
vector<ll> vec;

void dfs(ll v){
	vis[v] = 1;
	for(pll u : g[v]){
		if(vis[u.F]){
			vec.pb(d[v] ^ d[u.F] ^ w[u.S]);
		}
		else{
			d[u.F] = d[v] ^ w[u.S];
			dfs(u.F);
		}
	}
	return;
}

int main(){
    fast_io;

	cin >> n >> m;
	for(ll i = 0; i < m; i++){
		ll v, u;
		cin >> v >> u >> w[i];
		g[v].pb(Mp(u, i));
		g[u].pb(Mp(v, i));
	}
	dfs(1);
	for(ll j = lg; j--;){
		basis[j] = -1;
		for(ll i = 0; i < Sz(vec); i++){
			if(!mark[i] && ((vec[i] >> j) & 1)){
				basis[j] = i;
			}
		}
		if(basis[j] != -1){
			mark[basis[j]] = 1;
			for(ll i = 0; i < Sz(vec); i++){
				if(i != basis[j] && ((vec[i] >> j) & 1)){
					vec[i] ^= vec[basis[j]];
				}
			}
		}
	}
	for(ll j = lg; j--;){
		if(basis[j] == -1) continue;
		if((d[n] >> j) & 1) d[n] ^= vec[basis[j]];
	}
	cout << d[n];

    return 0;
}
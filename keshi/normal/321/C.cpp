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

ll n, sz[maxn], ans[maxn], hide[maxn];
vector<ll> g[maxn];

void plant(ll v, ll par = -1){
	sz[v] = 1;
	for(ll u : g[v]){
		if(hide[u] || u == par) continue;
		plant(u, v);
		sz[v] += sz[u];
	}
}

ll centroid(ll v, ll s, ll par = -1){
	for(ll u : g[v]){
		if(!hide[u] && u != par && sz[u] * 2 > s){
			return centroid(u, s, v);
		}
	}
	return v;
}

void solve(ll v, ll h = 0){
	plant(v);
	v = centroid(v, sz[v]);
	ans[v] = h;
	hide[v] = 1;
	for(ll u : g[v]){
		if(!hide[u]){
			solve(u, h + 1);
		}
	}
	return;
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
	solve(1);
	for(ll i = 1; i <= n; i++){
		cout << char('A' + ans[i]) << " ";
	}
 
    return 0;
}
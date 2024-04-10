//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll level = 20;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, d[maxn], par[maxn][level];

ll lca(ll v, ll u){
	if(d[v] < d[u]) swap(v, u);
	ll h = d[v] - d[u], z = 0;
	for(ll i = 0; i < level; i++){
		if((h >> i) & 1){
			v = par[v][i];
			z += (1 << i);
		}
	}
	for(ll i = level - 1; i > -1; i--){
		if(d[v] >= (1 << i) && par[v][i] != par[u][i]){
			v = par[v][i];
			u = par[u][i];
			z += 2 * (1 << i);
		}
	}
	if(v != u) z += 2;
	return z;
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n;
	
	v = u = 1;
	
	for(ll i = 2; i <= n; i++){
		cin >> par[i][0];
		d[i] = d[par[i][0]] + 1;
		for(ll j = 1; j < level; j++){
			if(d[i] >= (1 << j)) par[i][j] = par[par[i][j - 1]][j - 1];
		}
		if(lca(v, u) < max(lca(v, i), lca(u, i))){
			if(lca(v, i) > lca(u, i)) u = i;
			else v = i;
		}
		cout << lca(v, u) << ' ';
	}
	
	return 0;
}
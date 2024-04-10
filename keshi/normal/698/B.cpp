//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, a[maxn], m, r[maxn], t, root;

bool vis[maxn];

vector<ll> g[maxn];

void dfs(ll v, ll p){
	vis[v] = 1;
	for(ll i = 0; i < g[v].size(); i++){
		ll u = g[v][i];
		if(!vis[u]){
			dfs(u, v);
		}
		else if(u != p){
			r[t] = v;
			if(a[v] == v){
				root = v;
			}
		}
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
		g[i].pb(a[i]);
		g[a[i]].pb(i);
	}
	
	for(ll i = 1; i <= n; i++){
		if(!vis[i]){
			t++;
			dfs(i, 0);
		}
	}
	
	if(root == 0){
		root = r[1];
	}
	
	for(ll i = 1; i <= t; i++){
		if(a[r[i]] != root){
			a[r[i]] = root;
			m++;
		}
	}
	
	cout << m << endl;
	
	for(ll i = 1; i <= n; i++){
		cout << a[i] << " ";
	}
	
	return 0;
}
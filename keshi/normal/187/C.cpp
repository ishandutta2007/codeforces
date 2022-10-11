//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, k, s, t, dis[maxn], dsu[maxn], sz[maxn];

vector<ll> g[maxn], vec;

void init(){
    for(ll i = 1; i <= n; i++){
    	dsu[i] = i;
    	sz[i] = 1;
    	dis[i] = inf;
	}
}

ll root(ll i){
	if (dsu[i] == i) return dsu[i];
	dsu[i] = root(dsu[i]);
	return dsu[i];
}

void Union(ll i, ll j){
    ll v = root(i), u = root(j);
    if(v == u) return;
    if(sz[v] > sz[u]) swap(v, u);
	dsu[v] = dsu[u];
	sz[u] += sz[v];
	return;
}

bool isval(ll x){
	ll v, u;
	init();
	queue<ll> q;
	for(ll i = 0; i < vec.size(); i++){
		if(dis[vec[i]]) q.push(vec[i]);
		dis[vec[i]] = 0;
	}
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i];
			if(dis[v] + 1 <= x && dis[u] > dis[v] + 1){
				dis[u] = dis[v] + 1;
				Union(v, u);
				q.push(u);
			}
			else if(dis[u] + dis[v] + 1 <= x){
				Union(v, u);
			}
		}
	}
	return (root(s) == root(t));
}

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m >> k;
	
	init();
	
	for(ll i = 0; i < k; i++){
		cin >> v;
		vec.pb(v);
	}
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v].pb(u);
		g[u].pb(v);
		Union(v, u);
	}
	
	cin >> s >> t;
	vec.pb(t);
	
	if(root(s) != root(t)){
		cout << -1;
		return 0;
	}
	
	ll l = 0, r = m, mid;
	
	while(r - l > 1){
		mid = (l + r) / 2;
		if(isval(mid)) r = mid;
		else l = mid;
	}
	
	cout << r;
	
	return 0;
}
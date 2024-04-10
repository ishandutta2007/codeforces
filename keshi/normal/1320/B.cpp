//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, k, dis[maxn], a[maxn], mn, mx;

vector<ll> g[maxn], gp[maxn];

queue<ll> q;

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> u >> v;
		g[v].pb(u);
		gp[u].pb(v);
	}
	
	cin >> k;
	
	for(ll i = 0; i < k; i++){
		cin >> a[i];
	}
	
	fill(dis, dis + maxn, inf);
	
	q.push(a[k - 1]);
	dis[a[k - 1]] = 0;
	
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i];
			if(dis[u] > dis[v] + 1){
				dis[u] = dis[v] + 1;
				q.push(u);
			}
		}
	}
	
	for(ll i = 0; i < k - 1; i++){
		if(dis[a[i + 1]] + 1 != dis[a[i]]) mn++;
		for(ll j = 0; j < gp[a[i]].size(); j++){
			u = gp[a[i]][j];
			if(dis[u] + 1 == dis[a[i]] && u != a[i + 1]){
				mx++;
				break;
			}
		}
	}
	
	cout << mn << " " << mx;
	
	return 0;
}
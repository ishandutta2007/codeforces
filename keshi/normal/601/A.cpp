//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 500;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, dis[maxn], v, u;

bool g[maxn][maxn];

queue<ll> q;

int main(){
	fast_io;
	
	cin >> n >> m;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		g[v][u] = 1;
		g[u][v] = 1;
	}
	
	fill(dis, dis + maxn, inf);
	
	q.push(1);
	dis[1] = 0;
	
	while(!q.empty()){
		v = q.front();
		q.pop();
		for(ll i = 1; i <= n; i++){
			if(g[v][i] != g[1][n] && dis[i] > dis[v] + 1){
				q.push(i);
				dis[i] = dis[v] + 1;
			}
		}
	}
	
	if(dis[n] == inf){
		dis[n] = -1;
	}
	
	cout << dis[n];
	
	return 0;
}
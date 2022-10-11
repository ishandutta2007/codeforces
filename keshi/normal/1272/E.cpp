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

ll n, a[maxn], dis[maxn], v, u;

vector<ll> g[maxn];

queue<ll> q;

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(ll i = 0; i < n; i++){
		dis[i] = inf;
		if(i + a[i] < n){
			if(a[i + a[i]] % 2 != a[i] % 2){
				dis[i] = 1;
			}
			else{
				g[i + a[i]].pb(i);
			}
		}
		if(i - a[i] >= 0){
			if(a[i - a[i]] % 2 != a[i] % 2){
				dis[i] = 1;
			}
			else{
				g[i - a[i]].pb(i);
			}
		}
	}
	
	for(ll i = 0; i < n; i++){
		if(dis[i] == 1) q.push(i);
	}
	
	while(!q.empty()){
		ll v = q.front();
		q.pop();
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i];
			if(dis[u] > dis[v] + 1){
				dis[u] = dis[v] + 1;
				q.push(u);
			}
		}
	}
	
	for(ll i = 0; i < n; i++){
		if(dis[i] == inf){
			dis[i] = -1;
		}
		cout << dis[i] << " ";
	}
	
	return 0;
}
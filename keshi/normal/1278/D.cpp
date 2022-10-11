//In the name of GOD
//Hello Yellow
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1e6 + 100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, o[maxn], c[maxn];

bool vis[maxn];

pll a[maxn];

vector<ll> g[maxn];

set<pll> s;

void dfs(ll v){
	ll u;
	vis[v] = 1;
	m++;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(!vis[u]) dfs(u);
	}
	return;
}

int main(){
	fast_io;
	
	cin >> n;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i].F >> a[i].S;
		o[a[i].F] = i;
		c[a[i].S] = i;
	}
	
	for(ll i = 1; i <= 2 * n; i++){
		if(o[i]){
			s.insert({-i, o[i]});
		}
		else{
			s.erase({-a[c[i]].F, c[i]});
			for(set<pll>::iterator it = s.begin(); it != s.end(); it++){
				if(-it -> F < a[c[i]].F) break;
				m++;
				if(m >= n){
					cout << "NO";
					return 0;
				}
				g[c[i]].pb(it -> S);
				g[it -> S].pb(c[i]);
			}
		}
	}
	
	if(m != n - 1){
		cout << "NO";
		return 0;
	}
	
	m = 0;
	dfs(1);
	if(m != n) cout << "NO";
	else cout << "YES";
	
	return 0;
}
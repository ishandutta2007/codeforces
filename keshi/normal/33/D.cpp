//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 1100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second
#define r F
#define x S.F
#define y S.S

ll n, m, k, d[maxn][maxn], h[maxn];

pll p[maxn];

pair<ll, pll> a[maxn];

vector<ll> g[maxn];

ll dis(pll p1, pll p2){
	return (p1.F - p2.F) * (p1.F - p2.F) + (p1.S - p2.S) * (p1.S - p2.S);
}

void dfs(ll s, ll v){
	ll u;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		if(d[s][u] > d[s][v] + 1){
			d[s][u] = d[s][v] + 1;
			dfs(s, u);
		}
	}
	return;
}

int main(){
	bool f;
	ll v, u;
	fast_io;
	
	cin >> m >> n >> k;
	
	for(ll i = 1; i <= m; i++){
		cin >> p[i].F >> p[i].S;
	}
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i].r >> a[i].x >> a[i].y;
	}
	
	sort(a + 1, a + n + 1);
	
	for(ll i = 1; i <= n; i++){
		f = 1;
		for(ll j = i + 1; j <= n; j++){
			if(dis(a[i].S, a[j].S) <= a[j].r * a[j].r){
				f = 0;
				g[i].pb(j);
				g[j].pb(i);
				break;
			}
		}
		if(f){
			g[0].pb(i);
			g[i].pb(0);
		}
	}
	
	for(ll i = 0; i <= n; i++){
		fill(d[i], d[i] + n + 1, inf);
		d[i][i] = 0;
		dfs(i, i);
	}
	
	for(ll i = 1; i <= m; i++){
		for(ll j = 1; j <= n; j++){
			if(dis(p[i], a[j].S) <= a[j].r * a[j].r){
				h[i] = j;
				break;
			}
		}
	}
	
	for(ll i = 0; i < k; i++){
		cin >> v >> u;
		v = h[v];
		u = h[u];
		cout << d[v][u] << '\n';
	}
	
	return 0;
}
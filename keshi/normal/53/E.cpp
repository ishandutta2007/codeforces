//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll maxn = 20;
const ll maxm = 1e5;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, p[maxn], x, ans, k, s[maxn], dp[maxm];

bool g[maxn][maxn];

vector<ll> a[3];

int main(){
	ll v, u;
	fast_io;
	
	cin >> n >> m >> k;
	
	for(ll i = 0; i < m; i++){
		cin >> v >> u;
		v--;
		u--;
		g[v][u] = 1;
		g[u][v] = 1;
	}
	
	p[0] = 1;
	for(ll i = 1; i < maxn; i++){
		p[i] = p[i - 1] * 3;
	}
	
	for(ll i = 0; i < p[n]; i++){
		a[0].clear();
		a[1].clear();
		a[2].clear();
		x = i;
		for(ll j = 0; j < n; j++){
			s[j] = x % 3;
			a[s[j]].pb(j);
			x /= 3;
		}
		if(a[1].size() < 2) continue;
		if(a[1].size() == 2 && a[2].size() == 0){
			dp[i] = g[a[1][0]][a[1][1]];
			continue;
		}
		for(ll j = 0; j < n; j++){
			if(g[a[1][0]][j] && s[j] == 2) dp[i] += dp[i - p[a[1][0]]] + dp[i - p[a[1][0]] - p[j]];
		}
		if(a[1].size() == k && a[0].size() == 0) ans += dp[i];
	}
	
	cout << ans;
	
	return 0;
}
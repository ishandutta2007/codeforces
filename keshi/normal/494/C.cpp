//In the name of GOD
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll maxn = 2e5 + 100;
const ll maxm = 5100;
const ll mod = 1e9 + 7;
const ll inf = 1e18;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt" , "r+" , stdin) ; freopen("output.txt" , "w+" , stdout);
#define pb push_back
#define Mp make_pair
#define pll pair<ll, ll>
#define F first
#define S second

ll n, m, a[maxn], c[maxm], q2[maxn];
ld dp[maxm][maxm], ans;
pair<pll, ld> b[maxn];
vector<pll> q1[maxn];
vector<ll> q, g[maxn];

void dfs(ll v){
	ll u;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		dfs(u);
		c[v] = max(c[v], c[u]);
	}
	return;
}

ld get(ll v, ll x){
	if(x - c[v] < 0) return 0;
	if(x - c[v] >= maxm) return 1;
	return dp[v][x - c[v]];
}

void solve(ll v){
	ll u;
	ld p;
	for(ll i = 0; i < g[v].size(); i++){
		u = g[v][i];
		solve(u);
	}
	for(ll j = 0; j < maxm; j++){
		p = b[v].S;
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i];
			p *= get(u, c[v] + j - 1);
		}
		if(j) dp[v][j] += p;
		p = 1 - b[v].S;
		for(ll i = 0; i < g[v].size(); i++){
			u = g[v][i];
			p *= get(u, c[v] + j);
		}
		dp[v][j] += p;
	}
	return;
}

int main(){
	fast_io;
	
	cout << setprecision(10) << fixed;
	
	cin >> n >> m;
	
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}
	
	for(ll i = 1; i <= m; i++){
		cin >> b[i].F.F >> b[i].F.S >> b[i].S;
		q1[b[i].F.F].pb(Mp(-b[i].F.S, i));
		q2[b[i].F.S]++;
	}
	
	q.pb(0);
	
	for(ll i = 1; i <= n; i++){
		sort(q1[i].begin(), q1[i].end());
		for(ll j = 0; j < q1[i].size(); j++){
			g[q.back()].pb(q1[i][j].S);
			q.pb(q1[i][j].S);
		}
		c[q.back()] = max(c[q.back()], a[i]);
		for(ll j = 0; j < q2[i]; j++){
			q.pop_back();
		}
	}
	
	dfs(0);
	solve(0);
	
	for(ll i = 1; i < maxm; i++){
		ans += (dp[0][i] - dp[0][i - 1]) * i;
	}
	
	cout << c[0] + ans;
	
	return 0;
}
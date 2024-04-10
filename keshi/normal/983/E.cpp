//In the name of God
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const ll maxn = 2e5 + 100;
const ll mod = 1e9 + 7;
const int inf = 1e9 + 100;
const int lg = 19;

#define fast_io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define file_io freopen("input.txt", "r+", stdin);freopen("output.txt", "w+", stdout);
#define pb push_back
#define Mp make_pair
#define F first
#define S second
#define Sz(x) int((x).size())
#define all(x) (x).begin(), (x).end()

ll pw(ll a, ll b){
	ll c = 1;
	while(b){
		if(b & 1) c = c * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return c;
}

int n, m, q, par[maxn][lg], nxt[maxn][lg], d[maxn], ans[maxn], t, st[maxn], ft[maxn];
pii dp[maxn];
bool ok[maxn];
vector<int> g[maxn], gg[maxn];
vector<pii> vec[maxn];

int lca(int v, int u){
	if(d[v] < d[u]) swap(v, u);
	int h = d[v] - d[u];
	for(int i = 0; i < lg; i++){
		if((h >> i) & 1) v = par[v][i];
	}
	if(v == u) return v;
	for(int i = lg; i--;){
		if(par[v][i] != par[u][i]){
			v = par[v][i];
			u = par[u][i];
		}
	}
	return par[v][0];
}

void dfs(int v){
	st[v] = t++;
	for(int u : g[v]){
		dfs(u);
		dp[v] = min(dp[v], dp[u]);
	}
	ft[v] = t;
	nxt[v][0] = dp[v].S;
	return;
}

pii get(int v, int h){
	int x = 0;
	for(int i = lg; i--;){
		if(d[nxt[v][i]] > h){
			v = nxt[v][i];
			x += (1 << i);
		}
	}
	return Mp(v, x);
}
set<int> s[maxn];

void solve(int v){
	for(int u : gg[v]){
		s[v].insert(st[u]);
	}
	for(int u : g[v]){
		solve(u);
		if(Sz(s[v]) < Sz(s[u])){
			s[v].swap(s[u]);
		}
		for(int x : s[u]){
			s[v].insert(x);
		}
		s[u].clear();
	}
	for(pii i : vec[v]){
		if(s[v].lower_bound(st[i.F]) != s[v].end() && (*s[v].lower_bound(st[i.F])) < ft[i.F]){	
			ok[i.S] = 1;
		}
	}
}

int main(){
	fast_io;
	
	d[0] = -1;
	cin >> n;
	for(int i = 2; i <= n; i++){
		cin >> par[i][0];
		d[i] = d[par[i][0]] + 1;
		g[par[i][0]].pb(i);
		for(int j = 1; j < lg; j++){
			par[i][j] = par[par[i][j - 1]][j - 1];
		}
	}
	for(int i = 1; i <= n; i++){
		dp[i] = Mp(d[i], i);
	}
	cin >> m;
	for(int i = 0; i < m; i++){
		int v, u, x;
		cin >> v >> u;
		x = lca(v, u);
		dp[v] = min(dp[v], Mp(d[x], x));
		dp[u] = min(dp[u], Mp(d[x], x));
		gg[v].pb(u);
		gg[u].pb(v);
	}
	dfs(1);
	for(int j = 1; j < lg; j++){
		for(int i = 1; i <= n; i++){
			nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
		}
	}
	cin >> q;
	for(int i = 0; i < q; i++){
		int v, u, x;
		cin >> v >> u;
		x = lca(v, u);
		if(d[nxt[v][lg - 1]] > d[x] || d[nxt[u][lg - 1]] > d[x]){
			ans[i] = -1;
			continue;
		}
		if(x == u || x == v) ok[i] = 1;
		pii vx = get(v, d[x]);
		pii ux = get(u, d[x]);
		ans[i] = vx.S + ux.S;
		vec[vx.F].pb(Mp(ux.F, i));
	}
	solve(1);
	for(int i = 0; i < q; i++){
		if(ans[i] == -1) cout << "-1\n";
		else if(ok[i]) cout << ans[i] + 1 << "\n";
		else cout << ans[i] + 2 << "\n";
	}
	
	return 0;
}
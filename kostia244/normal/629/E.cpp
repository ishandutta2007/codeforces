#pragma GCC optimize("trapv")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#include<bits/extc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using namespace __gnu_pbds;
using oset = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;
using ld = long double;
const int maxn = 1e5 + 10;
ll n, m, tin[maxn], tout[maxn], H[maxn], pr[maxn][17], timer = 0, total = 0;
ll sz[maxn];
pi dp[maxn];
vi g[maxn];
void read() {
	cin >> n >> m;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
}
bool par(int u, int v) {
	return tin[v] >= tin[u] && tin[v] < tout[u];
}
void pre(int v, int p, int h) {
	tin[v] = timer++;
	total += h;
	sz[v] = 1;
	pr[v][0] = p;
	for(int i = 1; i < 17; i++)
		pr[v][i] = pr[pr[v][i-1]][i-1];
	for(auto i : g[v]) {
		if(i==p) continue;
		H[i] = H[v] + 1;
		pre(i, v, h + 1);
		sz[v] += sz[i];
	}
	tout[v] = timer;
}
int dist(int u, int v) {
	int ans = H[u]+H[v];
	for(int i = 17; i--;)
		if(pr[u][i]&&!par(pr[u][i], v))
			u = pr[u][i];
	u = pr[u][0];
	return ans-2*H[u];
}
void dfs(int v, int p, ll cst) {
	for(auto i : g[v]) {
		if(i == p) continue;
		dfs(i, v, cst+n-2*sz[i]);
		dp[v].first += dp[i].first + sz[i];
	}
	dp[v].second = cst - dp[v].first;
}
ld solvep(int u, int v) {
	ll szu, dpu;
	szu = n;
	dpu = dp[u].first + dp[u].second;
	for(auto i : g[u]) {
		if(par(i, v)&&!par(i, u)) {
			szu -= sz[i];
			dpu -= dp[i].first + sz[i];
			continue;
		}
	}
//	cout << u << " " << szu << " " << dpu << "\n";
//	cout << v << " " << sz[v] << " " << dp[v].first << "\n";
	ll sum = szu*dp[v].first + sz[v]*dpu;
	return 1. + H[v]-H[u] + (ld)sum/((ld)szu*sz[v]);
}
ld solvei(int u, int v) {
	ll sum = sz[u]*dp[v].first + sz[v]*dp[u].first;
	return 1. + dist(u, v) + (ld)sum/((ld)sz[u]*sz[v]);
}
void solve() {
	int u, v;
	map<pair<int, int>, ld> a;
	cout << fixed << setprecision(15);
	while(m--) {
		cin >> u >> v;
		if(u>v) swap(u, v);
		if(a.find({u, v})!=a.end()) {
			cout << a[{u, v}] << '\n';
			continue;
		}
		ld ans = 0;
		if(par(u, v)) ans = solvep(u, v);
		else if(par(v, u)) ans = solvep(v, u);
		else ans = solvei(u, v);
		cout << (a[{u, v}] = ans) << '\n';
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	read();
	H[1] = 1;
	pre(1, 1, 0);
	dfs(1, 1, total);
	solve();
	return 0;
}
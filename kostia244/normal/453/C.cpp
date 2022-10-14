#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,popcnt,sse4.1,sse4.2,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
//using arr = array;
using pi = pair<int, int>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<17, mod = 998244353 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
vi tour;
int n, m, vis[maxn], cur[maxn], a[maxn], r = -1;
vi g[maxn];
void go(int v) {
	tour.pb(v);
	cur[v]^=1;
}
void dfs(int v, int p) {
	vis[v] = 1;
	go(v);
	for(auto &i : g[v]) {
		if(vis[i]) continue;
		dfs(i, v);
		go(v);
	}
	if((cur[v]^a[v])&&p!=-1) {
		go(p);
		go(v);
	}
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int f, t, i = 0; i < m; i++) {
		cin >> f >> t;
		g[f].pb(t);g[t].pb(f);
	}
	for(int i = 1; i <= n; i++) {
		cin >> a[i];
		if(a[i]) r = i;
	}
	if(r == -1) return cout << 0, 0;
	dfs(r, -1);
	if(cur[r]!=a[r]) tour.pop_back();
	for(auto &i : tour) a[i]^=1;
	for(int i = 1; i <= n; i++) if(a[i]) return cout << -1, 0;
	cout << tour.size() << '\n';
	for(auto &i : tour) cout << i << " ";
	return 0;
}
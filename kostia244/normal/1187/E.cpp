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
using pi = pair<ll, ll>;
using vi = vector<ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1<<18, mod = 998244353 , lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
struct ctx {
	ll sz = 0, dp = 0;
	ll add_root() {
		dp += ++sz;
	}
	ll add_son(ctx s) {
		dp += s.dp + s.sz;
		sz += s.sz;
	}
	ll rem_son(ctx s) {
		dp -= s.dp + s.sz;
		sz -= s.sz;
	}
};
int n;
vi g[maxn];
ctx dp[maxn];
ll ans = 0;
void base(int v) {
	dp[v].add_root();
	for(auto i : g[v]) {
		g[i].erase(find(all(g[i]), v));
		base(i);
		dp[v].add_son(dp[i]);
	}
}
void dfs(int v, ctx x) {
	for(auto i : g[v]) {
		x.add_son(dp[i]);
	}
	ans = max(ans, x.dp);
	for(auto i : g[v]) {
		ctx t = x;
		t.rem_son(dp[i]);
		t.add_root();
		dfs(i, t);
	}
}		
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	base(1);
	ctx t;
	t.add_root();
	dfs(1, t);
	cout << ans << '\n';
	return 0;
}
#pragma GCC optimize("O2")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,tune=native")
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
/*#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<pi, null_type, less<pi>, rb_tree_tag, tree_order_statistics_node_update>;
*/
const int maxn = 1<<18, mod = 1e9 + 7, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, k, sm[maxn], deg[maxn], p[maxn], h[maxn];
vi g[maxn];
void dfs(int v, int pr) {
	p[v] = pr;
	for(auto i : g[v]) {
		if(i != pr) h[i] = h[v]+1, dfs(i, v), deg[v]++;
	}
}
ll get(int i) {
	return h[i] - sm[i];
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	dfs(1, 0);
	priority_queue<pi> q;
	for(int i = 1; i <= n; i++) {
		if(deg[i] == 0) q.push({get(i), i});
	}
	ll ans = 0;
	while(k--) {
		auto [cst, v] = q.top();
		q.pop();
		ans += cst;
		sm[p[v]] += sm[v]+1;
		v = p[v];
		if(--deg[v] == 0) {
			q.push({get(v), v});
		}
	}
	cout << ans;
	return 0;
}
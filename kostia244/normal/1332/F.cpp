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
using pi = pair<int, int>;
using vi = vector<int>;
using vpi = vector<pi>;
using ld = long double;
#include<bits/extc++.h>
using namespace __gnu_pbds;
using oset = tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update>;
const int maxn = 1<<19, mod = (119<<23)+1;
int n;
ll dp[maxn][3];
vi g[maxn];
ll calc(int v, int p, int a, int b, int c) {//, int d, int e) {
	ll res = 1;
	for(auto &i : g[v]) if(i!=p) {
		ll t = dp[i][0]*a + dp[i][1]*b + dp[i][2]*c;// + dp[i][3]*d + dp[i][4]*e;
		t%=mod;
		res = res*t%mod;
	}
	return res;
}
void dfs(int v, int p) {
	for(auto &i : g[v]) if(i!=p) dfs(i, v);
	dp[v][0] = calc(v, p, 1, 1, 1);
	dp[v][1] =(mod + calc(v, p, 2, 1, 2) - dp[v][0])%mod;//tk
	dp[v][2] =(mod + calc(v, p, 3, 2, 2) - dp[v][0])%mod;// !tk
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
	int r = 1;
	dfs(r, 0);
	cout << (mod+dp[r][0]+dp[r][1]+dp[r][2]-1)%mod;
}
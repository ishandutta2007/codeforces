//#pragma GCC optimize("Ofast")
//#pragma GCC target("avx2,tune=native")
//#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("trapv")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using vi = vector<ll>;
using vvi = vector<vi>;
using pi = pair<ll, ll>;
const ll mod = 1e9 + 7;
//#define combine AERENORZ
template<typename X, typename Y>
void minq(X &a, Y b) {
	if (a > b)
		a = b;
}
template<typename X, typename Y>
void maxq(X &a, Y b) {
	if (a < b)
		a = b;
}

int n, k, a[220];
vvi g;
struct res {
	int sz, dp[220];
	res() {
		sz = 0;
		memset(dp, -63, sizeof dp);
	}
	ll getMax() const {
		ll ans = 0;
		for (int i = 0; i <= sz; i++)
			maxq(ans, dp[i]);
		return ans;
	}
};
int suf[220];
res combine(res a, res b) {
	res comb;
	comb.sz = a.sz+b.sz;
	for(int i = b.sz; i--;)
		b.dp[i+1] = b.dp[i];
	for(int i = 0; i <= comb.sz; i++)
		comb.dp[i] = max(a.dp[i], b.dp[i]);
	for(int i = 0; i <= a.sz; i++) {
		for(int j = max(0, k-i); j <= b.sz; j++) {
			maxq(comb.dp[min(i, j)], a.dp[i]+b.dp[j]);
		}
	}
	return comb;
}
res dfs(int v, int p) {
	res ans;
	ans.dp[0]=a[v];
	ans.sz=1;
	for(auto i : g[v]) {
		if(i==p) continue;
		ans = combine(ans, dfs(i, v));
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k, k++;
	g.resize(n+1);
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int f, t, i = 1; i < n; i++) {
		cin >> f >> t;
		g[f].pb(t);
		g[t].pb(f);
	}
	cout << dfs(1, 1).getMax();
}
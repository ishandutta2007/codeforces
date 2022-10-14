#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
const int maxn = 5050, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll n, s, e, x[maxn], a[maxn], b[maxn], c[maxn], d[maxn];
ll dp[maxn][maxn];
ll f(int i, int op, int cl) {
	if(i == n) return op == 0 && cl == 0 ? 0 : 1ll<<60;
	if(dp[i][max(cl, op)] != -1) return dp[i][max(cl, op)];
	ll t = 0, ans = 1ll<<60;
	if(i) t += (x[i] - x[i-1])*(op+cl);
	if(i == e-1) {
		return dp[i][max(cl, op)] = min({
			1ll<<60,
			(op && (i+1 == n || op+cl>1) ? ll(f(i+1, op-1, cl) + a[i] + t) : 1ll<<60),
			ll(f(i+1, op, cl+1) + b[i] + t)
		});
	}
	if(i == s-1) {
		return dp[i][max(cl, op)] = min({
			1ll<<60,
			(cl && (i+1 == n || op+cl>1) ? ll(f(i+1, op, cl-1) + c[i] + t) : 1ll<<60),
			ll(f(i+1, op+1, cl) + d[i] + t)
		});
	}
	ans = f(i+1, op+1, cl+1) + b[i] + d[i];
	if(cl) ans = min(ans, f(i+1, op, cl) + c[i] + b[i]);
	if(op) ans = min(ans, f(i+1, op, cl) + a[i] + d[i]);
	if(op && cl && (i+1 == n || op+cl > 2)) ans = min(ans, f(i+1, op-1, cl-1) + c[i] + a[i]);
	return dp[i][max(cl, op)] = ans + t;
}
void stupid() {
	vector<int> ans = {0, 1, 2, 3, 4};
	pair<ll, vector<int>> res = {1ll<<60, {}};
	do {
		if(ans[0]+1 != s || ans.back()+1!=e) continue;
		ll cur = 0;
		for(int i = 1; i < n; i++) {
			int l = ans[i-1], r = ans[i];
			cur += abs(x[l] - x[r]);
			if(l < r) cur += d[l] + a[r];
			else cur += c[l] + b[r];
		}
		res = min(res, {cur, ans});
	} while(next_permutation(all(ans)));
	cout << res.first << endl;
	for(auto &i : res.second) cout << i << " "; cout << endl;
}
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> s >> e;
	memset(dp, -1, sizeof dp);
	for(int i = 0; i < n; i++) cin >> x[i];
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < n; i++) cin >> b[i];
	for(int i = 0; i < n; i++) cin >> c[i];
	for(int i = 0; i < n; i++) cin >> d[i];
	//stupid();
	cout << f(0, 0, 0) << endl;
	//for(auto i : dp)
	//	cout << i.first[0] << " " << i.first[1] << " " << i.first[2] << " " << i.second << endl;
}
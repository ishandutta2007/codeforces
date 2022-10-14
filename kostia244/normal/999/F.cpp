#pragma GCC optimize("trapv")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define pb push_back
#include <x86intrin.h>
#define pb push_back
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;
const int maxn = 5005, mod = 998244353;
int n,k;
vi c, f, h;
ll dp[503][5002];
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k;
	c.resize(n*k);
	for(auto &i : c) cin >> i;
	f.resize(n);
	for(auto &i : f) cin >> i;
	h.resize(k);
	sort(all(c));
	sort(all(f));
	for(auto &i : h) cin >> i;
	memset(dp, -0x3d, sizeof dp);
	dp[0][0] = 0;
	for(int i = 0; i <= n; i++) {
		for(int j = 0; j <= k*n; j++) {
			if(j) dp[i][j] = max(dp[i][j], dp[i][j-1]);
			if(dp[i][j]<0) continue;
			if(i==n) continue;
			dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
			int pos = max(j, int(lower_bound(all(c), f[i])-c.begin()));
			for(int z = 1; z <= k && pos + z <= 5000 && pos + z <= k*n && c[pos+z-1]==f[i]; z++) {
				dp[i+1][pos+z] = max(dp[i+1][pos+z], dp[i][j] + h[z-1]);
			}
		}
	}
	cout << dp[n][k*n];
}
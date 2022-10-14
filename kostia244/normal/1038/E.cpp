#pragma GCC optimize("O2")
//#pragma GCC optimize("unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2,fma,tune=native")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
using namespace std;
using ll = long long;
using vi = vector<ll>;
using pi = pair<ll, ll>;
using vpi = vector<pi>;
using ld = long double;
const int maxn = 1e2 + 10, mod = 1e9 + 7;
int dp[1<<20], ndp[1<<20];
int l, r, val, n;
int shft(int a, int x) {
	return a<<(5*x);
}
inline int state(int msk, int l, int r) {
	msk^=shft(1,l);
	msk|=shft(2<<l,l);
	msk|=shft(2<<r,l);
	msk^=shft(1,r);
	msk|=shft(2<<r,r);
	msk|=shft(2<<l,r);
	return msk;
}
int col[4], g;
void dfs(int i, int msk) {
	col[i] = 1;
	for(int j = 0; j < 4; j++) {
		if(i==j) continue;
		if((msk&shft(2<<j, i))&&!col[j]) dfs(j, msk);
	}
}
bool valid(int msk) {
	for(int i = 0; i < 4; i++)
		col[i] = 0;
	g = 0;
	for(int i = 0; i < 4; i++)
		g += (msk & shft(1,i)) >0;
	if(g > 2)
		return 0;
	g = 0;
	int k = 0;
	while(k<4&&!(msk&shft(2<<k, k))) k++;
	if(k==4) return 0;
	dfs(k, msk);
	for(int i = 0; i < 4; i++) {
		if((msk&shft(2<<i, i))&&!col[i]) return 0;
	}
	return 1;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	memset(dp, -0x3f, sizeof dp);
	dp[0] = 0;
	for(int _ = 0; _ < n; _++) {
		cin >> l >> val >> r, l--, r--;
		for(int i = 0; i < 1<<20; i++) ndp[i] = dp[i];
		for(int i = 0; i < 1<<20; i++) {
			int t = state(i, l, r);
			ndp[t] = max(ndp[t], dp[i]+val);
		}
		for(int i = 0; i < 1<<20; i++) dp[i] = ndp[i];
	}
	int ans = 0;
	for(int i = 0; i < 1<<20; i++) {
		if(valid(i)) {
			ans = max(ans, dp[i]);
		}
	}
	cout << ans;
	return 0;
}
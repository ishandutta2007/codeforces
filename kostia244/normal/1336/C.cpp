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
const int maxn = 1<<12, mod = 119<<23|1, lg = 19;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
ll dp[maxn][maxn];
string s, t;
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s >> t;
	int n = s.size(), m = t.size();
	s = " " + s, t = " " + t;
	for(int i = 0; i <= n; i++) {
		dp[i][i+1] = 1;
	}
	ll ans = 0;
	for(int l = 1; l <= n+1; l++)
		for(int i = 0, j = l; j <= n+1; i++, j++) {
			if(i&&(i>m||s[l]==t[i])) {
				(dp[i-1][j] += dp[i][j])%=mod;
			}
			if(j!=n+1&&(j>m||s[l]==t[j])) {
				(dp[i][j+1] += dp[i][j])%=mod;
			}
			if(i==0&&j>m) (ans += dp[i][j])%=mod;
		}
	cout << ans;
	return 0;
}
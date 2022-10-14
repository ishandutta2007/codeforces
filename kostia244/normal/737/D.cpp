#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3")
#include<bits/stdc++.h>
#define all(x) x.begin(), x.end()
using namespace std;
using ll = long long;
using ld = long double;
const int maxn = 4040, mod = 1e9 + 7;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const int C = 94;
int dp[128][C][4040][2];
int n, a[maxn];
inline __attribute__(( always_inline )) int get(int l, int r) { return a[r] - a[l-1]; }
inline __attribute__(( always_inline )) void minq(int &a, const int& b) { a = min(a, b); }
inline __attribute__(( always_inline )) void maxq(int &a, const int& b) { a = max(a, b); }
signed main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i], a[i] += a[i-1];
	for(int l = 0; l < 128; l++) {
		for(int r = 0; r < 4040; r++)
			for(int k = 0; k < 93; k++) {
				dp[l][k][r][0] = (1<<30);
				dp[l][k][r][1] = -(1<<30);
			}
	}
	ll score = 0;
	for(int L = n+1; L-- > 0;) {
		int l = L&127;
		//int lc = a[L] - a[n] + a[L];
		for(int r = n-L+1; r-- > 0;)
		for(int k = min(C-1, n-L-r)+1; k < C; k++) {
		    int x = get(1, L) - get(n-r+1, n);
			dp[l][k][r][0] = dp[l][k][r][1] = x;
		}
		for(int k = C-2; k > 0; k--) {
			for(int r = n-L-k+1; r-- > 0;) {
				dp[l][k][r][0] = max(dp[(l+k)&127][k][r][1],
				 dp[(l+k+1)&127][k+1][r][1]);
				dp[l][k][r][1] = min(dp[l][k][r+k][0], dp[l][k+1][r+k+1][0]);
			}
		}
			//lc += a[n-r+1];
	}
	cout << dp[0][1][0][0] << endl;
}
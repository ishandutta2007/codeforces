#include <bits/stdc++.h>
using namespace std;

#define ucin ios::sync_with_stdio(0), cin.tie(0)
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
typedef pair<int, int> pii;
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;

const int N = 3000 + 10;
const int mod = 998244353;

int qpow(int a, int b) {
	int ans = 1;
	for(; b >= 1; b >>= 1, a = (ll) a * a % mod)
		if(b & 1) ans = (ll) ans * a % mod;
	return ans;
}
char s[N], t[N];
int n, m, dp[N][N];
int main() {
	scanf("%s%s", s + 1, t + 1);
	n = strlen(s + 1); m = strlen(t + 1);
	for(int i = n; i >= 1; i --) {
		for(int j = i; j <= n; j ++) {
			if(i == j) {
				dp[i][i] = (s[1] == t[i] || i > m) ? 2 : 0;
			} else {
				dp[i][j] = 0;
				if(s[j - i + 1] == t[i] || i > m) (dp[i][j] += dp[i + 1][j]) %= mod; 
				if(s[j - i + 1] == t[j] || j > m) (dp[i][j] += dp[i][j - 1]) %= mod; 
			}
		}
	}
	int ans(0);
	for(int i = m; i <= n; i ++) {
		(ans += dp[1][i]) %= mod;
	}
	printf("%d\n", ans);
	return 0;
}
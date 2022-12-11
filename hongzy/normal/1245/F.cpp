#include <bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define mp make_pair
#define pb push_back
#define ucin() ios :: sync_with_stdio(0)
typedef vector<int> vi;
typedef map<int, int> mii;
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long double ld;
typedef long long ll;
typedef double db;

const int N = 35;
int a1[N], a2[N], n1, n2, len;
ll dp[N][2][2];
ll dfs(int u, bool l1, bool l2) {
	if(u == 0) return 1;
	if(~ dp[u][l1][l2]) return dp[u][l1][l2];
	ll ans = 0;
	int r1 = l1 ? a1[u] : 1;
	int r2 = l2 ? a2[u] : 1;
	for(int i = 0; i <= r1; i ++) {
		for(int j = 0; j <= r2; j ++) if((i & j) == 0) {
			ans += dfs(u - 1, l1 && i == r1, l2 && j == r2);
		}
	}
	dp[u][l1][l2] = ans;
	return ans;
}
ll q(int n, int m) {
	if(n < 0 || m < 0) return 0;
	if(n == 0) return m + 1ll;
	if(m == 0) return n + 1ll;
	n1 = n2 = 0; memset(dp, -1, sizeof dp);
	while(n) { a1[++ n1] = n & 1; n >>= 1; }
	while(m) { a2[++ n2] = m & 1; m >>= 1; }
	len = max(n2, n1);
	for(int i = n1 + 1; i <= len; i ++) a1[i] = 0;
	for(int i = n2 + 1; i <= len; i ++) a2[i] = 0;
	return dfs(len, 1, 1);
}
int main() {
	ucin(); int t; cin >> t;
	while(t --) {
		int l, r; cin >> l >> r;
		cout << ( q(r, r) - 2ll * q(l - 1, r) + q(l - 1, l - 1) ) << endl;
	}
	return 0;
}
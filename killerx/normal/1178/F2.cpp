#include <bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
#define mod 998244353
#define pb push_back
#define mp make_pair
#define ll long long
#define vi vector <int>
#define pii pair <int, int>
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define rep(i,n) for (int i = 0; i < (int) (n); ++ i)
#define foreach(it,c) for (__typeof(c.begin()) it = c.begin(); it != c.end(); ++ it)

inline int read() {
	int x = 0, f = 1, c = getchar();
	for (;!isdigit(c);c = getchar()) if (c == '-') f ^= 1;
	for (; isdigit(c);c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}

int n, m;
int c[1000005];
int dp[1005][1005];
int pl[505], pr[505];

int DP(int l, int r) {
//	eprintf("%d %d\n", l, r);
	if (l >= r) return 1;
	if (~dp[l][r]) return dp[l][r];
	int mn = l;
	for (int i = l; i <= r; ++ i) if (pl[c[i]] < l || pr[c[i]] > r) return 0;
	for (int i = l; i <= r; ++ i) if (c[i] < c[mn]) mn = i;
	vi v;
	for (int i = l; i <= r; ++ i) if (c[i] == c[mn]) v.pb(i);
	dp[l][r] = 1;
	rep(i, v.size() - 1) dp[l][r] = 1LL * dp[l][r] * DP(v[i] + 1, v[i + 1] - 1) % mod;
	int lft = 0, rgt = 0;
	for (int i = l; i <= pl[c[mn]]; ++ i) (lft += 1LL * DP(l, i - 1) * DP(i, pl[c[mn]] - 1) % mod) %= mod;
	for (int i = pr[c[mn]]; i <= r; ++ i) (rgt += 1LL * DP(pr[c[mn]] + 1, i) * DP(i + 1, r) % mod) %= mod;
	dp[l][r] = 1LL * dp[l][r] * lft % mod * rgt % mod;
//	eprintf("%d %d %d\n", l, r, dp[l][r]);
	return dp[l][r];
}

int main() {
	n = read(), m = read();
	rep(i, m) c[i] = read();
	m = unique(c, c + m) - c;
	memset(pl, -1, sizeof pl); memset(pr, -1, sizeof pr);
	rep(i, m) if (!~pl[c[i]]) pl[c[i]] = i;
	rep(i, m) if (!~pr[c[m - i - 1]]) pr[c[m - i - 1]] = m - i - 1;
	if (m > 1000) {puts("0"); return 0;}
	rep(i, m) for (int j = c[i] + 1; j <= n; ++ j) if (pl[j] <= i && i <= pr[j]) {puts("0"); return 0;}
	memset(dp, -1, sizeof dp);
	printf("%d\n", DP(0, m - 1));
	return 0;
}
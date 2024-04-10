// Code by Denverjin.
#include <bits/stdc++.h>
using namespace std;

#define ld double
#define ll long long
#define pii pair <int, int>
#define ull unsigned long long
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define rep(i, n) for (int i = 0; i < (int)(n); ++ i)

#define PI acos(-1)
#define MOD 51123987
#define MUL 191260817
#define EPS 1e-10
#define INF 1 << 30
#define LINF 1LL << 60

template <typename T> inline void chkmin(T &x, T y) {if (y < x) x = y;}
template <typename T> inline void chkmax(T &x, T y) {if (y > x) x = y;}
template <typename T> inline T add(T x, T y) {return (x + y) % MOD;}
template <typename T> inline T mul(T x, T y) {return 1LL * x * y % MOD;}
template <typename T> inline T qp(T x, T n) {
	T ans = 1;
	do {if (n & 1) ans = mul(ans, x); x = mul(x, x);} while (n >>= 1);
	return ans;
}

const int SZ = 1 << 13;
char buff[SZ], *pos = buff + SZ - 1;
#define getchar() (++ pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos)

inline ll read() {
	ll x = 0; int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

int n, v;
int dp[105][105];

int main() {
	n = read(), v = read();
	rep(i, n + 1) rep(j, v + 1) dp[i][j] = INF;
	dp[0][0] = 0;
	rep(i, n) {
		rep(j, v + 1) rep(k, j + 1) chkmin(dp[i][j], dp[i][j - k] + k * (i + 1));
		rep(k, v + 1) for (int j = i + 1; j <= n; ++ j) if (k - j + i >= 0) chkmin(dp[j][k - j + i], dp[i][k]);
	}
	int ans = INF;
	rep(j, v + 1) chkmin(ans, dp[n - 1][j]);
	printf("%d\n", ans);
	return 0;
}
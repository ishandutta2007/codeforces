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
#define MOD 1000000007
#define MUL 19260817
#define EPS 1e-10
#define INF 1e9
#define LINF 1e18

template <typename T> inline void chkmin(T &x, T y) {if (y < x) x = y;}
template <typename T> inline void chkmax(T &x, T y) {if (y > x) x = y;}
template <typename T> inline T add(T x, T y) {return (x + y) % MOD;}
template <typename T> inline T mul(T x, T y) {return 1LL * x * y % MOD;}
template <typename T> inline T qp(T x, T n) {
	T ans = 1;
	do {if (n & 1) ans = mul(ans, x); x = mul(x, x);} while (n >>= 1);
	return ans;
}

#ifndef DEBUG
const int SZ = 1 << 13;
char buff[SZ], *pos = buff + SZ - 1;
#define getchar() (++ pos == buff + SZ ? fread(pos = buff, 1, SZ, stdin), *pos : *pos)
#endif

inline ll read() {
	ll x = 0; int f = 1, c = getchar();
	for (;!isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = (x<<3) + (x<<1) + (c^48);
	return x * f;
}

const int N = 5005;
int n, a, b;
char s[N];
int lcp[N][N];
int z[N];
int dp[N];
char ss[N];

void calcZ(int m) {
	int l = 0, r = 0;
	memset(z, 0, sizeof z);
	for (int i = 1; i < m; ++ i) {
		if (i <= r) z[i] = min(z[i - l], r - i + 1);
		for (; i + z[i] < m && ss[i + z[i]] == ss[z[i]]; ++ z[i]);
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;
	}
}

int main() {
	n = read(), a = read(), b = read();
	rep(i, n) s[i] = getchar();
	rep(i, n) {
		int m = 0;
		for (int j = i; j < n; ++ j) ss[m ++] = s[j];
		calcZ(m);
		rep(j, m) if (j) lcp[i + j][i] = z[j]; 
	}
	memset(dp, 0x3f, sizeof dp);
	dp[0] = 0;
	rep(i, n) {
		chkmin(dp[i + 1], dp[i] + a);
		int mx = 0;
		rep(j, i) chkmax(mx, min(lcp[i][j], i - j));
		for (int j = i + 1; j - i <= mx; ++ j) chkmin(dp[j], dp[i] + b);
	}
	printf("%d\n", dp[n]);
	return 0;
}
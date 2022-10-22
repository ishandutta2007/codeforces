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

int n = read(), m = read();
int dp[45][1000];
int pw3[45];

int getbit(int mask, int pos) {return (mask / pw3[pos]) % 3;}

int main() {
	if (n < m) swap(n, m);
	pw3[0] = 1;
	rep(i, 44) pw3[i + 1] = pw3[i] * 3;
	rep(i, 45) rep(j, 1000) dp[i][j] = INF;
	int ini = 0, full = 1;
	rep(i, m) full *= 3, ini = ini * 3 + 1;
	dp[0][ini] = 0;
	rep(i, n) rep(j, full) if (dp[i][j] < INF) {
		rep(k, 1 << m) {
			int nj = 0;
			bool ok = 1;
			rep(l, m) if (getbit(j, l) == 0 && !(k & 1 << l)) ok = 0;
			if (ok) {
				rep(l, m) {
					if (k & 1 << l) nj = nj * 3 + 2;
					else if (getbit(j, l) == 2 || (l && k & 1 << (l - 1)) || (l + 1 < m && k & 1 << (l + 1))) nj = nj * 3 + 1;
					else nj = nj * 3;
				}
				chkmin(dp[i + 1][nj], dp[i][j] + __builtin_popcount(k));
			}
		}
	}
	int ans = INF;
	rep(i, 1 << m) {
		int mask = 0;
		rep(j, m) {
			mask = mask * 3 + 1;
			if (i & 1 << j) mask ++;
		}
		chkmin(ans, dp[n][mask]);
	}
	printf("%d\n", n * m - ans);
	return 0;
}
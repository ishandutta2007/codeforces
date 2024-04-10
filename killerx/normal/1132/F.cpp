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

const int N = 505;
int n;
char s[N];
int dp[N][N];

int DP(int l, int r) {
	if (l > r) return 0;
	if (~dp[l][r]) return dp[l][r];
//	printf("%d %d\n", l, r);
	dp[l][r] = INF;
	for (char c = 'a'; c <= 'z'; ++ c) {
		vector <pii> v;
		v.PB(MP(l - 1, l - 1));
		for (int i = l; i <= r; ++ i) {
			if (s[i] == c) {
				if (!v.empty() && i == v.back().S + 1) v.back().S ++;
				else v.PB(MP(i, i));
			}
		}
		v.PB(MP(r + 1, r + 1));
		vector <int> f(v.size(), INF);
		f[0] = 0;
		rep(i, v.size()) {
			for (int j = i + 1; j < v.size(); ++ j) {
				chkmin(f[j], f[i] + DP(v[i].S + 1, v[j].F - 1));
			}
		}
		chkmin(dp[l][r], f[v.size() - 1] + 1);
	}
//	printf("%d %d = %d\n", l, r, dp[l][r]);
	return dp[l][r];
}

int main() {
	n = read();
	rep(i, n) s[i] = getchar();
	memset(dp, ~0, sizeof dp);
	printf("%d\n", DP(0, n - 1));
	return 0;
}
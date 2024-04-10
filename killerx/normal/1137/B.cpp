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

const int N = 1 << 20;
int n, m, nn;
char S[N], T[N];
int Z[N];

int main() {
	for (; !isspace(S[n] = getchar()); ++ n);
	for (; !isspace(T[m] = getchar()); ++ m);
	for (int L = 0, R = 0, i = 1; i < m; ++ i) {
		if (i <= R) Z[i] = min(R - i + 1, Z[i - L]);
		while (i + Z[i] < m && T[i + Z[i]] == T[Z[i]]) ++ Z[i];
		if (i + Z[i] - 1 > R) L = i, R = i + Z[i] - 1;
	}
	int Mx = 0;
	for (int i = 1; i < m; ++ i) {
		if (Z[m - i] >= i) Mx = i;
	}
//	printf("%d\n", Mx);
	int cnt[2];
	cnt[0] = cnt[1] = 0;
	rep(i, n) cnt[S[i] - '0'] ++;
	int cntt[2];
	cntt[0] = cntt[1] = 0;
	rep(i, Mx) cntt[T[i] - '0'] ++;
	int cnttt[2];
	cnttt[0] = cnttt[1] = 0;
	for (int i = Mx; i < m; ++ i) cnttt[T[i] - '0'] ++;
	if (cnt[0] >= cntt[0] && cnt[1] >= cntt[1]) {
		cnt[0] -= cntt[0]; cnt[1] -= cntt[1];
		rep(i, Mx) S[nn ++] = T[i];
		for (int i = 0; ; ++ i) {
			if (cnt[0] >= cnttt[0] && cnt[1] >= cnttt[1]) {
				cnt[0] -= cnttt[0]; cnt[1] -= cnttt[1];
				for (int j = Mx; j < m; ++ j) S[nn ++] = T[j];
			} else break;
		}
	}
	while (cnt[0]) S[nn ++] = '0', cnt[0] --;
	while (cnt[1]) S[nn ++] = '1', cnt[1] --;
//	printf("%d\n", nn);
	printf(S);
	return 0;
}
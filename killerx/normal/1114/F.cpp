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

const int N = 1 << 19;
const int B = 450;
int p[100], invp[100], psz;
ll msk[305];
int n, q;
int pwB[305];

struct Node {int a; ll b;};
Node a[N], b[N / B], c[N / B];

int main() {
	for (int i = 2; i <= 300; ++ i) {
		bool ok = 1;
		for (int j = 2; j * j <= i; ++ j) if (i % j == 0) ok = 0;
		if (ok) p[psz ++] = i;
	}
	rep(i, psz) invp[i] = qp(p[i], MOD - 2);
	for (int i = 1; i <= 300; ++ i) pwB[i] = qp(i, B);
	for (int i = 1; i <= 300; ++ i) rep(j, psz) if (i % p[j] == 0) msk[i] |= 1LL << j;
	n = read(), q = read();
	rep(i, n) a[i].a = read();
	rep(i, n) a[i].b = msk[a[i].a];
	rep(i, n) b[i / B].a = 1;
	rep(i, n) c[i / B].a = 1;
	rep(i, n) c[i / B].a = mul(c[i / B].a, a[i].a);
	rep(i, n) c[i / B].b |= a[i].b;
	while (q --) {
		char tp = getchar();
		int l = read() - 1, r = read();
		if (tp == 'T') {
			int ans = 1;
			ll msk = 0;
			while (l < r && l % B) {ans = mul(ans, mul(a[l].a, b[l / B].a)); msk |= a[l].b | b[l / B].b; ++ l;}
			while (l < r && r % B) {-- r; ans = mul(ans, mul(a[r].a, b[r / B].a)); msk |= a[r].b | b[r / B].b;}
			while (l < r) {ans = mul(ans, c[l / B].a); msk |= c[l / B].b; l += B;}
			rep(j, psz) if (msk & 1LL << j) ans = mul(ans, mul(invp[j], p[j] - 1));
			printf("%d\n", ans);
		}
		if (tp == 'M') {
			int x = read();
			while (l < r && l % B) {a[l].a = mul(a[l].a, x); a[l].b |= msk[x]; c[l / B].a = mul(c[l / B].a, x); c[l / B].b |= msk[x]; ++ l;}
			while (l < r && r % B) {-- r; a[r].a = mul(a[r].a, x); a[r].b |= msk[x]; c[r / B].a = mul(c[r / B].a, x); c[r / B].b |= msk[x];}
			while (l < r) {b[l / B].a = mul(b[l / B].a, x); b[l / B].b |= msk[x]; c[l / B].a = mul(c[l / B].a, pwB[x]); c[l / B].b |= msk[x]; l += B;}
		}
	}
	return 0;
}
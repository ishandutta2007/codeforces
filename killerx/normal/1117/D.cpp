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

#define vec vector <int>
#define mat vector <vec>

mat mul(mat a, mat b) {
	mat c(a.size(), vec(b[0].size(), 0));
	rep(i, a.size()) rep(j, b[0].size()) rep(k, b.size()) {
		c[i][j] = add(c[i][j], mul(a[i][k], b[k][j]));
	}
	return c;
}

mat qp(mat x, ll n) {
	mat ans(x.size(), vec(x.size(), 0));
	rep(i, x.size()) ans[i][i] = 1;
	do {if (n & 1) ans = mul(ans, x); x = mul(x, x);} while (n >>= 1);
	return ans;
}

ll n;
int m;

int main() {
	n = read(), m = read();
	mat base(m, vec(m, 0));
	rep(i, m - 1) base[i + 1][i] = 1;
	base[0][0] = base[0][m - 1] = 1;
	mat x = qp(base, n);
//	rep(i, m) rep(j, m) printf("%d%c", x[i][j], " \n"[j + 1 == m]);
	printf("%d\n", x[0][0]);
	return 0;
}
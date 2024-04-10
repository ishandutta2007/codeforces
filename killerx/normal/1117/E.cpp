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

const int N = 1 << 20;
char a[N], b[N], c[N], d[N], ans[N];
int aa[N], bb[N], cc[N];
map <int, int> mp;

int main() {
	scanf("%s", a);
	int n = strlen(a);
	rep(i, n) b[i] = i % 23 + 'a';
	rep(i, n) c[i] = i % 25 + 'a';
	rep(i, n) d[i] = i % 26 + 'a';
	printf("? %s\n", b); fflush(stdout); scanf("%s", b); rep(i, n) aa[i] = b[i] - 'a';
	printf("? %s\n", c); fflush(stdout); scanf("%s", c); rep(i, n) bb[i] = c[i] - 'a';
	printf("? %s\n", d); fflush(stdout); scanf("%s", d); rep(i, n) cc[i] = d[i] - 'a';
	rep(i, n) mp[((i % 23) * 100 + i % 25) * 100 + i % 26] = i;
	rep(i, n) ans[mp[(aa[i] * 100 + bb[i]) * 100 + cc[i]]] = a[i];
	printf("! %s\n", ans); fflush(stdout);
	return 0;
}
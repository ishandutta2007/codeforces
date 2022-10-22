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
int n, q;
int l[N], r[N];
int cnt[N];
int a[N];
int summ[N];

int main() {
	n = read(), q = read();
	rep(i, q) l[i] = read(), r[i] = read();
	rep(i, q) cnt[l[i]] ++, cnt[r[i] + 1] --;
	int ans = 0;
	rep(i, q) {
		cnt[l[i]] --, cnt[r[i] + 1] ++;
		rep(j, n) a[j + 1] = a[j] + cnt[j + 1];
		int cur = 0;
		for (int j = 1; j <= n; ++ j) if (a[j]) ++ cur;
		for (int j = 1; j <= n; ++ j) summ[j] = a[j] == 1;
		for (int j = 1; j <= n; ++ j) summ[j] += summ[j - 1];
		int mn = INF;
		rep(j, q) if (j != i) chkmin(mn, summ[r[j]] - summ[l[j] - 1]);
		cur -= mn;
		chkmax(ans, cur);
		cnt[l[i]] ++, cnt[r[i] + 1] --;
	}
	printf("%d\n", ans);
	return 0;
}
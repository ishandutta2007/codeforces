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

const int N = 1 << 10;
int n, m;
int a[N][N];
vector <int> va[N], vb[N];

int main() {
	n = read(), m = read();
	rep(i, n) rep(j, m) a[i][j] = read();
	rep(i, n) rep(j, m) va[i].PB(a[i][j]);
	rep(i, n) rep(j, m) vb[j].PB(a[i][j]);
	rep(i, n) sort(va[i].begin(), va[i].end()), va[i].erase(unique(va[i].begin(), va[i].end()), va[i].end());
	rep(i, m) sort(vb[i].begin(), vb[i].end()), vb[i].erase(unique(vb[i].begin(), vb[i].end()), vb[i].end());
	rep(i, n) rep(j, m) {
		int aa = lower_bound(va[i].begin(), va[i].end(), a[i][j]) - va[i].begin();
		int ab = lower_bound(vb[j].begin(), vb[j].end(), a[i][j]) - vb[j].begin();
//		printf("%d %d %d %d %d %d\n", i, j, aa, ab, va[i].size(), vb[i].size());
		int sa = va[i].size();
		int sb = vb[j].size();
		if (aa < ab) {
			swap(aa, ab);
			swap(sa, sb);
		}
		printf("%d", max(sa, sb + aa - ab));
		if (j + 1 == m) puts(""); else putchar(' ');
	}
	return 0;
}
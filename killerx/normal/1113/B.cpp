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

const int N = 1 << 20;
int n;
int a[N];
int sum;

int main() {
	n = read();
	rep(i, n) a[i] = read();
	sort(a, a + n);
	rep(i, n) sum += a[i];
	int ans = sum;
	rep(i, n) if (i) {
		for (int j = 2; j < a[i]; ++ j) {
			if (a[i] % j == 0) {
				chkmin(ans, a[i] / j + a[0] * j + sum - a[i] - a[0]);
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}
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

const int N = 5005;
char s[N];
int n;
char ss[N];

int main() {
	while (!isspace(s[n] = getchar())) ++ n;
	bool ok = 0;
	rep(i, n / 2) if (s[i] != s[0]) ok = 1;
	if (!ok) return puts("Impossible"), 0;
	rep(i, n) if (i) {
		int k = 0;
		for (int j = i; j < n; ++ j) ss[k ++] = s[j];
		rep(j, i) ss[k ++] = s[j];
		bool ok = 1;
		rep(j, n) if (ss[j] != ss[n - 1 - j]) ok = 0;
		bool eq = 1;
		rep(j, n) if (ss[j] != s[j]) eq = 0;
		if (ok && !eq) return puts("1"), 0;
	}
	return puts("2"), 0;
}
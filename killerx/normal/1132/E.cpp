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

ll w;
ll cnt[9], use[9];

int main() {
	w = read();
	for (int i = 1; i <= 8; ++ i) cnt[i] = read();
	mt19937_64 rnd(19260817);
	ll ans = 0;
	{
		int id[9];
		for (int i = 1; i <= 8; ++ i) id[i] = i;
		do {
			ll nw = 0;
			for (int i = 1; i <= 8; ++ i) {
				ll use = min(cnt[id[i]], (w - nw) / id[i]);
				nw += id[i] * use;
			}
			chkmax(ans, nw);
		} while (next_permutation(id + 1, id + 9));
	}
	ll nw = 0;
	for (ld t = 1; t > EPS; t *= 0.999999) {
//		printf("%.10f\n", t);
		int i = rnd() % 8 + 1;
		ll nwuse = 0;
		if (nw <= w) chkmax(ans, nw);
		if (nw < w) nwuse = cnt[i] - rnd() % (ll)((cnt[i] - use[i]) * t + 1);
		else nwuse = use[i] - rnd() % (ll)(use[i] * t + 1);
		nw += (nwuse - use[i]) * i;
		use[i] = nwuse;
	}
	printf("%lld\n", ans);
	return 0;
}
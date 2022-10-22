#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define ld double
#define ll long long
//#define pii pair <int, int>
#define ull unsigned long long
//#define F first
//#define S second
#define PB push_back
//#define MP make_pair
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

struct pii {
	int F, S;
	pii() {}
	pii(int x, int y) {F = x, S = y;}
	bool operator < (const pii &x) const {return F != x.F ? F < x.F : S < x.S;}
};
pii MP(int x, int y) {return pii(x, y);}

const int N = 2e5 + 5;
int n, k;
ll a[N], b[N];
set <pii> st;
ll addd[N];

bool chk(ll V) {
	st.clear();
	rep(i, n) if ((a[i] + b[i]) / b[i] < k) st.insert(MP((a[i] + b[i]) / b[i], i));
	memset(addd, 0, sizeof addd);
	rep(t, k) {
		if (st.empty()) return 1;
		pii p = *st.begin(); st.erase(st.begin());
		int i = p.S;
		int tt = p.F;
		if (tt <= t) return 0;
		addd[i] += V;
		ll ntt = (a[i] + addd[i] + b[i]) / b[i];
		if (ntt < k) st.insert(MP(ntt, i));
	}
	return 1;
}

int main() {
	n = read(), k = read();
	rep(i, n) a[i] = read();
	rep(i, n) b[i] = read();
//	mt19937_64 rnd(200);
//	n = k = 2e5;
//	rep(i, n) a[i] = rnd() % (ll)(1e12) + 1;
//	rep(i, n) b[i] = rnd() % (ll)(1e5) + 1;
	ll lb = 0, rb = 2e12;
	while (lb < rb) {
		ll md = (lb + rb) >> 1;
//		printf("		%lld\n", md);
		if (chk(md)) rb = md;
		else lb = md + 1;
	}
	if (lb == 2e12) lb = -1;
	printf("%lld\n", lb);
	return 0;
}
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
int X1, Y1, X2, Y2;
int n;
char s[N];

pair <ll, ll> cal(ll stp) {
	pair <ll, ll> d;
	rep(i, n) {
		if (s[i] == 'U') d.S ++;
		if (s[i] == 'D') d.S --;
		if (s[i] == 'L') d.F --;
		if (s[i] == 'R') d.F ++;
	}
	d.F *= stp / n;
	d.S *= stp / n;
	pair <ll, ll> p;
	p.F = X1;
	p.S = Y1;
	rep(i, stp % n) {
		if (s[i] == 'U') d.S ++;
		if (s[i] == 'D') d.S --;
		if (s[i] == 'L') d.F --;
		if (s[i] == 'R') d.F ++;
	}
	p.F += d.F;
	p.S += d.S;
	return p;
}

int main() {
	X1 = read(), Y1 = read();
	X2 = read(), Y2 = read();
	n = read();
	rep(i, n) s[i] = getchar();
	ll lb = 1, rb = 1e18;
	while (lb < rb) {
		ll md = (lb + rb) >> 1;
		pair <ll, ll> p = cal(md);
//		printf("%lld (%lld, %lld)\n", md, p.F, p.S);
		if (abs(X2 - p.F) + abs(Y2 - p.S) > md) lb = md + 1;
		else rb = md;
	}
	printf("%lld\n", lb == 1e18 ? -1 : lb);
	return 0;
}
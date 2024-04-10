#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;
template <typename T>
void read(T &x) {
	x = 0; char c = getchar(); int f = 0;
	for (; !isdigit(c); c = getchar())
		f |= c == '-';
	for (; isdigit(c); c = getchar())
		x = x * 10 + (c ^ '0');
	if (f) x = -x;
}

template <typename T>
void write(T x, char ed = '\n') {
	if (x < 0) putchar('-'), x = -x;
	static short st[30], tp;
	do st[++tp] = x % 10, x /= 10; while (x);
	while (tp) putchar(st[tp--] | '0');
	putchar(ed);
}

#define fi first
#define se second
const int P = 1e9 + 7;
pair<int, int> p[2005];
ll f[2][2005], fac[200005], inv[200005], ans;
int n, m, k, s;
inline ll C(int n, int m) { return fac[n] * inv[m] % P * inv[n - m] % P; }
ll fpw(ll x, ll mi, ll res = 1) {
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res * x % P;
	return res;
}

int main() {
	read(n), read(m), read(k), read(s);
	for (int i = 1;i <= k; ++i) read(p[i].fi), read(p[i].se);
	sort(p + 1, p + k + 1), p[++k] = {n, m};
	inv[0] = inv[1] = fac[0] = fac[1] = 1;
	for (int i = 2;i <= 200000; ++i)
		inv[i] = (P - P / i) * inv[P % i] % P;
	for (int i = 2;i <= 200000; ++i)
		inv[i] = inv[i] * inv[i - 1] % P, fac[i] = fac[i - 1] * i % P;
	//for (int i = 1;i <= 20; ++i)
		//printf ("fac[%d] = %lld, inv[%d] = %lld\n", i, fac[i], i, inv[i]);
	int nw = 0, pr = 1;
	f[0][0] = 1, p[0] = {1, 1};
	for (; s > 1; s = (s + 1) >> 1) {
		swap(nw, pr);
		for (int i = 1;i <= k; ++i) 
			for (int j = 0;j < i; ++j) if (p[j].se <= p[i].se)
				f[nw][i] = (f[nw][i] + C(p[i].se - p[j].se + p[i].fi - p[j].fi, p[i].se - p[j].se) * (f[pr][j] - f[nw][j])) % P;
		ans = (ans + f[nw][k] * (s - 1)) % P;
		memset(f[pr], 0, sizeof(f[pr]));
	}
	//printf ("ans = %lld\n", ans);
	write((inv[n + m - 2] * fac[n - 1] % P * fac[m - 1] % P * ans % P + P + 1) % P);
	return 0;
}
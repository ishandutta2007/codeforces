#include <iostream>
#include <cstring>
#include <cstdio>
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

const int P = 31607;
ll fpw(ll x, ll mi, ll res = 1) {
	for (; mi; mi >>= 1, x = x * x % P)
		if (mi & 1) res = res * x % P;
	return res;
}

const int N = 22, M = (1 << 21) + 5;
const int inv = fpw(10000, P - 2);
int lg[M], siz[M], p[N][N], lim, n;
ll mul[N], f[N][M];
int main() {
	read(n), lim = 1 << n;
	for (int i = 1;i <= n; ++i) mul[i] = 1;
	for (int i = 1;i <= n; ++i) 
		for (int j = 1;j <= n; ++j) 
			read(p[i][j]), p[i][j] = p[i][j] * inv % P, mul[j] = mul[j] * p[i][j] % P;
	for (int i = 2;i < lim; ++i) lg[i] = lg[i >> 1] + 1;
	for (int i = 1;i <= n; ++i) {
		f[i][0] = 1;
		for (int j = 1;j < lim; ++j) 
			f[i][j] = f[i][j ^ (j & -j)] * p[i][lg[j & -j] + 1] % P;
		//for (int j = 1;j < lim; ++j)
			//printf ("f[%d][%d] = %lld\n", i, j, f[i][j]);
	}
	//printf ("fpw(%d, %d) = %lld\n", 16, 9, fpw(16, P - 2, 1));
	ll ans = 0;
	for (int i = 0;i < lim; ++i) {
		ll val1 = 1;
		for (int j = 1;j <= n; ++j)
			if (i >> (j - 1) & 1) val1 = val1 * mul[j] % P;
		ll val2 = val1, val3 = val1, val4 = val1;
		 for (int j = 1;j <= n; ++j) {
			 int s = (lim - 1) ^ i, ts = s;
			 val1 = val1 * (1 - f[j][s]) % P;
			 if (!(i >> (n - j) & 1)) s = s ^ (1 << (n - j)), val2 = val2 * p[j][n - j + 1] % P, val4 = val4 * p[j][n - j + 1] % P;
			 val2 = val2 * (1 - f[j][s]) % P;
			 if (!(i >> (j - 1) & 1)) {
				 if (j != n - j + 1) {
					 s = s ^ (1 << (j - 1));
					 val4 = val4 * p[j][j] % P;
				 }
				 val3 = val3 * (1 - f[j][ts ^ (1 << (j - 1))]) % P, val3 = val3 * p[j][j] % P;
			 }
			 else val3 = val3 * (1 - f[j][ts]) % P;
			 val4 = val4 * (1 - f[j][s]) % P;
		 //printf ("val = [%lld, %lld, %lld, %lld]\n", val1, val2, val3, val4);
		 }
		 siz[i] = siz[i >> 1] + (i & 1);
		 if (siz[i] & 1) ans += -val1 + val2 + val3 - val4;
		 else ans -= -val1 + val2 + val3 - val4;
		 //printf ("val = [%lld, %lld, %lld, %lld]\n", val1, val2, val3, val4);
	}
	write((1 - ans % P + P) % P);
	return 0;
}
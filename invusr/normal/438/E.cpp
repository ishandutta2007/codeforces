#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 100005;
const int MaxTN = 262147;
const int M = 998244353;
const int FFT_G = 3;
const int I2 = M + 1 >> 1;

inline int modpow(int a, const int &n)
{
	int res = 1;
	for (int i = n; i; i >>= 1)
	{
		if (i & 1)
			res = (s64)res * a % M;
		a = (s64)a * a % M;
	}
	return res;
}

inline int add(int a, const int &b)
{
	a += b;
	return a >= M ? a - M : a;
}
inline int dec(int a, const int &b)
{
	a -= b;
	return a < 0 ? a + M : a;
}

int tn, tl, inv;
int bitRev[MaxTN];
int root[MaxTN];

inline void fft_init(int n)
{
	tn = 1, tl = 0;
	while (tn < n)
		tn <<= 1, ++tl;
	inv = modpow(tn, M - 2);

	for (int i = 1; i < tn; ++i)
	{
		int l = bitRev[i >> 1] >> 1;
		bitRev[i] = l | ((i & 1) << tl - 1);
	}

	int bn = tn >> 1;
	root[bn + 0] = 1;
	root[bn + 1] = modpow(FFT_G, (M - 1) / tn);
	for (int i = 2; i < bn; ++i)
		root[bn + i] = (s64)root[bn + i - 1] * root[bn + 1] % M;
	for (int i = bn - 1; i > 0; --i)
		root[i] = root[i << 1];
}

inline void fft(int *a, int type)
{
	if (type)
		reverse(a + 1, a + tn);

	for (int i = 0; i < tn; ++i)
	{
		int r = bitRev[i];
		if (i < r)
			swap(a[i], a[r]);
	}

	for (int k = 1; k < tn; k <<= 1)
	{
		int *g = root + k;
		for (int s = 0; s < tn; s += k << 1)
		{
			int *w = g;
			for (int i = s; i < s + k; ++i, ++w)
			{
				int o = a[i], e = (s64)a[i + k] * *w % M;
				a[i] = add(o, e);
				a[i + k] = dec(o, e);
			}
		}
	}

	if (type == 1)
	{
		for (int i = 0; i < tn; ++i)
			a[i] = (s64)a[i] * inv % M;
	}
}

inline void polymul(int *a, int *b, int *c)
{
	fft(a, 0);
	fft(b, 0);
	for (int i = 0; i < tn; ++i)
		c[i] = (s64)a[i] * b[i] % M;
	fft(c, 1);
}

inline void polymulc(int *a, int n, int c)
{
	for (int i = 0; i < n; ++i)
		a[i] = (s64)a[i] * c % M;
}

void polyinv(int *a, int n, int *b)
{
	if (n == 1)
	{
		b[0] = modpow(a[0], M - 2);
		return;
	}

	int m = n + 1 >> 1;
	polyinv(a, m, b);

	fft_init(n * 2 - 1);

	static int da[MaxTN];
	static int db[MaxTN];
	for (int i = 0; i < n; ++i)
		da[i] = a[i], db[i] = b[i];
	for (int i = n; i < tn; ++i)
		da[i] = db[i] = 0;

	fft(da, 0);
	fft(db, 0);

	for (int i = 0; i < tn; ++i)
		b[i] = (s64)db[i] * (2 + M - (s64)da[i] * db[i] % M) % M;
	fft(b, 1);

	fill(b + n, b + n * 2, 0);
}

void polysqrt(int *a, int n, int *b)
{
	if (n == 1)
	{
		b[0] = 1;
		return;
	}

	int m = n + 1 >> 1;
	polysqrt(a, m, b);

	static int dc[MaxTN];
	polyinv(b, n, dc);

	static int da[MaxTN];
	static int db[MaxTN];
	for (int i = 0; i < n; ++i)
		da[i] = a[i];
	for (int i = n; i < tn; ++i)
		da[i] = dc[i] = 0;

	polymul(da, dc, db);

	for (int i = 0; i < n; ++i)
		b[i] = (s64)I2 * (b[i] + db[i]) % M;
	fill(b + n, b + n * 2, 0);
}

int n, m;
int c[MaxTN], a[MaxTN];
int f[MaxTN];

int main()
{
	cin >> n >> m;

	c[0] = 1;
	for (int i = 0; i < n; ++i)
	{
		int v = getint();
		if (v <= m)
			c[v] = (c[v] + M - 4) % M;
	}

	polysqrt(c, m + 1, a);
	a[0] = (a[0] + 1) % M;
	polyinv(a, m + 1, f);
	polymulc(f, m + 1, 2);

	for (int i = 1; i <= m; ++i)
		printf("%d\n", f[i]);
//
	return 0;
}
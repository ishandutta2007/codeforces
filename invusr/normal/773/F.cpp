#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;
typedef double r32;

const int MaxN = 30005;
const int MaxTN = 65537;
const r32 PI = acos(-1.0);

struct complex
{
	r32 r, i;
	complex() {}
	complex(const r32 &_r, const r32 &_i)
		: r(_r), i(_i) {}

	friend inline complex operator+(const complex &lhs, const complex &rhs)
	{
		return complex(lhs.r + rhs.r, lhs.i + rhs.i);
	}
	friend inline complex operator-(const complex &lhs, const complex &rhs)
	{
		return complex(lhs.r - rhs.r, lhs.i - rhs.i);
	}
	friend inline complex operator*(const complex &lhs, const complex &rhs)
	{
		complex res;
		res.r = lhs.r * rhs.r - lhs.i * rhs.i;
		res.i = lhs.r * rhs.i + lhs.i * rhs.r;
		return res;
	}
};

int n, r, m;

int tn, tl;
int bitRev[MaxTN];
complex root[MaxTN];

inline void fft_init(int n)
{
	tn = 1, tl = 0;
	while (tn < n)
		tn <<= 1, ++tl;

	for (int i = 1; i < tn; ++i)
	{
		int l = bitRev[i >> 1] >> 1;
		int r = (i & 1) << tl - 1;
		bitRev[i] = l | r;
	}

	int bn = tn >> 1;
	for (int i = 0; i < bn; ++i)
		root[bn + i] = complex(cos(2 * PI / tn * i), sin(2 * PI / tn * i));
	for (int i = bn - 1; i > 0; --i)
		root[i] = root[i << 1];
}

inline void fft(complex *a, int type)
{
	if (type == 1)
		reverse(a + 1, a + tn);

	for (int i = 0; i < tn; ++i)
	{
		int r = bitRev[i];
		if (i < r)
			swap(a[i], a[r]);
	}

	for (int k = 1; k < tn; k <<= 1)
	{
		complex *g = root + k;
		for (int s = 0; s < tn; s += k << 1)
		{
			complex *w = g;
			for (int i = s; i < s + k; ++i, ++w)
			{
				complex e = *w * a[i + k];
				a[i + k] = a[i] - e;
				a[i] = a[i] + e;
			}
		}
	}
}

int f[MaxN][2];
int outcome = 0;

void solve(int k)
{
	if (k == 0)
	{
		f[0][0] = 1;
		return;
	}

	int l = k / 2;
	int b = l & 1;
	solve(l);

	static complex da[MaxTN];
	static complex db[MaxTN];
	static complex dc[MaxTN];
	for (int i = n + 1; i < tn; ++i)
		da[i] = db[i] = dc[i] = complex(0, 0);
	for (int i = 0; i <= n; ++i)
	{
		da[i] = complex(f[i][0] + f[i][1], 0);
		db[i] = complex(f[i][b ^ 0], 0);
		dc[i] = complex(f[i][b ^ 1], 0);
	}

	fft(da, 0);
	fft(db, 0);
	fft(dc, 0);
	for (int i = 0; i < tn; ++i)
		db[i] = db[i] * da[i], dc[i] = dc[i] * da[i];
	fft(db, 1);
	fft(dc, 1);

	for (int i = n; i >= 0; --i)
	{
		int u = ((s64)(db[i].r / tn + 0.5) + f[i][0]) % m;
		int v = ((s64)(dc[i].r / tn + 0.5) + f[i][1]) % m;
		u = (u + m - (s64)(f[i][0] + f[i][1]) * f[0][b ^ 0] % m) % m;
		v = (v + m - (s64)(f[i][0] + f[i][1]) * f[0][b ^ 1] % m) % m;
		f[i][0] = u, f[i][1] = v;
	}

	if (k & 1)
	{
		for (int i = n; i > 0; --i)
		{
			f[i][1] += f[i - 1][0] + f[i - 1][1];
			f[i][1] %= m;
		}
	}

	for (int i = 1; i <= n; i += 2)
		outcome = (outcome + f[i][1]) % m;
}

int main()
{
	cin >> n >> r >> m;

	fft_init(2 * n + 1);
	solve(r / 2);

	cout << outcome << endl;

	return 0;
}
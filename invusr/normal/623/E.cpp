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
const int M = 1000000007;
const r32 PI = acos(-1.0);

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

struct complex
{
	r32 r, i;
	complex() {}
	complex(const r32 &_r, const r32 &_i)
		: r(_r), i(_i) {}

	inline complex conj() const
	{
		return complex(r, -i);
	}

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
				complex o = a[i], e = *w * a[i + k];
				a[i] = o + e;
				a[i + k] = o - e;
			}
		}
	}
}

inline void polycopy(complex *da, int *a, int n)
{
	for (int i = 0; i <= n; ++i)
		da[i] = complex(a[i] & 32767, a[i] >> 15);
	for (int i = n + 1; i < tn; ++i)
		da[i] = complex(0, 0);
}

inline void polymul(int *a, int *b, int *c, int n)
{
	static complex da[MaxTN];
	static complex db[MaxTN];
	polycopy(da, a, n);
	polycopy(db, b, n);

	fft(da, 0);
	fft(db, 0);

	static complex dc[MaxTN];
	static complex dd[MaxTN];
	for (int i = 0; i < tn; ++i)
	{
		int j = (tn - i) & (tn - 1);
		complex ta = (da[i] + da[j].conj()) * complex(0.5, 0);
		complex tb = (da[i] - da[j].conj()) * complex(0, -0.5);
		complex tc = (db[i] + db[j].conj()) * complex(0.5, 0);
		complex td = (db[i] - db[j].conj()) * complex(0, -0.5);
		dc[i] = ta * tc + ta * td * complex(0, 1);
		dd[i] = tb * tc + tb * td * complex(0, 1);
	}

	fft(dc, 1);
	fft(dd, 1);

	for (int i = 0; i <= n; ++i)
	{
		int ta = (s64)(dc[i].r / tn + 0.5) % M;
		int tb = (s64)(dc[i].i / tn + 0.5) % M;
		int tc = (s64)(dd[i].r / tn + 0.5) % M;
		int td = (s64)(dd[i].i / tn + 0.5) % M;
		c[i] = (ta + ((s64)(tb + tc) << 15) + ((s64)td << 30)) % M;
		c[i] = (c[i] + M) % M;
	}
}

s64 n;
int k;

int fact[MaxN], rfact[MaxN];
int pow2[MaxN];

struct dp_info
{
	int l, f[MaxN];

	inline void operator+=(const dp_info &rhs)
	{
		static int a[MaxN];
		static int b[MaxN];

		int now = 1;
		for (int i = 0; i <= k; ++i)
		{
			a[i] = (s64)rfact[i] * rhs.f[i] % M;
			b[i] = (s64)rfact[i] * f[i] % M * now % M;
			now = (s64)now * pow2[rhs.l] % M;
		}

		polymul(a, b, f, k);

		l += rhs.l;
		for (int i = 0; i < l; ++i)
			f[i] = 0;
		for (int i = l; i <= k; ++i)
			f[i] = (s64)f[i] * fact[i] % M;
	}
};
dp_info res, cur;

inline int solve()
{
	if (n > k)
		return 0;

	pow2[0] = fact[0] = 1;
	for (int i = 1; i <= k; ++i)
		pow2[i] = pow2[i - 1] * 2 % M;
	for (int i = 1; i <= k; ++i)
		fact[i] = (s64)fact[i - 1] * i % M;
	rfact[k] = modpow(fact[k], M - 2);
	for (int i = k; i >= 1; --i)
		rfact[i - 1] = (s64)rfact[i] * i % M;

	res.f[0] = cur.l = 1;
	for (int i = 1; i <= k; ++i)
		cur.f[i] = 1;

	fft_init(k * 2 + 1);

	for (int i = n; i; i >>= 1)
	{
		if (i & 1)
			res += cur;
		cur += cur;
	}

	int ans = 0;
	for (int i = n; i <= k; ++i)
	{
		int bin = (s64)fact[k] * rfact[i] % M * rfact[k - i] % M;
		ans = (ans + (s64)bin * res.f[i]) % M;
	}
	return ans;
}

int main()
{
	cin >> n >> k;
	cout << solve() << endl;

	return 0;
}
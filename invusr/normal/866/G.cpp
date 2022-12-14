#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

using s64 = long long;

const int M = 1000000007;
const int MaxN = 10;
const int MaxM = 100;
const int N = 250;

struct polynomial
{
	int n;
	int a[N * 2 + 1];

	polynomial() {}
	polynomial(const int &_n)
		: n(_n)
	{
	//	fill(a, a + _n + 1, 0);
		for (int i = 0; i <= N * 2; ++i)
			a[i] = 0;
	}

	friend inline polynomial operator*(const polynomial &lhs, const polynomial &rhs)
	{
		int l = lhs.n, r = rhs.n;
		int n = l + r;

		polynomial res(n);
	//	for (int i = 0; i <= n; ++i)
	//		res.a[i] = 0;
		for (int i = 0; i <= l; ++i)
			for (int j = 0; j <= r; ++j)
			{
				int k = i + j;
				int d = (s64)lhs.a[i] * rhs.a[j] % M;
				res.a[k] = (res.a[k] + d) % M;
			}

		return res;
	}

	friend inline polynomial operator%(const polynomial &lhs, const polynomial &rhs)
	{
		polynomial res = lhs;
		for (int i = lhs.n; i >= rhs.n; --i)
			for (int j = rhs.n; j >= 0; --j)
			{
				int k = i - j;
				int d = (s64)res.a[i] * rhs.a[rhs.n - j] % M;
				res.a[k] = (res.a[k] + d) % M;
			}

		res.n = rhs.n - 1;
		while (res.n && !res.a[res.n])
			--res.n;
		for (int i = rhs.n; i <= lhs.n; ++i)
			res.a[i] = 0;

		return res;
	}
};
polynomial f, mod, o;

int n, m;
s64 p;
int a[MaxN], b[MaxM];

inline polynomial polymodpow(polynomial a, const s64 &n, const polynomial &mod)
{
	polynomial res(0);
	res.a[0] = 1;

	for (s64 i = n; i; i >>= 1)
	{
		if (i & 1)
			res = res * a % mod;
		a = a * a % mod;
	}

	return res;
}

int main()
{
	cin >> n >> m >> p;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int i = 0; i < m; ++i)
		cin >> b[i];

	mod.n = N;
	mod.a[N] = M - 1;
	for (int i = 0; i < m; ++i)
		++mod.a[N - b[i]];

	o.a[o.n = 1] = 1;

	f.n = N - 1;
	for (int i = 0; i < n; ++i)
	{
		polynomial p = polymodpow(o, a[i], mod);
		for (int k = 0; k < N; ++k)
			f.a[k] = (f.a[k] + p.a[k]) % M;
	}

	f = polymodpow(f, p, mod);

	for (int i = N - 1; i > 0; --i)
		for (int j = 0; j < m; ++j)
		{
			int k = i - b[j];
			if (k >= 0)
				f.a[k] = (f.a[k] + f.a[i]) % M;
		}

	cout << f.a[0] << endl;


	return 0;
}
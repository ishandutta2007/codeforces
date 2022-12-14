#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;
typedef long double r64;

const s64 M = 10000000000ll;

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

inline s64 modmul(s64 a, s64 b)
{
	static int L = 100000000;
	int a1 = a / L, a2 = a % L;
	int b1 = b / L, b2 = b % L;
	s64 a3 = a - a2, b3 = b - b2;
	return ((s64)a2 * b2 % M + (s64)a3 * b2 % M + (s64)a2 * b3 % M) % M;
}

struct number
{
	s64 u;
	r64 v;

	number() {}
	number(const s64 &x)
		: u(x % M), v(x) {}

	inline void out()
	{
		if (v >= (r64)M)
			printf("...%010I64d\n", u);
		else
			printf("%I64d\n", u);
	}

	friend inline number operator+(const number &lhs, const number &rhs)
	{
		number res;
		res.u = (lhs.u + rhs.u) % M;
		res.v = lhs.v + rhs.v;
		return res;
	}
	friend inline number operator-(const number &lhs, const number &rhs)
	{
		number res;
		res.u = (lhs.u + M - rhs.u) % M;
		res.v = lhs.v - rhs.v;
		return res;
	}
	friend inline number operator*(const number &lhs, const number &rhs)
	{
		number res;
		res.u = modmul(lhs.u, rhs.u);
		res.v = lhs.v * rhs.v;
		return res;
	}
	friend inline number operator*(const number &lhs, const int &rhs)
	{
		number res;
		res.u = modmul(lhs.u, rhs);
		res.v = lhs.v * rhs;
		return res;
	}
};

inline number get_sum(s64 n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n % 2)
		return number((n + 1) / 2) * number(n);
	else
		return number(n / 2) * number(n + 1);
}
inline number get_square_sum(s64 n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else if (n == 2)
		return 5;

	number a = n;
	number b = n + 1;
	number c = n + n + 1;
	if (n % 2 == 0)
	{
		if (n % 3 == 0)
			return number(n / 6) * b * c;
		else if ((n + 1) % 3 == 0)
			return number(n / 2) * number((n + 1) / 3) * c;
		else if ((n + n + 1) % 3 == 0)
			return number(n / 2) * b * number((n + n + 1) / 3);
	}
	else if ((n + 1) % 2 == 0)
	{
		if (n % 3 == 0)
			return number(n / 3) * number((n + 1) / 2) * c;
		else if ((n + 1) % 3 == 0)
			return a * number((n + 1) / 6) * c;
		else if ((n + n + 1) % 3 == 0)
			return a * number((n + 1) / 2) * number((n + n + 1) / 3);
	}
}

inline number calc(int n, int m)
{
	if (n == 0 || m == 0)
		return 0;
	int t = min(n, m);

	number res = get_sum((s64)t * t);
	if (n < m)
	{
		number a = get_square_sum(n - 1);
		number b = get_square_sum(m - 1) - a;
		number c = get_sum(n) * (m - n);
		res = res + c + b * n;
	}
	else if (m < n)
	{
		number a = get_square_sum(m);
		number b = get_square_sum(n) - a;
		number c = get_sum(m - 1) * (n - m);
		res = res - c + b * m;
	}
	return res;
}

int main()
{
	int nT = getint();
	while (nT--)
	{
		int x1 = getint(), y1 = getint();
		int x2 = getint(), y2 = getint();
		number a = calc(x2, y2) + calc(x1 - 1, y1 - 1);
		number b = calc(x1 - 1, y2) + calc(x2, y1 - 1);
		(a - b).out();
	}

	return 0;
}
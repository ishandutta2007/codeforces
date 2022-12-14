#include <bits/stdc++.h>
using namespace std;

typedef unsigned u32;
typedef long long s64;
typedef unsigned long long u64;

typedef double r32;
typedef long double r64;

template <class T>
inline bool relax(T &a, const T &b)
{
	if (b > a)
	{
		a = b;
		return true;
	}
	return false;
}
template <class T>
inline bool tense(T &a, const T &b)
{
	if (b < a)
	{
		a = b;
		return true;
	}
	return false;
}

inline int getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	int res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int MaxN = 100000;
const int M = 1000000007;

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

int n, m;
int a[MaxN + 1], b[MaxN + 1];

int main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		a[i] = getint();
	for (int i = 1; i <= n; ++i)
		b[i] = getint();

	int d = modpow(m, M - 2);

	int x = (s64)m * (m - 1) / 2 % M;
	int y = (s64)m * m % M;
	int c = (s64)x * modpow(y, M - 2) % M;

	int eq = 1, res = 0;
	for (int i = 1; i <= n && eq; ++i)
	{
		if (a[i] == 0)
		{
			if (b[i] == 0)
			{
				res = (res + (s64)eq * c) % M;
				eq = (s64)eq * d % M;
			}
			else
			{
				res = (res + (s64)eq * d % M * (m - b[i])) % M;
				eq = (s64)eq * d % M;
			}
		}
		else
		{
			if (b[i] == 0)
			{
				res = (res + (s64)eq * d % M * (a[i] - 1)) % M;
				eq = (s64)eq * d % M;
			}
			else
			{
				res = (res + (s64)eq * (a[i] > b[i])) % M;
				eq = a[i] == b[i] ? eq : 0;
			}
		}
	}

	cout << res << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
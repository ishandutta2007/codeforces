#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
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

const int MaxN = 1000005;
const int M = 1000000007;

int n;
int a[MaxN];

int pri_n = 0, pri[MaxN / 8];
bool book[MaxN];
vector<int> fac[MaxN];

inline void init_sieve()
{
	for (int i = 2; i <= n; ++i)
	{
		if (!book[i])
		{
			pri[pri_n++] = i;
			fac[i].push_back(i);
		}

		for (int j = 0; j < pri_n; ++j)
		{
			int p = pri[j], d = i * p;
			if (d > n)
				break;
			book[d] = true;

			fac[d] = fac[i];
			if (i % p)
				fac[d].push_back(p);
			else
				break;
		}
	}

	fac[1].push_back(1);
}


inline int occur(int x)
{
	return x == 1 ? 1 : n / x;
}

inline int simplify(int x)
{
	int ret = 1;
	for (int i : fac[x])
		ret *= i;
	return ret;
}

inline bool add(int *equal, int a, int b)
{
	if (equal[a] && equal[a] != b)
		return false;
	equal[a] = b;
	return true;
}

inline int solve()
{
	static int equal_l[MaxN];
	static int equal_r[MaxN];
	for (int i = 1; i <= n; ++i)
	{
		if (a[i] == 0)
			continue;

		vector<int> &u = fac[i];
		vector<int> &v = fac[a[i]];
		if (u.size() != v.size())
			return 0;
		for (int j = 0; j < u.size(); ++j)
		{
			int a = u[j], b = v[j];
			if (occur(a) != occur(b))
				return 0;
			if (!add(equal_l, a, b))
				return 0;
			if (!add(equal_r, b, a))
				return 0;
		}
	}

	int res = 1;
	static int f[MaxN];
	static int g[MaxN];
	for (int i = 1; i <= n; ++i)
	{
		if (!book[i] && !equal_l[i])
			res = (s64)res * ++f[occur(i)] % M;
		if (!a[i])
			res = (s64)res * ++g[simplify(i)] % M;
	}

	return res;
}

int main()
{
	n = getint();
	for (int i = 1; i <= n; ++i)
		a[i] = getint();

	init_sieve();

	cout << solve();
	cout << endl;

	return 0;
}
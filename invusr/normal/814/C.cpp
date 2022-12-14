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

const int MaxN = 1505;

int n, q, m;
char s[MaxN], c[5], x;

int main()
{
	scanf("%d%s", &n, s + 1);
	scanf("%d", &q);

	while (q--)
	{
		scanf("%d%s", &m, c);
		x = c[0];

		int r = 0, now = 0, res = 0;
		for (int i = 1; i <= n; ++i)
		{
			while (r < n)
			{
				bool b = s[r + 1] != x;
				if (now + b > m)
					break;
				now += b, ++r;
			}
			res = max(res, r - i + 1);
			now -= s[i] != x;
		}
		printf("%d\n", res);
	}

	return 0;
}
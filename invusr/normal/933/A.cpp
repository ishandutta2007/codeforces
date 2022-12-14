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

const int MaxN = 2000;

int n;
int a[MaxN + 1];

int sum0[MaxN + 1][2];
int sum1[MaxN + 2][2];

int main()
{
//	freopen(".in", "r", stdin);
//	freopen(".out", "w", stdout);

	cin >> n;
	for (int i = 1; i <= n; ++i)
		cin >> a[i], --a[i];

	for (int i = 1; i <= n; ++i)
	{
		sum0[i][0] = sum0[i - 1][0];
		sum0[i][1] = sum0[i - 1][1];
		++sum0[i][a[i]];
	}

	for (int i = n; i; --i)
	{
		sum1[i][0] = sum1[i + 1][0];
		sum1[i][1] = sum1[i + 1][1];
		++sum1[i][a[i]];
	}

	int res = 0;
	for (int i = 0; i <= n; ++i)
		res = max(res, sum0[i][0] + sum1[i + 1][1]);

	for (int l = 1; l < n; ++l)
	{
		int best = 0;
		for (int r = l; r <= n; ++r)
		{
			if (a[r] == 1)
				best = max(best, sum0[r][1] - sum0[l - 1][1]);
			else
				++best;

			res = max(res, sum0[l - 1][0] + sum1[r + 1][1] + best);
		}
	}

	cout << res << endl;

	fclose(stdin);
	fclose(stdout);
	return 0;
}
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

const int MaxN = 300005;
const int NLet = 26;

char s[MaxN], t[MaxN], r[MaxN];
int n, nums[NLet], numt[NLet];

inline void input(char *s, int *num)
{
	scanf("%s", s);

	n = strlen(s);
	for (int i = 0; i < n; ++i)
		++num[s[i] - 'a'];
}

inline int get_max(int *num)
{
	for (int i = NLet - 1; i >= 0; --i)
		if (num[i] > 0)
			return i;
}
inline int get_min(int *num)
{
	for (int i = 0; i < NLet; ++i)
		if (num[i] > 0)
			return i;
}
inline void del_min(int *num, int k)
{
	for (int i = 0; k && (i < NLet); ++i)
	{
		if (num[i] <= k)
			k -= num[i], num[i] = 0;
		else
			num[i] -= k, k = 0;
	}
}
inline void del_max(int *num, int k)
{
	for (int i = NLet - 1; k && (i >= 0); --i)
	{
		if (num[i] <= k)
			k -= num[i], num[i] = 0;
		else
			num[i] -= k, k = 0;
	}
}

int main()
{
	input(s, nums);
	input(t, numt);

	int r0 = 0, r1 = 0;
	for (int i = 0; i < n; ++i)
		i & 1 ? ++r1 : ++r0;

	del_max(nums, n - r0);
	del_min(numt, n - r1);

	int hp = 0, tp = n - 1;
	for (int i = 0; i < n; ++i)
	{
		int u0 = get_min(nums), v0 = get_max(nums);
		int u1 = get_min(numt), v1 = get_max(numt);
		if (i & 1)
		{
			if (u0 >= v1)
				r[tp--] = u1 + 'a', --numt[u1];
			else
				r[hp++] = v1 + 'a', --numt[v1];
		}
		else
		{
			if (u0 >= v1)
				r[tp--] = v0 + 'a', --nums[v0];
			else
				r[hp++] = u0 + 'a', --nums[u0];
		}
	}

	puts(r);

	return 0;
}
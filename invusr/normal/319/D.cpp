#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

const int MaxN = 50005;
const int P1 = 27, M1 = 998244353;
const int P2 = 31, M2 = 1000000007;

int n;
char s[MaxN], t[MaxN];

int prev[MaxN];
int next[MaxN];

int pre1[MaxN], preh1[MaxN];
int pre2[MaxN], preh2[MaxN];

inline void build_hash()
{
	int m = 0;
	for (int i = next[0]; i <= n; i = next[i])
		t[++m] = s[i];
	copy(t, t + (n = m) + 1, s);
	s[n + 1] = '\0';

	preh1[0] = preh2[0] = 0;
	for (int i = 1; i <= n; ++i)
	{
		preh1[i] = ((s64)preh1[i - 1] * P1 + s[i]) % M1;
		preh2[i] = ((s64)preh2[i - 1] * P2 + s[i]) % M2;
	}

	for (int i = 0; i <= n; ++i)
		prev[i] = i - 1, next[i] = i + 1;
}

inline int get(int *pre, int *preh, int l, int r, int m)
{
	return ((preh[r] - (s64)preh[l - 1] * pre[r - l + 1]) % m + m) % m;
}

inline bool is_equal(int l1, int r1, int l2, int r2)
{
	int hl1 = get(pre1, preh1, l1, r1, M1);
	int hl2 = get(pre2, preh2, l1, r1, M2);
	int hr1 = get(pre1, preh1, l2, r2, M1);
	int hr2 = get(pre2, preh2, l2, r2, M2);
	return hl1 == hr1 && hl2 == hr2;
}

inline int get_lcp(int i, int j)
{
	int l = 1, r = n - max(i, j) + 1;
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (is_equal(i, i + mid - 1, j, j + mid - 1))
			l = mid + 1;
		else
			r = mid - 1;
	}
	return r;
}
inline int get_lcs(int i, int j)
{
	int l = 1, r = min(i, j);
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (is_equal(i - mid + 1, i, j - mid + 1, j))
			l = mid + 1;
		else
			r = mid - 1;
	}
	return r;
}

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);

	pre1[0] = pre2[0] = 1;
	for (int i = 1; i <= n; ++i)
	{
		pre1[i] = (s64)pre1[i - 1] * P1 % M1;
		pre2[i] = (s64)pre2[i - 1] * P2 % M2;
	}

	for (int i = 0; i <= n + 1; ++i)
		prev[i] = i - 1, next[i] = i + 1;

	build_hash();

	for (int l = 1; l + l <= n; ++l)
	{
		bool ok = false;
		for (int i = 1, j; !ok && (j = i + l) <= n; i += l)
		{
			int l = max(i, j - get_lcs(i, j));
			int r = min(j, i + get_lcp(i, j));
			ok = r > l;
		}
		if (!ok)
			continue;

		for (int i = l + l; i <= n; ++i)
		{
			int j = i - l;
			if (is_equal(i - l + 1, i, j - l + 1, j))
			{
				prev[i - l + 1] = prev[j - l + 1];
				next[prev[i - l + 1]] = i - l + 1;
				i += l - 1;
			}
		}

		build_hash();
	}

	printf("%s", s + 1);

	return 0;
}
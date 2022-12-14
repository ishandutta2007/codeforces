#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

typedef long long s64;

inline s64 getint()
{
	static char c;
	while ((c = getchar()) < '0' || c > '9');

	s64 res = c - '0';
	while ((c = getchar()) >= '0' && c <= '9')
		res = res * 10 + c - '0';
	return res;
}

const int L = 45;

int n;
int cnt[L + 1][2];

int extra[L + 1];
int final[L + 1];

inline bool check(int k)
{
	int now = k;
	for (int i = 0; i < L; ++i)
	{
		extra[i] = cnt[i][1] - now;
		int next = min(now, cnt[i + 1][1]);
		final[i] = now - next;
		now = next;
	}

	now = 0;
	for (int i = L - 1; i >= 0; --i)
	{
		now += final[i];
		now -= cnt[i][0] + extra[i + 1];
		if (now < 0)
			return false;
	}
	return now - extra[0] >= 0;
}

int main()
{
	n = getint();
	for (int i = 0; i < n; ++i)
	{
		s64 x = getint();
		int l = 63 - __builtin_clzll(x);
		++cnt[l][(x & (x - 1)) == 0];
	}

	int l = 1, r = cnt[0][1];
	while (l <= r)
	{
		int mid = l + r >> 1;
		if (check(mid))
			r = mid - 1;
		else
			l = mid + 1;
	}

	int vl = l, vr = cnt[0][1];
	if (vl > vr)
		vl = vr = -1;
	for (int i = vl; i <= vr; ++i)
		printf("%d ", i);

	return 0;
}
#include <bits/stdc++.h>
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

const int MaxN = 100005;

int n, a[MaxN];
s64 sum[MaxN];

inline bool check()
{
	if (sum[n] & 1)
		return false;

	for (int i = 1; i <= n; ++i)
	{
		s64 tar1 = sum[n] / 2 - a[i];
		s64 tar2 = sum[n] / 2 + a[i];
		int u = lower_bound(sum + 0, sum + i + 0, tar1) - sum;
		int v = lower_bound(sum + i, sum + n + 1, tar2) - sum;
		if (u < i && sum[u] == tar1)
			return true;
		if (v <= n && sum[v] == tar2)
			return true;
	}
	return false;
}

int main()
{
	n = getint();
	for (int i = 1; i <= n; ++i)
		sum[i] = sum[i - 1] + (a[i] = getint());

	puts(check() ? "YES" : "NO");

	return 0;
}
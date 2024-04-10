#include <bits/stdc++.h>
using namespace std;

typedef long long s64;
typedef double r32;

const int MaxN = 200005;

int n, k;
int a[MaxN];

int main()
{
	ios::sync_with_stdio(false);

	cin >> n >> k;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];

	s64 cur = 0, sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		cur += a[i];
		if (i >= k)
			cur -= a[i - k], sum += cur;
	}

	r32 res = (r32)sum / (n - k + 1);
	printf("%.16f\n", res);

	return 0;
}
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std;

const int MaxN = 100005;
const int MaxM = 100005;

int n, m;
char a[MaxN], b[MaxN];
bool del[MaxN];

int main()
{
	scanf("%d", &m);
	scanf("%s", a + 1);
	n = strlen(a + 1);

	for (int i = 1; i <= n; ++i)
		b[i] = a[i];
	sort(b + 1, b + n + 1);

	int total = 0, res = 0;
	for (char c = 'z'; c >= 'a'; --c)
	{
		int cnt = 0, chosen = 0;
		for (int i = 1; i <= n; ++i)
			if (a[i] == c)
				del[i] = true, ++cnt;

		bool ok = true;
		for (int i = 1, l = 0; ok && i <= n + 1; ++i)
		{
			if (del[i])
				continue;
			ok = i - l <= m;
			for (int j = l + 1, k = l, p = l, cur = 0; j <= i; ++j)
			{
				if (a[j] != c && j != i)
					continue;
				if (j - p > m && k - p <= m)
				{
					if (k == p)
					{
						ok = false;
						break;
					}
					++chosen, p = k;
					if (i - k <= m)
						ok = true;
				}
				k = j;
			}
			l = i;
		}
		if (!ok)
			break;

		total += cnt;
		if (chosen != 0)
		{
			res = total - chosen;
			break;
		}
	}

	for (int i = 1; i <= n - res; ++i)
		putchar(b[i]);

	return 0;
}
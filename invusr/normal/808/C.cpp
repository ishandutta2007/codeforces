#include <bits/stdc++.h>
using namespace std;

const int MaxN = 105;

int n, total;
int cap[MaxN], idx[MaxN];
int res[MaxN];

inline bool comparator(int i, int j)
{
	return cap[i] < cap[j];
}

int main()
{
	cin >> n >> total;
	for (int i = 1; i <= n; ++i)
		cin >> cap[idx[i] = i];

	sort(idx + 1, idx + n + 1, comparator);

	for (int i = 1; i <= n; ++i)
	{
		int v = idx[i];
		total -= (res[v] = cap[v] + 1 >> 1);
	}

	for (int i = n; total > 0; --i)
	{
		int v = idx[i];
		int k = cap[v] - res[v];
		if (total >= k)
			total -= k, res[v] = cap[v];
		else
		{
			res[v] += total, total = 0;
			break;
		}
	}

	if (total < 0)
		puts("-1");
	else
	{
		for (int i = 1; i <= n; ++i)
			printf("%d ", res[i]);
	}

	return 0;
}
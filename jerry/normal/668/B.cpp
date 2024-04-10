#include <bits/stdc++.h>
using namespace std;

int n, q, loc[3], di[2];
int arr[1000005];

int twocase()
{
	for (int i = 0;i < q;i++)
	{
		int typ; scanf("%d", &typ);
		if (typ == 1)
		{
			int d; scanf("%d", &d);
			for (int j = 0;j < 2;j++)
			{
				loc[j] += d;
				loc[j] += n;
				loc[j] %= n;
			}
		} else
		{
			for (int j = 0;j < 2;j++)
				loc[j] ^= 1;
		}
	}
	for (int i = 0;i < 2;i++)
		printf("%d ", loc[i]+1);
	printf("\n");
	return 0;
}

int main()
{
	scanf("%d%d", &n, &q);
	loc[0] = 0, loc[1] = 1, loc[2] = 2;
	if (n == 2)
		return twocase();
	for (int i = 0;i < q;i++)
	{
		int typ; scanf("%d", &typ);
		if (typ == 1)
		{
			int d; scanf("%d", &d);
			for (int j = 0;j < 3;j++)
			{
				loc[j] += d;
				loc[j] += n;
				loc[j] %= n;
			}
		} else
		{
			for (int j = 0;j < 3;j++)
				loc[j] ^= 1;
		}
	}
	di[0] = loc[1] - loc[0] + n; di[0] %= n;
	di[1] = loc[2] - loc[1] + n; di[1] %= n;
	arr[loc[0]] = 0; int at = loc[0];
	for (int i = 1;i < n;i++)
	{
		at += di[(i-1)&1];
		at %= n;
		arr[at] = i;
	}
	for (int i = 0;i < n;i++)
		printf("%d ", arr[i]+1);
	printf("\n");
	return 0;
}
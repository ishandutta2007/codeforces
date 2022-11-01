#include <bits/stdc++.h>
using namespace std;

int arr[300005];
int x[300005];
int n, m;

bool check(int a)
{
	for (int i = 0;i+a <= n;i++)
	{
		int hv = arr[i+a] - arr[i];
		if (hv <= m) return true;
	}
	return false;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1;i <= n;i++) scanf("%d", x+i);
	for (int i = 1;i <= n;i++) arr[i] = arr[i-1] + 1 - x[i];
	int lo = 0, hi = n+1;
	while (lo+1 < hi)
	{
		int mid = (lo+hi) >> 1;
		if (check(mid))
			lo = mid;
		else
			hi = mid;
	}
	printf("%d\n", lo);
	int a = lo;
	for (int i = 0;i+a <= n;i++)
	{
		int hv = arr[i+a] - arr[i];
		if (hv <= m)
		{
			for (int j = i+1;j <= i+a;j++)
				x[j] = 1;
			for (int j = 1;j <= n;j++) printf("%d ", x[j]);
			printf("\n");
			return 0;
		}
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;

int arr[1005][1005];

void slv(int n)
{
	for (int i = 0;i < n;i++) for (int j = 1;j <= n/2;j++) arr[i][(i+j)%n] = 1;
}

int main()
{
	int n;
	scanf("%d", &n);
	if (n == 4)
	{
		printf("-1\n");
		return 0;
	}
	if (n&1) slv(n);
	else
	{
		slv(n-1);
		for (int i = 0;i < n-1;i++)
			if (i&1) arr[i][n-1] = 1;
			else arr[n-1][i] = 1;
	}
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++) printf("%d ", arr[i][j]);
		printf("\n");
	}
	return 0;
}
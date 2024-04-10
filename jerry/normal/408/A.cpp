#include <cstdio>

int k[100];
int ans(2147483647);
int n;
int m;

int main()
{
	scanf("%d", &n);
	for (int i = 0;i < n;i++)
		scanf("%d", k+i);
	for (int i = 0;i < n;i++)
	{
		int tmp = 0;
		for (int j = 0;j < k[i];j++)
		{
			scanf("%d", &m);
			tmp += (5*m+15);
		}
		if (tmp < ans) ans = tmp;
	}
	printf("%d\n", ans); return 0;
}
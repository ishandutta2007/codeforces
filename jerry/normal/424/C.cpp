#include <cstdio>

int xors[1000001];
int n;

int main()
{
	for (int i = 1;i < 1000001;i++)
	{
		if ((i % 4) == 1)
			xors[i] = 1;
		if ((i % 4) == 2)
			xors[i] = i + 1;
		if ((i % 4) == 3)
			xors[i] = 0;
		if ((i % 4) == 0)
			xors[i] = i;
	}
	scanf("%d", &n);
	int ans = 0;
	for (int i = 1;i <= n;i++)
	{
		int quot = n / i;
		int rem = n - i*quot;
		if (quot & 1)
			ans ^= xors[i-1];
		ans ^= xors[rem];
	}
	for (int i = 0;i < n;i++)
	{
		int temp;
		scanf("%d", &temp);
		ans ^= temp;
	}
	printf("%d\n", ans);
	return 0;
}
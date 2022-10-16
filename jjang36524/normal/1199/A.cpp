#include <stdio.h>
int N;
int a, b;
int arr[100100];
int main()
{
	scanf("%d%d%d", &N,&a,&b);
	int i,j;
	for (i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}
	for (i = 0; i < N; i++)
	{
		for (j = (i - a < 0) ? 0 : i - a; j <= ((i + b < N) ? i + b : N-1); j++)
		{
			if (arr[i] > arr[j])
				goto A;
		}
		printf("%d", i + 1);
		return 0;
	A:
		int d;
	}
}
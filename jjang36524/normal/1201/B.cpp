#include <stdio.h>
int N;
long long sum;
long long ma;
int main()
{
	scanf("%d", &N);
	int i;
	for (i = 0; i < N; i++)
	{
		int a;
		scanf("%d", &a);
		sum += a;
		ma = ma > a ? ma : a;
	}
	if (ma * 2 > sum || sum % 2)
		printf("NO");
	else
		printf("YES");
}
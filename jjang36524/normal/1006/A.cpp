#include <stdio.h>
int main()
{
	int N;
	scanf("%d", &N);
	while (N--)
	{
		int a;
		scanf("%d", &a);
		printf("%d ", a - (!(a % 2)));
	}
}
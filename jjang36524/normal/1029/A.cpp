#include <stdio.h>
#include <string.h>
int N, M;
char st[50];
int dist;
int main()
{
	scanf("%d%d", &N, &M);
	scanf("%s", st);
	int i;
	dist = N;
	for (i = 1; i < N; i++)
	{
		if (!strncmp(st, st + i, N - i))
		{
			dist = i;
			break;
		}
	}
	
	for (i = 1; i < M; i++)
	{
		int j;
		for (j = 0; j < dist; j++)
		{
			printf("%c", st[j]);
		}
	}
	printf("%s", st);
}
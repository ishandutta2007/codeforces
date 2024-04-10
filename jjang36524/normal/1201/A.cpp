#include <stdio.h>
int app[1001][128];
int ma[1001];
int main()
{
	int N, M;
	scanf("%d%d", &N, &M);
	int i, j;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < M; j++)
		{
			char a;
			scanf(" %c", &a);
			app[j][a]++;
		}
	}
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < 128; j++)
		{
			ma[i] = ma[i] > app[i][j] ? ma[i] : app[i][j];
		}
	}
	int ans = 0;
	for (i = 0; i < M; i++)
	{
		int a;
		scanf("%d", &a);
		ans += a * ma[i];
	}
	printf("%d", ans);
}
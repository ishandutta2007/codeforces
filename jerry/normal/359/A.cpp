#include <cstdio>

bool good[52][52];
int n;
int m;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0;i < n;i++) for (int j = 0;j < m;j++)
		scanf("%d", &good[i][j]);
	for (int i = 0;i < n;i++) if (good[i][0] || good[i][m-1])
	{
		printf("2\n");
		return 0;
	}
	for (int i = 0;i < m;i++) if (good[0][i] || good[n-1][i])
	{
		printf("2\n");
		return 0;
	}
	printf("4\n");
	return 0;
}
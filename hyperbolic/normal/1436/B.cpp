#include <stdio.h>

int x[110][110];
int check[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) for(int j=1;j<=a;j++) x[i][j] = 0;
		for(int i=1;i<=a;i++) x[i][i] = 1;
		for(int i=1;i<a;i++) x[i][i+1] = 1;
		x[a][1] = 1;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=a;j++) printf("%d ",x[i][j]);
			printf("\n");
		}
	}
}
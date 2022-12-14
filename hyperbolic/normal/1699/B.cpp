#include <stdio.h>

int ans[110][110],check[110][110];
int main()
{
	check[0][0] = 1, check[0][1] = 0, check[0][2] = 0, check[0][3] = 1;
	check[1][0] = 0, check[1][1] = 1, check[1][2] = 1, check[1][3] = 0;
	check[2][0] = 0, check[2][1] = 1, check[2][2] = 1, check[2][3] = 0;
	check[3][0] = 1, check[3][1] = 0, check[3][2] = 0, check[3][3] = 1;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<a;i++)
		{
			for(int j=0;j<b;j++) printf("%d ",check[i%4][j%4]);
			printf("\n");
		}
	}
}
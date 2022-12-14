#include <stdio.h>

int ans[1010][1010];
int main()
{
	for(int i=1;i<=500;i++) ans[i][1] = 1;
	for(int i=1;i<=500;i++) ans[i][i] = 1;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=i;j++) printf("%d ",ans[i][j]);
			printf("\n");
		}
	}
}
#include <stdio.h>

int ans[1010][1010];
int main()
{
	int a;
	scanf("%d",&a);
	
	for(int i=1;i<=40;i++)
	{
		ans[2*i+1][2*i+3] = ans[2*i+3][2*i+1] = 1;
		ans[2*i+1][2*i+4] = ans[2*i+4][2*i+1] = 1;
		ans[2*i+2][2*i+3] = ans[2*i+3][2*i+2] = 1;
		ans[2*i+2][2*i+4] = ans[2*i+4][2*i+2] = 1;
	}
	ans[1][3] = ans[3][1] = 1;
	ans[1][4] = ans[4][1] = 1;
	
	for(int i=85;i<125;i++) ans[i+1][i] = ans[i][i+1] = 1;
	ans[125][2] = ans[2][125] = 1;
	
	int p = 126;
	for(int i=30;i>=1;i--)
	{
		if(a>=(1<<i))
		{
			ans[2*i+1][p] = ans[p][2*i+1] = 1;
			ans[2*i+2][p] = ans[p][2*i+2] = 1;
			ans[p][86+i] = ans[86+i][p] = 1;
			p++;
			a -= (1<<i);
		}
	}
	if(a==1)
	{
		ans[1][85] = ans[85][1] = 1;
	}
	
	printf("%d\n",p-1);
	for(int i=1;i<p;i++)
	{
		for(int j=1;j<p;j++)
		{
			if(ans[i][j]==1) printf("Y");
			else printf("N");
		}
		printf("\n");
	}
}
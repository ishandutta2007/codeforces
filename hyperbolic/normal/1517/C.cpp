#include <stdio.h>

int ans[510][510];
int x[510];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%d",&x[i]);
	
	for(int i=0;i<=a+1;i++) ans[0][i] = ans[i][0] = ans[a+1][i] = ans[i][a+1] = -1;
	for(int i=1;i<=a;i++)
	{
		int c = x[i];
		int s = i, t = i;
		int type = 1;
		while(c--)
		{
			ans[s][t] = x[i];
			if(type==1)
			{
				if(ans[s][t-1]!=0)
				{
					type = 2;
					s++;
				}
				else t--;
			}
			else
			{
				if(ans[s][t-1]==0)
				{
					type = 1;
					t--;
				}
				else s++;
			}
		}
	}
	
	for(int i=1;i<=a;i++)
	{
		for(int j=1;j<=i;j++) printf("%d ",ans[i][j]);
		printf("\n");
	}
}
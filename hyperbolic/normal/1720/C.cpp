#include <stdio.h>

char x[510][510];
int direX[10]={0,1,1,1,0,-1,-1,-1}, direY[10] = {1,1,0,-1,-1,-1,0,1};
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		
		int sum = 0;
		for(int i=1;i<=a;i++) for(int j=1;j<=b;j++) sum += x[i][j]-'0';
		
		if(sum==0)
		{
			printf("0\n");
			continue;
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				for(int k=0;k<8;k++)
				{
					int s = i+direX[k];
					int t = j+direY[k];
					if(1<=s&&s<=a&&1<=t&&t<=b&&x[i][j]=='0'&&x[s][t]=='0')
					{
						printf("%d\n",sum);
						goto u;
					}
				}
			}
		}
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(x[i][j]=='0')
				{
					printf("%d\n",sum-1);
					goto u;
				}
			}
		}
		printf("%d\n",sum-2);
		u:;
	}
}
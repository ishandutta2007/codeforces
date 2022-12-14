#include <stdio.h>

char x[510][510];
int count[510][510];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%s",x[i]+1);
		
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				if(x[i][j]!='*')
				{
					count[i][j] = 0;
					continue;
				}
				
				count[i][j] = count[i][j-1]-1;
				if(count[i][j]<0) count[i][j] = 0;
				int control;
				for(int k=count[i][j]+1;;k++)
				{
					control = 0;
					for(int l=0;l<k;l++)
					{
						if(j-(k-1-l)<1) control = 1;
						else if(i-l<1) control = 1;
						else if(x[i-l][j-(k-1-l)]!='*') control = 1;
					}
					for(int l=0;l<k;l++)
					{
						if(j+(k-1-l)>b) control = 1;
						else if(i-l<1) control = 1;
						else if(x[i-l][j+(k-1-l)]!='*') control = 1;
					}
					if(control==1) break;
					else count[i][j]++;
				}
			}
		}
		
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			for(int j=1;j<=b;j++)
			{
				//printf("%d %d : %d!!\n",i,j,count[i][j]);
				ans += count[i][j];
			}
		}
		printf("%d\n",ans);
	}
}
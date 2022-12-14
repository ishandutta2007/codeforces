#include <stdio.h>
#include <string.h>

char x[200010];
int y[200010],z[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s",x+1);
		int a = strlen(x+1);
		y[0] = 0, z[a+1] = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]!='0') y[i] = y[i-1]+1;
			else y[i] = y[i-1];
		}
		for(int i=a;i>=1;i--)
		{
			if(x[i]!='1') z[i] = z[i+1]+1;
			else z[i] = z[i+1];
		}
		
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			if(y[i-1]==(i-1) && z[i+1]==(a-i))
			{
				ans++;
			}
		}
		printf("%d\n",ans);
	}
}
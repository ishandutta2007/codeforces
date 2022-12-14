#include <stdio.h>

char y[400010],x[110];
int last[400010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		scanf("%s",y+1);
		for(int i=1;i<=a;i++) y[i+a] = y[i];
		
		int p = 2*a+1;
		for(int i=2*a;i>=1;i--)
		{
			if(y[i]=='g') p = i;
			last[i] = p;
		}
		
		int ans = 0;
		for(int i=1;i<=a;i++)
		{
			if(y[i]==x[1])
			{
				int val = last[i]-i;
				ans = ans>val?ans:val;
			}
		}
		printf("%d\n",ans);
	}
}
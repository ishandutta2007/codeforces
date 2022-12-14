#include <stdio.h>

int y[200010];
char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		scanf("%s",x+1);
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='B') y[i] = 0;
			else y[i] = 1;
		}
		for(int i=1;i<=a;i++) y[i] += y[i-1];
		
		int ans = a;
		for(int i=1;i+b-1<=a;i++)
		{
			int val = y[i+b-1]-y[i-1];
			ans = ans<val?ans:val;
		}
		printf("%d\n",ans);
		for(int i=1;i<=a;i++) y[i] = 0;
	}
}
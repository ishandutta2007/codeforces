#include <stdio.h>

char x[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		x[a+1] = '.';
		int count0 = 0, count1 = 0;
		for(int i=1;i<=a;i++)
		{
			if(x[i]=='0') count0++;
			else count1++;
		}
		long long int ans = (long long int)count0 * count1;
		
		int p = 1;
		for(int i=2;i<=a+1;i++)
		{
			if(x[i]!=x[i-1])
			{
				long long int val = (i-1)-p+1;
				ans = ans>val*val?ans:val*val;
				p = i;
			}
		}
		printf("%lld\n",ans);
	}
}
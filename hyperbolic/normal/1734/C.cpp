#include <stdio.h>

char x[1000010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		
		long long int ans = 0;
		for(int i=1;i<=a;i++)
		{
			int start = i;
			while(start<=a&&x[start]=='2') start+=i;
			while(start<=a&&x[start]!='1')
			{
				if(x[start]=='0')
				{
					ans += i;
					x[start] = '2';
				}
				start+=i;
			}
		}
		printf("%lld\n",ans);
	}
}
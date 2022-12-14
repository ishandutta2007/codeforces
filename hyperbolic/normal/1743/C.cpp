#include <stdio.h>

char x[200010];
int y[200010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		scanf("%s",x+1);
		x[a+1] = '0';
		x[0] = '0';
		y[0] = 0;
		for(int i=1;i<=a;i++) scanf("%d",&y[i]);
		
		int min = 12345678;
		long long int ans = 0;
		int p = 1;
		while(p<=a)
		{
			if(x[p]=='1')
			{
				ans += y[p-1];
				min = min<y[p-1]?min:y[p-1];
				if(x[p+1]=='0')
				{
					ans += y[p];
					min = min<y[p]?min:y[p];
					ans -= min;
					min = 12345678;
				}
			}
			p++;
		}
		printf("%lld\n",ans);
	}
}
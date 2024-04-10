#include <stdio.h>
#include <algorithm>

long long int MAX = 1;
int x[300010],y[300010];
int main()
{
	for(int i=1;i<=17;i++) MAX*=10;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<=b;i++) scanf("%d",&y[i]);
		std::sort(x+1,x+a+1);
		int min = 1, max = a;
		int ans = a;
		while(min<=max)
		{
			int h = (min+max)/2;
			long long int sum = 0;
			for(int i=h;i<=a;i++)
			{
				if(x[i]<(i-h+1))
				{
					min = h+1;
					goto u;
				}
			}
			ans = h;
			max = h-1;
			u:;
		}
		
		long long int sum = 0;
		for(int i=1;i<ans;i++) sum += y[x[i]];
		for(int i=ans;i<=a;i++) sum += y[i-ans+1];
		long long int ANS = sum;
		for(int i=ans;i<=a;i++)
		{
			sum -= y[a-i+1];
			sum += y[x[i]];
			ANS = ANS<sum?ANS:sum;
		}
		printf("%lld\n",ANS);
	}
}
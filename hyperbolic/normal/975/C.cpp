#include <stdio.h>

long long int x[200010],y[200010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	for(int i=1;i<=a;i++) y[i] = x[i];
	for(int i=a;i>=1;i--) y[i] += y[i+1];
	long long int last = y[1];
	for(int i=1;i<=b;i++)
	{
		long long int c;
		scanf("%lld",&c);
		last -= c;
		if(last<=0)
		{
			printf("%d\n",a);
			last = y[1];
			continue;
		}
		
		int L = 1, R = a;
		int ans = 1;
		while(L<=R)
		{
			int h = (L+R)/2;
			if(last<=y[h])
			{
				ans = h;
				L = h+1;
			}
			else R = h-1;
		}
		printf("%d\n",(a-ans+1));
	}
}
#include <stdio.h>
#include <algorithm>

long long int MAX = 1;
int abs(int k)
{
	return k>0?k:-k;
}
int x[200010],y[200010];
int main()
{
	for(int i=1;i<=15;i++) MAX*=10;
	
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		for(int i=1;i<a;i++) y[i] = abs(x[i]-x[i+1]);
		long long int sum = 0;
		for(int i=1;i<a;i++) sum += y[i];
		
		long long int ans = MAX;
		for(int i=2;i<a;i++)
		{
			long long int k = sum - y[i] - y[i-1] + abs(x[i+1]-x[i-1]);
			ans = ans<k?ans:k;
		}
		long long int k = sum - y[1];
		ans = ans<k?ans:k;
		k = sum - y[a-1];
		ans = ans<k?ans:k;
		printf("%lld\n",ans);
	}
}
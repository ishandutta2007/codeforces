#include <stdio.h>
#include <algorithm>

int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int a;
		scanf("%d",&a);
		for(int i=1;i<=a;i++) scanf("%d",&x[i]);
		std::sort(x+1,x+a+1);
		long long int sum = (long long int)x[a]*(a-1);
		for(int i=1;i<=a;i++) sum -= x[i];
		if(sum<0)
		{
			sum %= (a-1);
			sum += (a-1);
			sum %= (a-1);
		}
		printf("%lld\n",sum);
	}
}
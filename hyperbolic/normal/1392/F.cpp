#include <stdio.h>

long long int x[1000010];
int main()
{
	int a;
	scanf("%d",&a);
	for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
	
	long long int sum = 0;
	for(int i=1;i<=a;i++) sum+=x[i];
	
	for(long long int L=1;L<=a;L++)
	{
		long long int C1 = (L-1)*L/2;
		long long int C2 = (L+a-3)*(a-L)/2;
		if((sum-C1-C2)%a==0)
		{
			long long int k = (sum-C1-C2)/a;
			for(int i=1;i<=L;i++) printf("%lld ",k+(i-1));
			for(int i=L+1;i<=a;i++) printf("%lld ",k+(i-2));
			return 0;
		}
	}
}
#include <stdio.h>
long long sum;
int main()
{
	int N;
	scanf("%d",&N);
	while(N--)
	{
		long long a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		sum=a+b+c;
		printf("%lld\n",sum/2);
	}
}
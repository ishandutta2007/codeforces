#include <stdio.h>
#define MAX (long long int)1e16

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		
		long long int start = (b/4)*4;
		b%=4;
		for(int i=1;i<=b;i++)
		{
			if((a+MAX)%2==0) a -= (start+i);
			else a += (start+i);
		}
		
		printf("%lld\n",a);
	}
}
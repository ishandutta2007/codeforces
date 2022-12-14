#include <stdio.h>

long long int x[100010];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		for(int i=1;i<=a;i++) scanf("%lld",&x[i]);
		
		long long int sum = 0;
		for(int i=1;i<=a;i++) sum += x[i];
		sum%=2;
		
		if((b+c+sum)%2==0) printf("Alice\n");
		else printf("Bob\n");
	}
}
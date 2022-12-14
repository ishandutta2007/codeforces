#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b;
		scanf("%lld%lld",&a,&b);
		long long int c = b*b;
		if(a<c) printf("NO\n");
		else if((a-c)%2==1) printf("NO\n");
		else printf("YES\n");
	}
}
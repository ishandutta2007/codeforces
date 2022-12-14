#include <stdio.h>

int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		long long int a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		
		if(2*b-a>0 && (2*b-a)%c==0) printf("YES\n");
		else if(2*b-c>0 && (2*b-c)%a==0) printf("YES\n");
		else if((a+c)%2==0 && ((a+c)/2)%b==0) printf("YES\n");
		else printf("NO\n");
	}
}
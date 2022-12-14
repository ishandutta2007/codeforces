#include <stdio.h>

int main()
{
	long long int a,b,c,d;
	scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
	int e;
	scanf("%d",&e);
	
	int count = 0;
	for(int i=1;i<=e;i++)
	{
		long long int f,g,h;
		scanf("%lld%lld%lld",&f,&g,&h);
		long long int s1 = f*a+g*b+h;
		long long int s2 = f*c+g*d+h;
		if(s1<0&&s2>0) count++;
		if(s1>0&&s2<0) count++;
	}
	printf("%d\n",count);
}
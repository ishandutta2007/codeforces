#include <stdio.h>
long long int x[3000010];
int main()
{
	for(int i=1;i<(1<<21);i++)
	{
		x[i] = (long long int)i*i*i;
	}
	long long int a;
	scanf("%I64d",&a);
	long long int min=1,max=1,ans=-1;
	for(int i=1;i<=62;i++) max*=2;
	max-=10; max*=2;
	while(min<=max)
	{
		long long int h = (min+max)/2;
		long long int s = 0;
		for(int i=2;i<(1<<21)&&h>=x[i];i++) s+=h/x[i];
		if(s==a) ans = h;
		if(s<a) min = h+1;
		else max = h-1;
	}
	printf("%I64d",ans);
}
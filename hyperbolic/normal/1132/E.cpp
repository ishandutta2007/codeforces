#include <stdio.h>

long long int a;
long long int ans = 0;
long long int x[10];

int func2(long long int k, int type)
{
	if(k==0) return 1;
	if(type==0) return 0;
	
	if(k<=type*x[type])
	{
		long long int s1 = k%type;
		if(func2(s1,type-1)==1) return 1;
		if(s1+type<=k&&func2(s1+type,type-1)==1) return 1;
		if(s1+2*type<=k&&func2(s1+2*type,type-1)==1) return 1;
		return 0;
	}
	else
	{
		if(func2(k-type*x[type],type-1)==1) return 1;
		if(k-type*x[type]+type<=k&&func2(k-type*x[type]+type,type-1)==1) return 1;
		if(k-type*x[type]+2*type<=k&&func2(k-type*x[type]+2*type,type-1)==1) return 1;
		return 0;
	}
}
int main()
{
	scanf("%lld",&a);
	for(int i=1;i<=8;i++) scanf("%lld",&x[i]);
	
	long long int ans = 0;
	for(int i=8;i>=1;i--)
	{
		if(ans+i*x[i]<=a) ans += i*x[i];
		else
		{
			long long int C = (a-ans)/i;
			ans += C*i;
		}
	}
	for(long long int i = ans+1; i<=ans+10;i++)
	{
		if(i>a) break;
		if(func2(i,8)) ans = i;
	}
	printf("%lld",ans);
}
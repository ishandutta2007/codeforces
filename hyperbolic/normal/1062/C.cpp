#include <stdio.h>
#define MOD 1000000007

long long int power(long long int k)
{
	if(k==0) return 1;
	if(k==1) return 2;
	if(k%2==0)
	{
		long long int t = power(k/2);
		return (t*t)%MOD;
	}
	else
	{
		long long int t = power((k-1)/2);
		return ((t*t)%MOD*2)%MOD;
	}
}

char x[100010];
int s1[100010],s0[100010];
int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	scanf("%s",x+1);
	for(int i=1;i<=a;i++) s0[i] = x[i]=='0'?s0[i-1]+1:s0[i-1];
	for(int i=1;i<=a;i++) s1[i] = x[i]=='1'?s1[i-1]+1:s1[i-1];
	
	for(int i=1;i<=b;i++)
	{
		int c,d;
		scanf("%d%d",&c,&d);
		long long int t0 = s0[d]-s0[c-1];
		long long int t1 = s1[d]-s1[c-1];
		printf("%lld\n",(power(t1)-1)*power(t0)%MOD);
	}
}
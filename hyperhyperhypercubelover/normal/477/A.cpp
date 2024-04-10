#include<cstdio>

int main()
{
	long long r=0;
	long long t;
	int i,a,b;
	scanf("%d%d",&a,&b);
	for(i=1;i<b;i++)
	{
		r = (r+1LL*a*(a+1)/2%1000000007*i%1000000007*b%1000000007)%1000000007;
		r = (r+1LL*a*i%1000000007)%1000000007;
	}
	printf("%I64d",r);
}
#include <stdio.h>

int main()
{
	int a,b;
	scanf("%d%d",&a,&b);
	int p = (a+1)/2;
	long long int S2 = 0, S1 = 0;
	S2 += (long long int)p*(p-1)/2;
	S2 += (long long int)(a-p)*(a-p+1)/2;
	S1 = (long long int )a*(a-1)/2;
	long long int sum = 0;
	for(int i=1;i<=b;i++)
	{
		long long int c,d;
		scanf("%lld%lld",&c,&d);
		sum += c*a;
		if(d<0) sum += S2*d;
		else sum += S1*d;
	}
	printf("%.12lf",(double)sum/a);
}
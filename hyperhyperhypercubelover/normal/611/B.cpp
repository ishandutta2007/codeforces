#include<cstdio>

int main()
{
	long long a,b,t;
    int i,j,r=0;
    scanf("%I64d%I64d",&a,&b);
    for(i=1;i<=60;i++)for(j=0;j<i;j++)
	{
		t = (2LL<<i)-(1LL<<j)-1;
        if(a<=t&&t<=b)r++;
	}
	printf("%d",r);
}
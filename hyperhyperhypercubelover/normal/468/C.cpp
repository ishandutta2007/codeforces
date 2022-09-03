#include<cstdio>

long long f(long long n,long long q)
{
	long long i,j,r=0;
	for(i=j=1;i<=n;i*=10)
	{
		r+=(n/i/10-!q)*i;
		if(n/i%10==q)r+=n%i+1;
		if(n/i%10>q)r+=i;
	}
	return r;
}

long long g(long long n)
{
	long long i,r=0;
	if(n==0)return 0;
	for(i=1;i<10;i++)r+=i*f(n,i);
	return r;
}

int main()
{
	long long a=0;
	long long i,j,t,n;
	scanf("%I64d",&n);
    i=1;
    j=2e16;
    while(i<j)
	{
		t=(i+j)>>1;
		if(g(t)<n)i=t+1;
        else j=t;
	}
	i=1;
    while((t=g(j)-g(i-1))!=n)
	{
		if(t<n)j++;
		else i++;
	}
	printf("%I64d %I64d",i,j);
}
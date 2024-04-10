#include<cstdio>
#include<algorithm>

int a[222222];

int main()
{
	long long r=0;
	int i,n,m;
	scanf("%d%d",&n,&m);
	for(i=0;i<n+n;i++)scanf("%d",&a[i]);
    std::sort(a,a+n+n);
    r=std::min(std::min(6LL*a[0],3LL*a[n])*n,2LL*m);
	printf("%I64d.%I64d\n",r/2,r%2*5);
}
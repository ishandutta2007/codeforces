#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
#define P 10007
#define MAXN 100005
double a[128],x;
int n,m,L,i,j;
int main()
{
	scanf("%d%d",&n,&m);
	for(i=0;i<=m;i++)scanf("%lf",a+i);
	for(L=1;L<=m;L<<=1);
	for(i=1;i<L;i<<=1)for(j=0;j<L;j++)if(i&j)
	{
		x=a[i^j]+a[j];
		a[j]=a[i^j]-a[j];
		a[i^j]=x;
	}
	for(i=0;i<L;i++)a[i]=pow(a[i],n);
	for(i=1;i<L;i<<=1)for(j=0;j<L;j++)if(i&j)
	{
		x=a[i^j]+a[j];
		a[j]=(a[i^j]-a[j])/2;
		a[i^j]=x/2;
	}
	printf("%.8lf\n",1-a[0]);
	return 0;
}
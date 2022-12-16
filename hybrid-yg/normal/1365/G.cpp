#include<bits/stdc++.h>
using namespace std;
int n,i,m,a[1005],f[1005],k,p,j;
long long x[1005],c[1005],s;
long long Query(int a[],int p)
{
	int j;
	if(p==0)
		return 0;
	printf("? ");
	printf("%d",p);
	for(j=1;j<=p;++j)
		printf(" %d",a[j]);
	printf("\n");
	fflush(stdout);
	long long x;
	scanf("%lld",&x);
	return x;
}
void dfs(int i,int s,int p)
{
	if(i==13)
	{
		if(s==6)
			if(k<n)
				f[++k]=p;
		return;
	}
	dfs(i+1,s+1,p|(1<<i));
	dfs(i+1,s,p);
}
int main()
{
	scanf("%d",&n);
	dfs(0,0,0);
	for(i=0;i<13;++i)
	{
		p=0;
		for(j=1;j<=n;++j)
			if((f[j]>>i)&1)
				a[++p]=j;
		x[i]=Query(a,p);
		s|=x[i];
	}
	for(i=1;i<=n;++i)
	{
		long long s=9223372036854775807ll;
		for(j=0;j<13;++j)
			if((f[i]>>j)&1)
				s&=x[j];
			else
				s-=(s&x[j]);
		c[i]=s;
	}
	printf("!");
	for(i=1;i<=n;++i)
		printf(" %lld",s^c[i]);
	fflush(stdout);
}
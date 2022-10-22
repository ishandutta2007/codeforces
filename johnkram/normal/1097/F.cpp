#include<bits/stdc++.h>
using namespace std;
bitset<7001> a[7001],u[7001],d[100005];
int n,q,m,i,j,k,l,mu[7001],p[7001];
bool b[7001];
int main()
{
	n=7000;
	for(mu[1]=1,i=2;i<=n;i++)
	{
		if(!b[i])mu[p[m++]=i]=1;
		for(j=0;j<m&&i*p[j]<=n;j++)
		{
			b[i*p[j]]=1;
			if(i%p[j])mu[i*p[j]]=mu[i];
			else break;
		}
	}
	for(i=1;i<=n;i++)for(j=1;i*j<=n;j++)
	{
		a[i*j][i]=1;
		u[i][i*j]=mu[j];
	}
	scanf("%d%d",&n,&q);
	while(q--)
	{
		scanf("%d%d%d",&i,&j,&k);
		if(i==1)d[j]=a[k];
		else if(i==2)
		{
			scanf("%d",&l);
			d[j]=d[k]^d[l];
		}
		else if(i==3)
		{
			scanf("%d",&l);
			d[j]=d[k]&d[l];
		}
		else putchar(((d[j]&u[k]).count()&1)^'0');
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int t,n,m,N,x,i,j,l,r,mid,p[1000005],phi[1000005],mu[1000005],d[1005];
ll ans;
bool b[1000005];
int ask(int x)
{
	int i=1,j=0;
	for(;i<=N;i++)j+=x/d[i]*mu[d[i]];
	return j;
}
int main()
{
	n=1000000;
	for(phi[1]=mu[1]=1,i=2;i<=n;i++)
	{
		if(!b[i])
		{
			phi[p[m++]=i]=i-1;
			mu[i]=-1;
		}
		for(j=0;j<m&&i*p[j]<=n;j++)
		{
			b[i*p[j]]=1;
			if(i%p[j])
			{
				phi[i*p[j]]=phi[i]*phi[p[j]];
				mu[i*p[j]]=-mu[i];
			}
			else
			{
				phi[i*p[j]]=phi[i]*p[j];
				break;
			}
		}
	}
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&x,&n,&m);
		N=0;
		for(i=1;i*i<=n;i++)if(n%i==0)
		{
			d[++N]=i;
			if(i*i<n)d[++N]=n/i;
		}
		sort(d+1,d+N+1);
		m+=x/n*phi[n]+ask(x%n);
		ans=(ll)(m-1)/phi[n]*n;
		m=(m-1)%phi[n]+1;
		l=0;
		r=n;
		while(l+1<r)
		{
			mid=l+r>>1;
			if(ask(mid)<m)l=mid;
			else r=mid;
		}
		cout<<ans+r<<endl;
	}
	return 0;
}
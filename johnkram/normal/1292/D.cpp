#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define MAXN 33000005
ll ans,s;
int n,m,N,M,i,j,k,l,a[5005],d[5005],x[105],y[105],z[5005],w[5005],t[20005],ne[MAXN],h[MAXN],A[MAXN];
void dfs(int x)
{
	for(int i=h[x];i;i=ne[i])
	{
		dfs(i);
		A[x]+=A[i];
	}
	s+=A[x];
}
void work(int x)
{
	ans=min(ans,s);
	for(int i=h[x];i;i=ne[i])
	{
		s+=M-(A[i]<<1);
		work(i);
		s+=(A[i]<<1)-M;
	}
}
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d",&i);
		a[i]++;
	}
	n=5000;
	N=t[0]=1;
	d[0]=d[1]=1;
	for(i=2;i<=n;i++)
	{
		for(j=i,k=2,m=0;k*k<=j;k++)if(j%k==0)
		{
			x[++m]=k;
			for(y[m]=0;j%k==0;j/=k)y[m]++;
		}
		if(j>1)
		{
			x[++m]=j;
			y[m]=1;
		}
		for(j=1;j<=m;j++)
		{
			z[x[j]]+=y[j];
			s+=y[j];
		}
		copy(z,z+n+1,w);
		d[i]=t[s]=++N;
		for(j=2,k=s;j<x[m];j++)for(;w[j];w[j]--)
		{
			ne[N]=h[N+1];
			h[N+1]=N;
			t[--k]=++N;
		}
		for(j=0;j+1<y[m];j++)
		{
			ne[N]=h[N+1];
			h[N+1]=N;
			t[--k]=++N;
		}
		ne[N]=h[t[k-1]];
		h[t[k-1]]=N;
	}
	for(i=0;i<=n;i++)
	{
		A[d[i]]+=a[i];
		M+=a[i];
	}
	s=0;
	dfs(1);
	ans=s-=A[1];
	work(1);
	cout<<ans<<endl;
	return 0;
}
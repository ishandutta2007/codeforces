#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,kk,blockSize,u,v;
li res,d1,d2;
ll x[MAXN],sz[MAXN],lx[MAXN],rx[MAXN],bel[MAXN],r[551][551];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline li query(ll pos)
{
	li res=0;
	for(register int i=1;i<bel[pos];i++)
	{
		res+=sz[i]-(upper_bound(r[i]+1,r[i]+sz[i]+1,x[pos])-r[i]-1);
	}
	for(register int i=lx[bel[pos]];i<pos;i++)
	{
		res+=(x[i]>x[pos]);
	}
	for(register int i=pos+1;i<=rx[bel[pos]];i++)
	{
		res+=(x[i]<x[pos]);
	}
	for(register int i=bel[pos]+1;i<=bel[n];i++)
	{
		res+=upper_bound(r[i]+1,r[i]+sz[i]+1,x[pos])-r[i]-1;
	}
	return res;
}
int main()
{
	n=read(),kk=read(),blockSize=sqrt(n);
	for(register int i=1;i<=n;i++)
	{
		x[i]=i,bel[i]=bel[i-1]+(i%blockSize==1);
		r[bel[i]][++sz[bel[i]]]=x[i];
		i%blockSize==1?lx[bel[i]]=i,rx[bel[i-1]]=i-1:1;
	}
	for(register int i=1;i<=bel[n];i++)
	{
		sort(r[i]+1,r[i]+sz[i]+1);
	}
	rx[bel[n]]=n;
	for(register int i=1;i<=kk;i++)
	{
		u=read(),v=read();
		if(u==v)
		{
			printf("%lld\n",res);
			continue;
		}
		u>v?swap(u,v):(void)1,d1=query(u),d2=query(v);
		res-=d1+d2-(x[u]>x[v]);
		if(bel[u]!=bel[v])
		{
			for(register int j=1;j<=sz[bel[u]];j++)
			{
				if(r[bel[u]][j]==x[u])
				{
					r[bel[u]][j]=x[v];
					break;
				}
			}
			for(register int j=1;j<=sz[bel[v]];j++)
			{
				if(r[bel[v]][j]==x[v])
				{
					r[bel[v]][j]=x[u];
					break;
				}
			}	
		}
		sort(r[bel[u]]+1,r[bel[u]]+sz[bel[u]]+1);
		sort(r[bel[v]]+1,r[bel[v]]+sz[bel[v]]+1);
		swap(x[u],x[v]);
		d1=query(u),d2=query(v);
		res+=d1+d2-(x[u]>x[v]),printf("%lld\n",res);
	}
}
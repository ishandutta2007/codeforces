#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=65541;
ll n,m,x,y;
li kk,sm;
ll cnt[MAXN],u[MAXN],v[MAXN],p[MAXN],pw[25];
li f[MAXN][20];
inline li read()
{
    register li num=0,neg=1;
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
inline void DP(ll x)
{
	ll c;
	memset(f,0,sizeof(f)),f[0][0]=1;
	for(register int i=0;i<=pw[n]-1;i++)
	{
		for(register int j=0;j<=n;j++)
		{
			c=cnt[i]+1;
			if(v[c])
			{
				if((u[v[c]]&i)!=u[v[c]])
				{
					continue;
				}
				if((pw[v[c]-1]&i)==pw[v[c]-1])
				{
					continue;
				}
				f[i|pw[v[c]-1]][j|((v[c]==x)*c)]+=f[i][j];
				continue;
			}
			for(register int k=1;k<=n;k++)
			{
				if(!(pw[k-1]&i))
				{
					if((u[k]&i)==u[k])
					{
						f[i|pw[k-1]][j|((k==x)*c)]+=f[i][j];
					}
				}
			}
		}
	}
}
int main()
{
	n=read(),kk=read()-2000,m=read(),pw[0]=1;
	for(register int i=1;i<=n;i++)
	{
		pw[i]=pw[i-1]<<1;
	}
	for(register int i=0;i<=pw[n]-1;i++)
	{
		cnt[i]=__builtin_popcount(i);
	}
	for(register int i=1;i<=m;i++)
	{
		x=read(),y=read(),u[y]|=pw[x-1];
	}
	for(register int i=1;i<=n;i++)
	{
		DP(i),sm=0;
		for(register int j=1;j<=n;j++)
		{
			if(!v[j]&&sm+f[pw[n]-1][j]>=kk)
			{
				v[j]=i,p[i]=j,kk-=sm;
				break;
			}
			sm+=f[pw[n]-1][j];
		}
		if(!p[i])
		{
			return puts("The times have changed\n"),0;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",p[i]);
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2048;
ll n,m,kk,u,v,st;
li res;
ll f[MAXN][MAXN];
vector<ll>vg[MAXN];
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
int main()
{
	n=read(),m=read(),kk=read();
	for(register int i=1;i<=m;i++)
	{
		u=read(),v=read(),vg[u].push_back(v),vg[v].push_back(u);
	}
	for(register int i=1;i<=n;i++)
	{
		f[1<<i-1][1<<i-1]=1;
	}
	for(register int i=1;i<(1<<n);i++)
	{
		for(register int j=i;j;j=(j-1)&i)
		{
			for(register int k=1;k<=n;k++)
			{
				if((i>>k-1)&1)
				{
					for(register int l:vg[k])
					{
						if(!((i>>l-1)&1))
						{
							st=j|(1<<l-1),((j>>k-1)&1)?st^=(1<<k-1):1;
							__builtin_popcount(i)==1?st^=(1<<k-1):1;
							!(st>>l)?f[i|(1<<l-1)][st]+=f[i][j]:1;
						}
					}
				}
			}
		}
	}
	for(register int i=0;i<(1<<n);i++)
	{
		__builtin_popcount(i)==kk?res+=f[(1<<n)-1][i]:1;
	}
	printf("%lld\n",res);
}
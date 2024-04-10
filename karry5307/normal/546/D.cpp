#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=5e6+51;
ll test,ptot,x,y;
ll np[MAXN],prime[MAXN],f[MAXN],prefix[MAXN];
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
inline void sieve(ll limit)
{
	np[1]=1;
	for(register int i=2;i<=limit;i++)
	{
		if(!np[i])
		{
			prime[++ptot]=i,f[i]=1;
		}
		for(register int j=1;i*prime[j]<=limit;j++)
		{
			np[i*prime[j]]=1,f[i*prime[j]]=f[i]+1;
			if(i%prime[j]==0)
			{
				break;
			}
		}
	}
	for(register int i=1;i<=limit;i++)
	{
		prefix[i]=prefix[i-1]+f[i];
	}
}
inline void solve()
{
	x=read(),y=read(),printf("%d\n",prefix[x]-prefix[y]);
}
int main()
{
	test=read(),sieve(5000000);
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
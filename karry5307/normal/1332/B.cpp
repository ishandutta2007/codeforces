#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e3+51;
map<ll,ll>mp;
ll test,n,tot;
ll primes[15]={0,2,3,5,7,11,13,17,19,23,29,31};
ll x[MAXN],col[MAXN],disc[MAXN];
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
inline void solve()
{
	n=read(),mp.clear(),tot=0;
	for(register int i=0;i<n;i++)
	{
		x[i]=read();
		for(register int j=1;j<=11;j++)
		{
			if(x[i]%primes[j]==0)
			{
				col[i]=j;
				break;
			}
		}
	}
	for(register int i=0;i<n;i++)
	{
		if(mp.find(col[i])==mp.end())
		{
			mp[col[i]]=disc[i]=++tot;
		}
		else
		{
			disc[i]=mp[col[i]];
		}
	}
	printf("%d\n",mp.size());
	for(register int i=0;i<n;i++)
	{
		printf("%d ",disc[i]);
	}
	puts(""); 
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
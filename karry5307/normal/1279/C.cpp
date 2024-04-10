#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1e5+51;
ll test,cnt,ccnt,p,q,t,res;
ll x[MAXN],y[MAXN],v[MAXN],rid[MAXN];
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
	cnt=read(),ccnt=read(),res=p=t=0;
	for(register int i=1;i<=cnt;i++)
	{
		x[i]=read();
	}
	for(register int i=1;i<=ccnt;i++)
	{
		y[i]=read();
	}
	for(register int i=1;i<=cnt;i++)
	{
		v[x[i]]=((i-1)<<1|1),rid[x[i]]=i;
	}
	for(register int i=1;i<=ccnt;i++)
	{
		if(v[y[i]]==1)
		{
			res++;
			continue;
		}
		else
		{
			res+=v[y[i]]-((i-1)<<1);
		}
		t=rid[y[i]];
		for(register int j=t;j>p;j--)
		{
			v[x[j]]=1;
		}
		p=rid[y[i]];
	}
	printf("%lld\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
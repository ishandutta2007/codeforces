#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n;
ll x[MAXN],res[MAXN];
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
inline void calc(ll l,ll r,ll d)
{
	if(l>r)
	{
		return;
	}
	ll mx=-1,pos=0;
	for(register int i=l;i<=r;i++)
	{
		x[i]>mx?mx=x[i],pos=i:1;
	}
	res[pos]=d,calc(l,pos-1,d+1),calc(pos+1,r,d+1);
}
inline void solve()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),res[i]=0;
	}
	calc(1,n,0);
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",res[i]);
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
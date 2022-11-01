#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,res;
ll x[MAXN],y[MAXN];
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
inline ll lg2(ll x)
{
	ll res=0;
	while(x)
	{
		x>>=1,res++;
	}
	return res;
}
inline void solve()
{
	n=read(),res=0;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	for(register int i=2;i<=n;i++)
	{
		y[i]=max(0,y[i-1]+x[i-1]-x[i]);
		res=max(res,lg2(y[i]));
	}
	printf("%d\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
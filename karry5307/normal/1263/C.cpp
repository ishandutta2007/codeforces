#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1;
ll test,x,res;
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
inline void dfs2(ll l,ll r,ll x)
{
	if(l>x)
	{
		return;
	}
	dfs2(x/(x/l)+1,x/(x/l),x),res++;
}
inline void dfs(ll l,ll r,ll x)
{
	if(l>x)
	{
		return;
	}
	dfs(x/(x/l)+1,x/(x/l),x);
	printf("%d ",x/l);
}
inline void solve()
{
	x=read(),res=0,dfs2(2,0,x);
	printf("%d\n0 ",res+2),dfs(2,0,x),printf("%d\n",x);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,flg;
ll x[MAXN];
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
	n=read(),flg=1,x[1]=read();
	for(register int i=2;i<=n;i++)
	{
		flg&=((x[i]=read())==x[1]);
	}
	if(flg)
	{
		return (void)puts("No");	
	}
	puts("Yes");
	for(register int i=1;i<=n;i++)
	{
		x[i]!=x[1]?printf("%d %d\n",1,i),flg=i:1;
	}
	for(register int i=2;i<=n;i++)
	{
		x[i]==x[1]?printf("%d %d\n",i,flg):1;
	}
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
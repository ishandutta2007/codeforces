#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=3e5+51;
ll test,n,kk,res;
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
	n=read(),kk=read(),res=0;
	for(register int i=1;i<=n*kk;i++)
	{
		x[i]=read();
	}
	for(register int i=n*kk-n/2,j=1;i&&j<=kk;i-=n/2+1,j++)
	{
		res+=x[i];
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
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=151;
ll test,n,m,res,q;
ll x[MAXN][2][2];
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
inline ll check(ll x[2][2],ll y[2][2])
{
	if(x[0][1]!=y[1][0]||x[1][0]!=y[0][1])
	{
		return 0;
	}
	return 1;
}
inline void solve()
{
	n=read(),m=read(),q=0;
	for(register int i=1;i<=n;i++)
	{
		for(register int j=0;j<2;j++)
		{
			x[i][j][0]=read(),x[i][j][1]=read();
		}
	}
	if(m&1)
	{
		return (void)puts("No");
	}
	for(register int i=1;i<=n;i++)
	{
		if(check(x[i],x[i]))
		{
			q=1;
		}
	}
	puts(q?"Yes":"No");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
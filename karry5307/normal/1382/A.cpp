#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,m;
ll x[MAXN],y[MAXN],barrel[MAXN];
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
	n=read(),m=read(),memset(barrel,0,sizeof(barrel));
	for(register int i=1;i<=n;i++)
	{
		barrel[x[i]=read()]=1;
	}
	for(register int i=1;i<=m;i++)
	{
		y[i]=read();
	}
	for(register int i=1;i<=m;i++)
	{
		if(barrel[y[i]])
		{
			return (void)printf("YES\n1 %d\n",y[i]);
		}
	}
	puts("NO");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
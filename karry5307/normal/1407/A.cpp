#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,x,u,v;
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
	n=read(),u=v=0;
	for(register int i=1;i<=n;i++)
	{
		x=read(),x?u++:v++;
	}
	if(v>=u)
	{
		printf("%d\n",v);
		for(register int i=1;i<=v;i++)
		{
			printf("0 ");
		}
		return (void)puts("");
	}
	else
	{
		u=((u>>1)<<1),printf("%d\n",u);
		for(register int i=1;i<=u;i++)
		{
			printf("1 ");
		}
		return (void)puts("");
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
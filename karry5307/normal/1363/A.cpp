#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,kk;
ll x[MAXN],p[2];
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
	n=read(),kk=read(),p[0]=p[1]=0;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read()&1,i<=kk?p[x[i]]++:1;
	}
	if(p[1]&1)
	{
		return (void)puts("Yes");
	}
	for(register int i=kk+1;i<=n;i++)
	{
		if((p[0]&&x[i])||(p[1]&&!x[i]))
		{
			return (void)puts("Yes");
		}
	}
	puts("No");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
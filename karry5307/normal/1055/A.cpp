#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,kk;
ll u[MAXN],v[MAXN];
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
int main()
{
	n=read(),kk=read();
	for(register int i=1;i<=n;i++)
	{
		u[i]=read();
	}
	for(register int i=1;i<=n;i++)
	{
		v[i]=read();
	}
	if(!u[1])
	{
		return puts("NO"),0;
	}
	if(u[kk])
	{
		return puts("YES"),0;
	}
	if(!v[kk])
	{
		return puts("NO"),0;
	}
	for(register int i=kk+1;i<=n;i++)
	{
		if(u[i]&&v[i])
		{
			return puts("YES"),0;
		}
	}
	puts("NO");
}
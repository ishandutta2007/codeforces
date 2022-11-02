#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,res,c,d;
ll x[MAXN],f[MAXN],g[MAXN];
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
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),f[i]=min(f[i-1],c+=x[i]);
	}
	for(register int i=n;i;i--)
	{
		g[i]=min(g[i+1],d+=x[i]);
	}
	for(register int i=1;i<=n;i++)
	{
		res=max(res,c-2*f[i]-2*g[i+1]);
	}
	printf("%d\n",res);
}
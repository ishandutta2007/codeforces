#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,res;
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
		x[i]=read(),f[i]=x[i]>x[i-1]?f[i-1]+1:1;
	}
	for(register int i=n;i;i--)
	{
		g[i]=x[i]<x[i+1]?g[i+1]+1:1;
	}
	for(register int i=1;i<=n;i++)
	{
		res=max(res,max(f[i-1]+1,g[i+1]+1));
		res=max(res,x[i-1]+1<x[i+1]?f[i-1]+1+g[i+1]:0);
	}
	printf("%d\n",res);
}
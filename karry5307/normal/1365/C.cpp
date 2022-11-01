#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,res;
ll x[2][MAXN],rp[2][MAXN],barrel[MAXN];
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
inline ll reduce(ll x)
{
	return x<0?x+n:x;
}
int main()
{
	n=read();
	for(register int i=0;i<2;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			rp[i][x[i][j]=read()]=j;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		barrel[reduce(rp[0][i]-rp[1][i])]++;
	}
	for(register int i=0;i<n;i++)
	{
		res=max(res,barrel[i]);
	}
	printf("%d\n",res);
}
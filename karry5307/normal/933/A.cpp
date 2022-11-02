#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51; 
ll n,res;
ll x[MAXN],f[MAXN][3],g[MAXN][3];
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
		x[i]=read();
	}
	for(register int i=1;i<=n;i++)
	{
		f[i][1]=f[i-1][1],f[i][2]=f[i-1][2];
		x[i]==1?f[i][1]++:f[i][2]=max(f[i][1],f[i][2])+1;
	}
	for(register int i=n;i;i--)
	{
		g[i][1]=g[i+1][1],g[i][2]=g[i+1][2];
		x[i]==2?g[i][2]++:g[i][1]=max(g[i][1],g[i][2])+1;
	}
	for(register int i=0;i<=n;i++)
	{
		res=max(res,f[i][2]+g[i+1][1]);
	}
	printf("%d\n",res);
}
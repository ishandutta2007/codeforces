#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e3+51;
li test,n,res;
li x[MAXN],f[MAXN][MAXN];
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
	n=read(),res=1e18,memset(f,0x3f,sizeof(f));
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	sort(x+1,x+n+1);
	for(register int i=1;i<=421;i++)
	{
		f[1][i]=llabs(x[1]-i);
	}
	for(register int i=2;i<=n;i++)
	{
		for(register int j=1;j<=421;j++)
		{
			for(register int k=i-1;k<j;k++)
			{
				f[i][j]=min(f[i][j],f[i-1][k]+llabs(x[i]-j));
			}
		}
	}
	for(register int i=n;i<=421;i++)
	{
		res=min(res,f[n][i]);
	}
	printf("%d\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
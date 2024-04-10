#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=501;
ll test,n,m,r;
ll x[MAXN][MAXN],y[MAXN][MAXN];
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
	n=read(),m=read(),r=0;
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=m;j++)
		{
			x[i][j]=read();
		}
	}
	for(register int i=1;i<=m;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			y[i][j]=read();
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=m;j++)
		{
			if(x[i][j]==y[1][1])
			{
				r=j;
				break;
			}
		}
		if(r)
		{
			break;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			if(x[j][r]==y[1][i])
			{
				for(register int k=1;k<=m;k++)
				{
					printf("%d ",x[j][k]);
				}
				puts("");
			}
		}
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
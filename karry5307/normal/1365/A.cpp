#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,m,turn,flg;
ll x[51][51];
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
	n=read(),m=read(),turn=0;
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=m;j++)
		{
			x[i][j]=read();
		}
	}
	while(1)
	{
		turn^=1,flg=0;
		for(register int i=1;i<=n;i++)
		{
			for(register int j=1;j<=m;j++)
			{
				if(!x[i][j])
				{
					flg=1;
					for(register int k=1;k<=n;k++)
					{
						if(x[k][j])
						{
							flg=0;
							break;
						}
					}
					if(!flg)
					{
						continue;
					}
					for(register int k=1;k<=m;k++)
					{
						if(x[i][k])
						{
							flg=0;
							break;
						}
					}
					if(!flg)
					{
						continue;
					}
					x[i][j]=1;
				}
				if(flg)
				{
					break;
				}
			}
			if(flg)
			{
				break;
			}
		}
		if(!flg)
		{
			return (void)puts(turn?"Vivek":"Ashish");
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
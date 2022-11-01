#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,kk,z,res;
ll x[MAXN],f[MAXN][10][2];
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
	n=read(),kk=read(),z=read(),res=0;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
		for(register int j=0;j<=z;j++)
		{
			f[i][j][0]=f[i][j][1]=0;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		f[i][0][0]=f[i-1][0][0]+x[i];
		if(i-1==kk)
		{
			res=max(res,max(f[i][0][0],f[i][0][1]));
		}
	}
	for(register int j=1;j<=z;j++)
	{
		for(register int i=1;i<=n;i++)
		{
			f[i][j][0]=max(f[i-1][j][0],f[i-1][j][1])+x[i];
			f[i][j][1]=f[i+1][j-1][0]+x[i];
			if(i-1+j*2==kk)
			{
				res=max(res,max(f[i][j][0],f[i][j][1]));
			}
		}
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
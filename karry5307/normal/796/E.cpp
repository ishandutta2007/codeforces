#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1051; 
ll n,m,lx,rx,kk,res,ress,ls,rs;
bitset<MAXN>lp,rp;
ll dp[2][MAXN][61][61];
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
inline void chkmax(ll &x,const ll &y)
{
	x=max(x,y);
}
int main()
{
	n=read(),m=read(),kk=read(),lx=read();
	for(register int i=0;i<lx;i++)
	{
		lp[read()]=1;
	}
	rx=read();
	for(register int i=0;i<rx;i++)
	{
		rp[read()]=1;
	}
	if(m*kk>=n*2)
	{
		return printf("%d\n",(lp|rp).count()),0;
	}
	memset(dp,-0x3f,sizeof(dp)),dp[0][0][0][0]=0;
	for(register int k=1,i=1;k<=n;k++,i^=1)
	{
		memset(dp[i],-0x3f,sizeof(dp[i]));
		for(register int j=0;j<=m;j++)
		{
			for(register int l=0;l<=kk;l++)
			{
				for(register int r=0;r<=kk;r++)
				{
					ress=dp[i^1][j][l][r],ls=max(l-1,0),rs=max(r-1,0); 
					chkmax(dp[i][j][ls][rs],ress);
					if(l)
					{
						chkmax(dp[i][j][ls][rs],ress+lp[k]);
						chkmax(dp[i][j+1][ls][kk-1],ress+(lp[k]|rp[k]));
					}
					if(r)
					{
						chkmax(dp[i][j][ls][rs],ress+rp[k]);
						chkmax(dp[i][j+1][kk-1][rs],ress+(lp[k]|rp[k]));
					}
					if(l&&r)
					{
						chkmax(dp[i][j][ls][rs],ress+(lp[k]|rp[k]));
					}
					chkmax(dp[i][j+1][kk-1][rs],ress+lp[k]);
					chkmax(dp[i][j+1][ls][kk-1],ress+rp[k]);
					chkmax(dp[i][j+2][kk-1][kk-1],ress+(lp[k]|rp[k])); 
				}
			}
		}
	}
	for(register int i=0;i<=m;i++)
	{
		for(register int l=0;l<=kk;l++)
		{
			for(register int r=0;r<=kk;r++)
			{
				chkmax(res,dp[n&1][i][l][r]);
			}
		}
	}
	printf("%d\n",res);
}
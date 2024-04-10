#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=251;
ll n,kk,res;
char s[MAXN],t[MAXN];
ll f[MAXN][MAXN][MAXN];
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
inline ll calc()
{
	ll sum=0;
	for(register int i=1;i<=n;i++)
	{
		sum+=s[i]==t[1];
	}
	sum=min(n,sum+kk);
	return sum*(sum-1)/2;
}
int main()
{
	n=read(),kk=read(),scanf("%s",s+1),scanf("%s",t+1);
	if(t[1]==t[2])
	{
		return printf("%d\n",calc()),0;
	}
	memset(f,-0x3f,sizeof(f));
	for(register int i=0;i<=n;i++)
	{
		f[0][0][i]=0;
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=0;j<=i;j++)
		{
			for(register int k=0;k<=kk;k++)
			{
				f[i][j][k]=f[i-1][j][k];
				if(s[i]==t[1])
				{
					f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k]);
				}
				else
				{
					k?f[i][j][k]=max(f[i][j][k],f[i-1][j-1][k-1]):1;
				}
				if(s[i]==t[2])
				{
					f[i][j][k]=max(f[i][j][k],f[i-1][j][k]+j);
				}
				else
				{
					k?f[i][j][k]=max(f[i][j][k],f[i-1][j][k-1]+j):1;
				}
			}
		}
	}
	for(register int i=0;i<=n;i++)
	{
		res=max(res,f[n][i][kk]);
	}
	printf("%d\n",res);
}
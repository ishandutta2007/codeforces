#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e7+51,MOD=1e9+7;
ll n,sum,s;
ll f[MAXN][4];
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
	n=read(),f[0][0]=sum=1;
	for(register int i=1;i<=n;i++)
	{
		s=0;
		for(register int j=0;j<4;j++)
		{
			s=(s+(f[i][j]=(sum-f[i-1][j]+MOD)%MOD))%MOD;
		}
		sum=s;
	}
	printf("%d\n",f[n][0]);
}
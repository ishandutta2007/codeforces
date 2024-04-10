#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e3+51,MOD=1e9+7;
ll n,kk,res;
ll f[MAXN][MAXN];
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
	n=read(),kk=read();
	for(register int i=1;i<=n;i++)
	{
		f[i][1]=1;
		for(register int j=1;j<=kk;j++)
		{
			for(register int k=1;i*k<=n;k++)
			{
				f[i*k][j+1]=(f[i*k][j+1]+f[i][j])%MOD;
			}
		}
	}
	for(register int i=1;i<=n;i++)
	{
		res=(res+f[i][kk])%MOD;	
	}
	printf("%d\n",res);
}
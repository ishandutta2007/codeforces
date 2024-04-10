#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=3e3+51,MOD=1e9+7;
ll n,m,res;
ll f[MAXN][MAXN],g[MAXN][MAXN];
char ch[MAXN][MAXN];
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
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		scanf("%s",ch[i]+1);
	}
	f[1][2]=ch[1][2]=='.',g[2][1]=ch[2][1]=='.';
	for(register int i=3;i<=m;i++)
	{
		f[1][i]=ch[1][i]=='#'?0:f[1][i-1];
	}
	for(register int i=3;i<=n;i++)
	{
		g[i][1]=ch[i][1]=='#'?0:g[i-1][1];
	}
	for(register int i=2;i<=n;i++)
	{
		for(register int j=2;j<=m;j++)
		{
			if(ch[i][j]!='#')
			{
				f[i][j]=(f[i][j-1]+f[i-1][j])%MOD;
				g[i][j]=(g[i][j-1]+g[i-1][j])%MOD;
			}
		}
	}
	res=(((li)f[n-1][m]*g[n][m-1]-(li)f[n][m-1]*g[n-1][m])%MOD+MOD)%MOD;
	printf("%d\n",res);
}
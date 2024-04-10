#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef double db;
const ll MAXN=3e3+51;
ll n,m,mx;
db res;
db pr[MAXN][301],f[301][MAXN],dt[MAXN],tmp[MAXN];
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
inline void upd(ll x)
{
	memcpy(tmp,f[x],(n+1)*sizeof(db)),f[x][0]=0;
	for(register int i=1;i<=n;i++)
	{
		f[x][i]=f[x][i-1]*(1-pr[i][x])+tmp[i-1]*pr[i][x];
	}
	dt[x]-=f[x][n];
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=m;j++)
		{
			scanf("%lf",&pr[i][j]),pr[i][j]/=1000;
		}
	}
	for(register int i=1;i<=m;i++)
	{
		f[i][0]=1;
		for(register int j=1;j<=n;j++)
		{
			f[i][j]=f[i][j-1]*(1-pr[j][i]);
		}
		dt[i]=1-f[i][n];
	}
	for(register int i=1;i<=n;i++)
	{
		mx=0;
		for(register int j=1;j<=m;j++)
		{
			dt[j]>dt[mx]?mx=j:1;
		}
		res+=dt[mx],upd(mx);
	}
	printf("%.12lf\n",res);
}
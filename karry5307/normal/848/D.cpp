#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=51,MOD=1e9+7;
ll n,m,cof;
ll f[MAXN][MAXN],g[MAXN][MAXN],h[MAXN][MAXN],invf[MAXN];
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
	n=read(),m=read(),invf[1]=1,f[0][1]=1;
	if(m==n+1)
	{
		return puts("1"),0;
	}
	for(register int i=2;i<=n;i++)
	{
		invf[i]=MOD-(li)(MOD/i)*invf[MOD%i]%MOD;
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=i+1;j++)
		{
			for(register int k=0;k<=i-1;k++)
			{
				for(register int l=j;l<=i-k;l++)
				{
					g[i][j]=(g[i][j]+(li)f[k][j]*f[i-k-1][l])%MOD;
				}
				for(register int l=j+1;l<=k+1;l++)
				{
					g[i][j]=(g[i][j]+(li)f[k][l]*f[i-k-1][j])%MOD;
				}
			}
		}
		for(register int j=1;j<=i+1;j++)
		{
			memset(h,0,sizeof(h));
			for(register int l1=0;l1<=n;l1++)
			{
				for(register int l2=0;l2<=n;l2++)
				{
					cof=1;
					for(register int k=1;l1-i*k>=0&&l2-j*k>=0;k++)
					{
						cof=(li)cof*(g[i][j]+k-1)%MOD*invf[k]%MOD;
						h[l1][l2]=(h[l1][l2]+(li)f[l1-i*k][l2-j*k]*cof)%MOD;
					}
				}
			}
			for(register int j=0;j<=n;j++)
			{
				for(register int k=1;k<=n;k++)
				{
					f[j][k]=(f[j][k]+h[j][k])%MOD;
				}
			}
		}
	}
	printf("%d\n",f[n][m]);
}
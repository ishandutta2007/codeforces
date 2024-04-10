#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=551;
ll n,m,r,r1,r2,MOD;
ll binom[MAXN][MAXN],f[MAXN],f2[MAXN],g[MAXN][MAXN],g2[MAXN][MAXN];
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
	n=read(),m=read(),MOD=read(),binom[0][0]=f[0]=g[0][0]=1;
	for(register int i=1;i<=n;i++)
	{
		binom[i][0]=1;
		for(register int j=1;j<=i;j++)
		{
			binom[i][j]=(binom[i-1][j]+binom[i-1][j-1])%MOD;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		r1=r2=0;
		for(register int j=1;j<=i;j++)
		{
			f[i]=(f[i]+(li)binom[i-1][j-1]*f[j-1]%MOD*f[i-j])%MOD;
			r=j*(j-1)/2+(i-j+1)*(i-j)/2;
			r1=(r1+(li)binom[i-1][j-1]*r%MOD*f[j-1]%MOD*f[i-j])%MOD;
			r=((li)f[j-1]*f2[i-j]+(li)f2[j-1]*f[i-j])%MOD;
			r2=(r2+(li)binom[i-1][j-1]*r)%MOD;
		}
		f[i]=(li)f[i]*(i+1)%MOD,f2[i]=(r1+(li)(i+1)*r2)%MOD;
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=0;j<i;j++)
		{
			g[i][j]=g[i-1][j],g2[i][j]=g2[i-1][j];
			for(register int k=1;k<=j;k++)
			{
				g[i][j]=(g[i][j]+(li)binom[j][k]*f[k]%MOD*g[i-k-1][j-k])%MOD;
				r=((li)f2[k]*g[i-k-1][j-k]+(li)f[k]*g2[i-k-1][j-k])%MOD;
				g2[i][j]=(g2[i][j]+(li)binom[j][k]*r)%MOD;
			}
		}
		g[i][i]=f[i],g2[i][i]=f2[i];
	}
	printf("%d\n",g2[n][m]);
}
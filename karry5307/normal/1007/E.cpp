#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=251,inf=1e16;
ll n,m,t,kk,rr,rx;
ll x[MAXN],y[MAXN],v[MAXN],px[MAXN],py[MAXN];
ll d[MAXN][MAXN][2],g[MAXN][MAXN][2];
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
inline ll ceil(ll x,ll y)
{
	return x/y+!!(x%y);
}
inline void chkmin(ll &x,ll y)
{
	x=x<y?x:y;
}
int main()
{
	n=read(),t=read(),kk=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),y[i]=read(),v[i]=read();
		px[i]=px[i-1]+x[i],py[i]=py[i-1]+y[i];
	}
	x[++n]=inf,v[n]=inf,px[n]=px[n-1]+x[n];
	for(register int p=1;p<=n;p++)
	{
		for(register int s=0;s<=t;s++)
		{
			d[p][s][0]=d[p][s][1]=g[p][s][0]=g[p][s][1]=inf;
		}
	}
	for(register int p=1;p<=n;p++)
	{
		for(register int s=0;s<=t;s++)
		{
			for(register int z=0;z<=1;z++)
			{
				if(d[p-1][s][z]!=inf&&z*x[p]+s*y[p]<=v[p])
				{
					chkmin(d[p][s][z],d[p-1][s][z]);
					rr=ceil(z*px[p-1]+s*py[p-1],kk);
					rr*kk<=z*px[p]+s*py[p]?chkmin(g[p][s][z],rr):(void)1;
				}
				for(register int r=0;r<s;r++)
				{
					if(g[p][r][z]!=inf&&d[p-1][s-r][0]!=inf)
					{
						m=z*px[p]+r*py[p]-kk*g[p][r][z];
						rr=ceil(max(0ll,m+(s-r)*y[p]-v[p]),kk);
						if(kk*rr<=m)
						{
							chkmin(d[p][s][z],g[p][r][z]+rr+d[p-1][s-r][0]);
							rx=ceil((s-r)*py[p-1],kk);
							if(rx*kk<=m-kk*rr+(s-r)*py[p])
							{
								chkmin(g[p][s][z],g[p][r][z]+rx+rr);
							}
						}
					}
				}
				chkmin(d[p][s][z],g[p][s][z]);
			}
		}
	}
	printf("%lld\n",d[n][t][1]);
}
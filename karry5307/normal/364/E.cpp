#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=3e3+51;
ll n,m,kk;
li res;
ll pr[MAXN][MAXN],up[MAXN],dn[MAXN];
char ch[MAXN];
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
inline ll calc(ll xl,ll xr,ll yl,ll yr)
{
	return pr[xr][yr]-pr[xr][yl]-pr[xl][yr]+pr[xl][yl];
}
inline void calc1(ll xl,ll xr,ll yl,ll yr)
{
	if(xl==xr||yl==yr)
	{
		return;
	}
	if(xr==xl+1&&yr==yl+1)
	{
		return (void)(res+=calc(xl,xr,yl,yr)==kk);
	}
	ll d=xr-xl<yr-yl;
	if(d==0)
	{
		ll mid=(xl+xr)>>1;
		calc1(xl,mid,yl,yr),calc1(mid,xr,yl,yr);
		for(register int l=yl;l<=yr;l++)
		{
			up[0]=dn[0]=mid;
			for(register int i=1;i<=kk+1;i++)
			{
				up[i]=xl,dn[i]=xr;
			}
			for(register int r=l+1;r<=yr;r++)
			{
				for(register int i=1;i<=kk+1;i++)
				{
					while(calc(up[i],mid,l,r)>=i)
					{
						up[i]++;
					}
					while(calc(mid,dn[i],l,r)>=i)
					{
						dn[i]--;
					}
				}
				for(register int i=0;i<=kk;i++)
				{
					res+=(li)(up[i]-up[i+1])*(dn[kk-i+1]-dn[kk-i]);
				}
			}
		}
	}
	if(d==1)
	{
		ll mid=(yl+yr)>>1;
		calc1(xl,xr,yl,mid),calc1(xl,xr,mid,yr);
		for(register int l=xl;l<=xr;l++)
		{
			up[0]=dn[0]=mid;
			for(register int i=1;i<=kk+1;i++)
			{
				up[i]=yl,dn[i]=yr;
			}
			for(register int r=l+1;r<=xr;r++)
			{
				for(register int i=1;i<=kk+1;i++)
				{
					while(calc(l,r,up[i],mid)>=i)
					{
						up[i]++;
					}
					while(calc(l,r,mid,dn[i])>=i)
					{
						dn[i]--;
					}
				}
				for(register int i=0;i<=kk;i++)
				{
					res+=(li)(up[i]-up[i+1])*(dn[kk-i+1]-dn[kk-i]);
				}
			}
		}
	}
}
int main()
{
    n=read(),m=read(),kk=read();
    for(register int i=1;i<=n;i++)
    {
    	scanf("%s",ch+1);
    	for(register int j=1;j<=m;j++)
    	{
    		pr[i][j]=pr[i-1][j]+pr[i][j-1]-pr[i-1][j-1]+(ch[j]&1);
		}
	}
	calc1(0,n,0,m),printf("%lld\n",res);
}
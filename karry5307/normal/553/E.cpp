#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
using namespace std;
typedef int ll;
typedef double db;
const ll MAXN=2e5+51;
const db PI=acos(-1.0);
struct Complex{
	db re,im;
	Complex(db x=0,db y=0)
	{
		this->re=x,this->im=y;
	}
};
struct Edge{
	ll from,to,dist;
};
Complex f[MAXN],g[MAXN];
Edge ed[MAXN];
ll nc,ec,t,x;
ll rev[MAXN];
db p[110][MAXN],dis[111][111],dp[111][40051],dp2[111][40051];
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
inline Complex operator +(Complex x,Complex y)
{
	return Complex(x.re+y.re,x.im+y.im);
}
inline Complex operator -(Complex x,Complex y)
{
	return Complex(x.re-y.re,x.im-y.im);
}
inline Complex operator *(Complex x,Complex y)
{
	return Complex(x.re*y.re-x.im*y.im,x.re*y.im+x.im*y.re);
}
inline Complex operator /(Complex x,db y)
{
	return Complex(x.re/y,x.im/y);
}
inline void FFT(Complex *cp,ll cnt,ll inv)
{
	ll cur=0;
	Complex res,omg;
	for(register int i=0;i<cnt;i++)
	{
		if(i<rev[i])
		{
			swap(cp[i],cp[rev[i]]);
		}
	}
	for(register int i=2;i<=cnt;i<<=1)
	{
		cur=i>>1,res=Complex(cos(2*PI/i),inv*sin(2*PI/i));
		for(register Complex *p=cp;p!=cp+cnt;p+=i)
		{
			omg=Complex(1,0);
			for(register int j=0;j<cur;j++)
			{
				Complex t=omg*p[j+cur],t2=p[j];
				p[j+cur]=t2-t,p[j]=t+t2;
				omg=omg*res;
			}
		}
	}
	if(inv==-1)
	{
		for(register int i=0;i<cnt;i++)
		{
			cp[i]=cp[i]/cnt;
		}
	}
}
inline void calc(ll l,ll r)
{
	ll mid=(l+r)>>1,cnt,limit;
	for(register int j=1;j<=ec;j++)
	{
		cnt=1,limit=-1;
		while(cnt<=((r<<1)-l-mid-1))
		{
			cnt<<=1,limit++;
		}
		for(register int i=0;i<cnt;i++)
		{
			rev[i]=(rev[i>>1]>>1)|((i&1)<<limit);
			f[i]=g[i]=Complex(0,0);
		}
		for(register int i=mid+1;i<=r;i++)
		{
			f[i-mid-1].re+=dp[ed[j].to][i];
		}
		for(register int i=1;i<=r-l;i++)
		{
			g[r-l-i].re+=p[j][i];
		}
		FFT(f,cnt,1),FFT(g,cnt,1);
		for(register int i=0;i<cnt;i++)
		{
			f[i]=f[i]*g[i];
		}
		FFT(f,cnt,-1);
		for(register int i=l;i<=mid;i++)
		{
			dp2[j][i]+=f[i-mid-1+r-l].re;
		}
	}
}
inline void cdqFFT(ll l,ll r)
{ 
	if(l==r)
	{
		for(register int i=1;i<=ec;i++)
		{
			dp[ed[i].from][l]=min(dp[ed[i].from][l],dp2[i][l]+ed[i].dist);
		}
		return;
	}
	ll mid=(l+r)>>1;
	cdqFFT(mid+1,r),calc(l,r),cdqFFT(l,mid);
}
int main()
{
	nc=read(),ec=read(),t=read(),x=read();
	for(register int i=1;i<=nc;i++)
	{
		for(register int j=1;j<=nc;j++)
		{
			dis[i][j]=i^j?1061109567.0:0;
		}
	}
	for(register int i=1;i<=ec;i++)
	{
		ed[i].from=read(),ed[i].to=read(),ed[i].dist=read();
		dis[ed[i].from][ed[i].to]=min(dis[ed[i].from][ed[i].to],1.0*ed[i].dist);
		for(register int j=1;j<=t;j++)
		{
			p[i][j]=read()/100000.0;
		}
	}
	for(register int k=1;k<=nc;k++)
	{
		for(register int i=1;i<=nc;i++)
		{
			for(register int j=1;j<=nc;j++)
			{
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	for(register int i=0;i<=(t<<1);i++)
	{
		dp[nc][i]=i<=t?0:x;
	}
	for(register int i=1;i<nc;i++)
	{
		for(register int j=0;j<=(t<<1);j++)
		{
			dp[i][j]=(j<=t)?0x3f3f3f3f:dis[i][nc]+x; 
		}
	}
	calc(1,t<<1),cdqFFT(0,t);
	printf("%.10lf\n",dp[1][0]);
}
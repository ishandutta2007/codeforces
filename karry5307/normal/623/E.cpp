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
typedef long long int li;
typedef long double db;
const ll MAXN=65541,MOD=1e9+7; 
const db PI=acos(-1);
struct Complex{
	db re,im;
	Complex(db x=0,db y=0)
	{
		this->re=x,this->im=y;
	}
	inline Complex conj()
	{
		return Complex(re,-im);
	}
};
ll kk,limit,res;
li cnt,cur;
ll f[MAXN],g0[MAXN],g1[MAXN],rev[MAXN],pw[MAXN],fact[MAXN],finv[MAXN]; 
inline li read()
{
    register li num=0,neg=1;
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
inline ll qpow(ll base,ll exponent)
{
    li res=1;
    while(exponent)
    {
        if(exponent&1)
        {
            res=1ll*res*base%MOD;
        }
        base=1ll*base*base%MOD,exponent>>=1;
    }
    return res;
}
inline void setup(ll cnt)
{
	fact[0]=fact[1]=finv[0]=pw[0]=1,pw[1]=2;
	for(register int i=2;i<=cnt;i++)
	{
		fact[i]=(li)fact[i-1]*i%MOD;
		pw[i]=(pw[i-1]+pw[i-1])%MOD;
	}
	finv[cnt]=qpow(fact[cnt],MOD-2);
	for(register int i=cnt-1;i;i--)
	{
		finv[i]=(li)finv[i+1]*(i+1)%MOD;
	}
}
inline ll comb(ll m,ll n)
{
	return (li)fact[m]*finv[n]%MOD*finv[m-n]%MOD;
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
inline void conv(ll cnt,ll *f,ll *g,ll *res)
{
	Complex p,q,r,s;
	ll t;
	li t0,t1,t2,t3;
	static Complex tmpf[MAXN],tmpg[MAXN],p0[MAXN],p1[MAXN],p2[MAXN],p3[MAXN];
	for(register int i=0;i<cnt;i++)
	{
		tmpf[i]=Complex(f[i]&32767,f[i]>>15);
		tmpg[i]=Complex(g[i]&32767,g[i]>>15);
	}
	FFT(tmpf,cnt,1),FFT(tmpg,cnt,1);
	for(register int i=0;i<cnt;i++)
	{
		t=(cnt-i)&(cnt-1);
		p=(tmpf[i]+tmpf[t].conj())*Complex(0.5,0);
		q=(tmpf[i]-tmpf[t].conj())*Complex(0,-0.5);
		r=(tmpg[i]+tmpg[t].conj())*Complex(0.5,0);
		s=(tmpg[i]-tmpg[t].conj())*Complex(0,-0.5);
		p0[i]=p*r,p1[i]=p*s,p2[i]=q*r,p3[i]=q*s;
	}
	for(register int i=0;i<cnt;i++)
	{
		tmpf[i]=p0[i]+p1[i]*Complex(0,1);
		tmpg[i]=p2[i]+p3[i]*Complex(0,1);
	}
	FFT(tmpf,cnt,-1),FFT(tmpg,cnt,-1);
	for(register int i=0;i<cnt;i++)
	{
		t0=(li)(tmpf[i].re+0.5)%MOD,t1=(li)(tmpf[i].im+0.5)%MOD;
		t2=(li)(tmpg[i].re+0.5)%MOD,t3=(li)(tmpg[i].im+0.5)%MOD;
		res[i]=(t0+(t1+t2)*32768%MOD+t3*1073741824ll%MOD)%MOD;
	}
}
inline void shift(ll fd)
{
	ll cnt=1,limit=-1;
	while(cnt<=(fd<<1))
	{
		cnt<<=1,limit++;
	}
	for(register int i=0;i<cnt;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<limit),g0[i]=g1[i]=0;
	}
	for(register int i=0;i<cnt;i++)
	{
		g0[i]=(li)f[i]*finv[i]%MOD,g1[i]=(li)g0[i]*qpow(pw[i],cur%(MOD-1))%MOD,f[i]=0;
	}
	conv(cnt,g0,g1,f);
	for(register int i=0;i<cnt;i++)
	{
		f[i]=i<fd?(li)f[i]*fact[i]%MOD:0;
	}
	cur<<=1;
}
inline void setBit(ll fd)
{
	ll cnt=1,limit=-1;
	while(cnt<=(fd<<1))
	{
		cnt<<=1,limit++;
	}
	for(register int i=0;i<cnt;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<limit),g0[i]=g1[i]=0;
	}
	for(register int i=0;i<cnt;i++)
	{
		g0[i]=(li)f[i]*pw[i]%MOD*finv[i]%MOD,g1[i]=finv[i],f[i]=0;
	}
	g1[0]=0,conv(cnt,g0,g1,f);
	for(register int i=0;i<cnt;i++)
	{
		f[i]=i<fd?(li)f[i]*fact[i]%MOD:0;
	}
	cur|=1;
}
int main()
{
	cnt=read(),kk=read()+1,setup(kk),cur=1,limit=log2(cnt);
	for(register int i=1;i<kk;i++)
	{
		f[i]=1;
	}
	f[0]=0;
	for(register int i=limit-1;i>=0;i--)
	{
		shift(kk+10);
		if(cnt&(1<<i))
		{
			setBit(kk+10);
		}
	}
	for(register int i=0;i<kk;i++)
	{
		res=(res+(li)f[i]*comb(kk-1,i)%MOD)%MOD;
	}
	printf("%d\n",res);
}
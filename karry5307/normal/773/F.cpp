#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#pragma GCC diagnostic error "-std=c++11"
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
using namespace std;
typedef int ll;
typedef long long int li;
typedef long double db;
const ll MAXN=65537,P=32768;
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
ll x,fd,md,cur,res,cnt,limit;
ll rev[MAXN],odd[MAXN],even[MAXN],resOdd[MAXN],resEven[MAXN];
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
		t0=(li)(tmpf[i].re+0.5)%md,t1=(li)(tmpf[i].im+0.5)%md;
		t2=(li)(tmpg[i].re+0.5)%md,t3=(li)(tmpg[i].im+0.5)%md;
		res[i]=(t0+(t1+t2)*32768%md+t3*1073741824ll%md)%md;
	}
}
inline void shift(ll fd)
{
	static ll tmp[MAXN],tmp2[MAXN];
	memset(resOdd,0,sizeof(resOdd)),memset(resEven,0,sizeof(resEven));
	memset(tmp,0,sizeof(tmp)),memset(tmp2,0,sizeof(tmp2)),tmp[0]=1;
	for(register int i=1;i<fd;i++)
	{
		tmp[i]=(odd[i]+even[i])%md;
		tmp2[i]=cur&1?even[i]:odd[i];
	}
	conv(cnt,tmp,tmp2,resOdd);
	for(register int i=1;i<fd;i++)
	{
		resOdd[i]=(resOdd[i]+odd[i])%md;
	}
	for(register int i=fd;i<fd<<1;i++)
	{
		resOdd[i]=0;
	}
	memset(tmp,0,sizeof(tmp)),memset(tmp2,0,sizeof(tmp2)),tmp[0]=1;
	for(register int i=1;i<fd;i++)
	{
		tmp[i]=(odd[i]+even[i])%md;
		tmp2[i]=cur&1?odd[i]:even[i];
	}
	conv(cnt,tmp,tmp2,resEven);
	for(register int i=1;i<fd;i++)
	{
		resEven[i]=(resEven[i]+even[i])%md;
	}
	for(register int i=fd;i<fd<<1;i++)
	{
		even[i]=0;
	}
	cur<<=1;
}
inline void setBit(ll fd)
{
	for(register int i=fd-1;i>=2;i--)
	{
		resOdd[i]=(resOdd[i]+resOdd[i-1]+resEven[i-1])%md;
	}
	resOdd[1]=(resOdd[1]+1)%md;
	cur|=1;
}
inline void upd(ll fd)
{
	for(register int i=0;i<fd;i++)
	{
		odd[i]=resOdd[i],even[i]=resEven[i];
	}
	for(register int i=1;i<fd;i+=2)
	{
		res=(res+odd[i])%md;
	}
}
int main()
{
	// freopen("xgzc.out","w",stdout);
	fd=read(),x=read(),md=read(),cnt=1,limit=-1;
	if(x==1)
	{
		return puts("0"),0;
	}
	while(cnt<=((fd+1)<<1))
	{
		cnt<<=1,limit++;
	}
	for(register int i=0;i<cnt;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<limit);
	}
	odd[1]=1,res=cur=1,x>>=1,limit=log2(x);
	for(register int i=limit-1;i>=0;i--)
	{
		shift(fd+1);
		if(x&(1<<i))
		{
			setBit(fd+1);
		}
		upd(fd+1);
	}
	printf("%d\n",res);
}
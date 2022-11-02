#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef long double db;
const ll MAXN=524291;
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
ll n,kk,cnt=1,limit=-1;
Complex f[MAXN],g[MAXN];
ll x[MAXN],rev[MAXN],prefix[MAXN],barrel[MAXN],rb[MAXN];
li res[MAXN];
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
int main()
{
	n=read(),kk=read(),barrel[0]=1;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),barrel[prefix[i]=prefix[i-1]+(x[i]<kk)]++;
	}
	for(register int i=0;i<=n;i++)
	{
		rb[i]=barrel[i];
	}
	reverse(rb,rb+n+1);
	for(register int i=0;i<=n;i++)
	{
		f[i].re=barrel[i],g[i].re=rb[i];
	}
	while(cnt<=((n+1)<<1))
	{
		cnt<<=1,limit++;
	}
	for(register int i=0;i<cnt;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<limit);
	}
	FFT(f,cnt,1),FFT(g,cnt,1);
	for(register int i=0;i<cnt;i++)
	{
		f[i]=f[i]*g[i];
	}
	FFT(f,cnt,-1);
	for(register int i=0;i<=n;i++)
	{
		res[i]=(li)(f[i].re+0.5);
	}
	reverse(res,res+n+1),res[0]=0;
	for(register int i=0,p=0;i<=n;i++)
	{
        if(prefix[i]!=prefix[i-1])
        {
            p=i;
        }
		res[0]+=i-p;
	}
	for(register int i=0;i<=n;i++)
	{
		printf("%lld ",res[i]);
	}
}
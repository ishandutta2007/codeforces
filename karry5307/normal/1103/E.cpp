#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef unsigned long long int ull;
const ll MAXN=262151;
const ull MOD=1ll<<58,INV5=14757395258967641293ull;
struct Complex{
	ull x[4];
	inline ull &operator [](const ll &p)
	{
		return x[p];
	}
	inline const ull &operator [](const ll &p) const
	{
		return x[p];
	}
	Complex(ull x0=0,ull x1=0,ull x2=0,ull x3=0)
	{
		this->x[0]=x0,this->x[1]=x1,this->x[2]=x2,this->x[3]=x3;
	}
};
ll fd;
ll pw10[7]={1,10,100,1000,10000,100000,1000000};
Complex omega[10],t[10],f[MAXN];
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
	return Complex(x[0]+y[0],x[1]+y[1],x[2]+y[2],x[3]+y[3]);
}
inline Complex operator -(Complex x,Complex y)
{
	return Complex(x[0]-y[0],x[1]-y[1],x[2]-y[2],x[3]-y[3]);
}
inline Complex operator *(Complex x,Complex y)
{
	ull t[7];
	memset(t,0,sizeof(t));
	for(register int i=0;i<4;i++)
	{
		t[i]+=x[i]*y[0],t[i+1]+=x[i]*y[1],t[i+2]+=x[i]*y[2],t[i+3]+=x[i]*y[3];
	}
	for(register int i=6;i>3;i--)
	{
		t[i-1]-=t[i],t[i-2]-=t[i],t[i-3]-=t[i],t[i-4]-=t[i],t[i]=0;
	}
	return Complex(t[0],t[1],t[2],t[3]);
}
inline Complex qpow(Complex base,ll exponent)
{
	Complex res=omega[0];
	while(exponent)
	{
		if(exponent&1)
		{
			res=res*base;
		}
		base=base*base,exponent>>=1;
	}
	return res;
}
inline void setup()
{
	omega[0][0]=1,omega[1][3]=-1;
	for(register int i=2;i<10;i++)
	{
		omega[i]=omega[i-1]*omega[1];
	}
}
inline void FFT(ll inv)
{
	Complex omg;
	for(register int i=0;i<5;i++)
	{
		for(register int j=0;j<100000;j++)
		{
			if((j/pw10[i])%10==0)
			{
				memset(t,0,sizeof(t));
				for(register int p=0;p<10;p++)
				{
					for(register int q=0;q<10;q++)
					{
						omg=omega[inv==1?(p*q%10):(10-p*q%10)%10];
						t[p]=t[p]+f[j+q*pw10[i]]*omg;
					}
				}
				for(register int k=0;k<10;k++)
				{
					f[j+k*pw10[i]]=t[k];
				}
			}
		}
	}
	if(inv==-1)
	{
		ull invl=INV5*INV5*INV5*INV5*INV5;
		for(register int i=0;i<100000;i++)
		{
			f[i]=f[i]*invl;
		}
	}
}
int main()
{
	setup(),fd=read();
	for(register int i=0;i<fd;i++)
	{
		f[read()][0]++;
	}
	FFT(1);
	for(register int i=0;i<100000;i++)
	{
		f[i]=qpow(f[i],fd);
	}
	FFT(-1);
	for(register int i=0;i<fd;i++)
	{
		printf("%llu\n",(f[i][0]/32)%MOD);
	}
}
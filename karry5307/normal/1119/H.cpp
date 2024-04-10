#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51,MOD=998244353,INV2=499122177;
ll cnt,ccnt,x,y,z,lst,p,q,r,s,t;
ll f0[MAXN],f1[MAXN],f2[MAXN],f[MAXN];
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
inline ll qpow(ll base,ll exponent)
{
    ll res=1;
    while(exponent)
    {
        if(exponent&1)
        {
            res=res*base%MOD;
        }
        base=base*base%MOD,exponent>>=1;
    }
    return res;
}
inline void FWTXor(ll *f,ll cnt,ll inv)
{
	for(register int i=1;i<cnt;i<<=1)
	{
		for(register int p=0;p<cnt;p+=i<<1)
		{
			for(register int j=p;j<p+i;j++)
			{
				ll t=f[j],t2=f[j+i];
				f[j]=t+t2,f[j+i]=t-t2;
				if(inv==-1)
				{
					f[j]=f[j]*INV2%MOD,f[j+i]=f[j+i]*INV2%MOD;
				}
			}
		} 
	}
}
int main()
{
	ccnt=read(),cnt=1<<read(),x=read(),y=read(),z=read();
	for(register int i=0;i<ccnt;i++)
	{
		p=read(),q=read()^p,r=read()^p,lst^=p,f0[q]++,f1[r]++,f2[q^r]++;
	}
	FWTXor(f0,cnt,1),FWTXor(f1,cnt,1),FWTXor(f2,cnt,1);
	p=(x+y+z)%MOD,q=(x+y-z)%MOD,r=(x-y+z)%MOD,s=(x-y-z)%MOD;
	for(register int i=0;i<cnt;i++)
	{
		t=(ccnt+f0[i]+f1[i]+f2[i])>>2,f[i]=qpow(p,t);
		f[i]=f[i]*qpow(q,(ccnt+f0[i]-t-t)/2)%MOD;
		f[i]=f[i]*qpow(r,(ccnt+f1[i]-t-t)/2)%MOD;
		f[i]=f[i]*qpow(s,(ccnt+f2[i]-t-t)/2)%MOD;
	}
	FWTXor(f,cnt,-1);
	for(register int i=0;i<cnt;i++)
	{
		cout<<(f[i^lst]+MOD)%MOD<<" ";
	}
}
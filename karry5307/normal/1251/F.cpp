#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1048581,MOD=998244353,G=3,INVG=332748118;
ll cnt,kk,ccnt,x,u,v;
ll f[MAXN],g[MAXN],rev[MAXN],rres[MAXN],res[MAXN],p[MAXN];
ll fact[MAXN],finv[MAXN];
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
            res=(li)res*base%MOD;
        }
        base=(li)base*base%MOD,exponent>>=1;
    }
    return res;
}
inline void setup(ll cnt)
{
    fact[0]=finv[0]=1;
    for(register int i=1;i<cnt;i++)
    {
        fact[i]=(li)fact[i-1]*i%MOD;
    }
    finv[cnt-1]=qpow(fact[cnt-1],MOD-2);
    for(register int i=cnt-2;i;i--)
    {
        finv[i]=(li)finv[i+1]*(i+1)%MOD;
    }
}
inline ll comb(ll m,ll n)
{
	return m<n?0:(li)fact[m]*finv[m-n]%MOD*finv[n]%MOD;
}
inline void NTT(ll *cp,ll cnt,ll inv)
{
    ll cur=0,res=0,omg=0;
    for(register int i=0;i<cnt;i++)
    {
        if(i<rev[i])
        {
            swap(cp[i],cp[rev[i]]);
        }
    }
    for(register int i=2;i<=cnt;i<<=1)
    {
        cur=i>>1,res=qpow(inv==1?G:INVG,(MOD-1)/i);
        for(register ll *p=cp;p!=cp+cnt;p+=i)
        {
            omg=1;
            for(register int j=0;j<cur;j++)
            {
                ll t=1ll*omg*p[j+cur]%MOD,t2=p[j];
                p[j+cur]=(t2-t+MOD)%MOD,p[j]=(t2+t)%MOD;
                omg=1ll*omg*res%MOD;
            }
        }
    }
    if(inv==-1)
    {
        ll invl=qpow(cnt,MOD-2);
        for(register int i=0;i<=cnt;i++)
        {
            cp[i]=1ll*cp[i]*invl%MOD;
        }
    }
}
inline void conv(ll cnt,ll *f,ll *g,ll *res)
{
	static ll tmpf[MAXN],tmpg[MAXN];
	for(register int i=0;i<cnt;i++)
	{
		tmpf[i]=f[i],tmpg[i]=g[i];
	}
	ll limit=log2(cnt)-1;
	for(register int i=0;i<cnt;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<limit);
	}
	NTT(tmpf,cnt,1),NTT(tmpg,cnt,1);
	for(register int i=0;i<cnt;i++)
	{
		res[i]=(li)tmpf[i]*tmpg[i]%MOD;
		tmpf[i]=tmpg[i]=0;
	}
	NTT(res,cnt,-1);
}
int main()
{
	setup((cnt=read())<<1),kk=read(),ccnt=1;
	while(ccnt<=(cnt<<1))
	{
		ccnt<<=1;
	}	
	for(register int i=1;i<=cnt;i++)
	{
		p[read()]++;
	}
	for(register int i=1;i<=kk;i++)
	{
		x=read(),u=v=0;
		for(register int j=1;j<x;j++)
		{
			p[j]==1?u++:p[j]>=2?v++:v;
		}
		for(register int j=0;j<ccnt;j++)
		{
			f[j]=(li)comb(u,j)*qpow(2,j)%MOD;
			g[j]=comb(v<<1,j);
		}
		conv(ccnt,f,g,rres);
		for(register int j=0;j<=cnt;j++)
		{
			res[j+x+1]=(res[j+x+1]+rres[j])%MOD;
		}
	}
	ccnt=read();
	for(register int i=0;i<ccnt;i++)
	{
		printf("%d\n",res[read()>>1]);
	}
}
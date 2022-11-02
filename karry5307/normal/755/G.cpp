#include<cstdio>
#include<cstring>
#include<cctype>
#include<cmath>
#include<iostream>
#include<algorithm>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
typedef int ll;
typedef long long int li;
typedef unsigned long long int ull;
const ll MAXN=65541,MOD=998244353,G=3,INVG=332748118;
ll n,kk,fd,c,invl;
ll rev[MAXN],omgs[MAXN],invo[MAXN],f[MAXN],g[MAXN],h[MAXN];
ll invx[MAXN];
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
inline void setupOmg(ll cnt)
{
    ll limit=log2(cnt)-1,omg;
    omg=qpow(G,(MOD-1)>>(limit+1)),omgs[cnt>>1]=1;
    for(register int i=(cnt>>1|1);i!=cnt;i++)
    {
		omgs[i]=(li)omgs[i-1]*omg%MOD;
    }
    for(register int i=(cnt>>1)-1;i;i--)
    {
		omgs[i]=omgs[i<<1]; 
    }
}
inline void NTT(ll *cp,ll cnt,ll inv)
{
    static ull tcp[MAXN];
    register ll cur=0,x,shift=log2(cnt)-__builtin_ctz(cnt);
    if(inv==-1)
    {
    	reverse(cp+1,cp+cnt);
    }
    for(register int i=0;i<cnt;i++)
    {
		tcp[rev[i]>>shift]=cp[i];
    }
    for(register int i=2;i<=cnt;i<<=1)
    {
        cur=i>>1;
        for(register int j=0;j<cnt;j+=i)
        {
            for(register int k=0;k<cur;k++)
            {
                x=tcp[j|k|cur]*omgs[k|cur]%MOD;
                tcp[j|k|cur]=tcp[j|k]+MOD-x,tcp[j|k]+=x;
            }
        }
    }
    for(register int i=0;i<cnt;i++)
    {
    	cp[i]=tcp[i]%MOD;
    }
    if(inv==1)
    {
		return;
    }
    x=MOD-(MOD-1)/cnt;
    for(register int i=0;i<cnt;i++)
    {
		cp[i]=(li)cp[i]*x%MOD;
    }
}
inline void deriv(ll fd,ll *f,ll *res)
{
    for(register int i=1;i<fd;i++)
    {
        res[i-1]=1ll*f[i]*i%MOD;
    }
    res[fd-1]=0;
}
inline void integ(ll fd,ll *f,ll *res)
{
    for(register int i=1;i<fd;i++)
    {
        res[i]=1ll*f[i-1]*invx[i]%MOD;
    }
    res[0]=0;
}
inline void conv(ll fd,ll *f,ll *g,ll *res)
{
    static ll tmpf[MAXN],tmpg[MAXN];
    ll cnt=1,limit=-1;
    while(cnt<(fd<<1))
    {
        cnt<<=1,limit++;
    }
    for(register int i=0;i<cnt;i++)
    {
		tmpf[i]=i<fd?f[i]:0,tmpg[i]=i<fd?g[i]:0;
		rev[i]=(rev[i>>1]>>1)|((i&1)<<limit);
    }
    NTT(tmpf,cnt,1),NTT(tmpg,cnt,1);
    for(register int i=0;i<cnt;i++)
    {
		tmpf[i]=(li)tmpf[i]*tmpg[i]%MOD;
    }
    NTT(tmpf,cnt,-1);
    for(register int i=0;i<fd;i++)
    {
		res[i]=tmpf[i];
    }
}
inline void invBF(ll fd,ll *f,ll *res)
{
	li r,invl=qpow(f[0],MOD-2);
	res[0]=invl;
	for(register int i=1;i<fd;i++)
	{
		r=0;
		for(register int j=0;j<i;j++)
		{
			r+=(li)res[j]*f[i-j]%MOD;
		}
		res[i]=(li)(MOD-r%MOD)*invl%MOD;
	}
}
inline void inv(ll fd,ll *f,ll *res)
{
    static ll tmp[MAXN];
    if(fd<=1024)
    {
        return invBF(fd,f,res);
    }
    inv((fd+1)>>1,f,res);
    ll cnt=1,limit=-1;
    while(cnt<(fd<<1))
    {
        cnt<<=1,limit++;
    }
    for(register int i=0;i<cnt;i++)
    {
        tmp[i]=i<fd?f[i]:0;
        rev[i]=(rev[i>>1]>>1)|((i&1)<<limit);
    }
    NTT(tmp,cnt,1),NTT(res,cnt,1);
    for(register int i=0;i<cnt;i++)
    {
        res[i]=(li)(2-(li)tmp[i]*res[i]%MOD+MOD)%MOD*res[i]%MOD;
    }
    NTT(res,cnt,-1);
    for(register int i=fd;i<cnt;i++)
    {
        res[i]=0;
    }
}
inline void lnBF(ll fd,ll *f,ll *res)
{
	li r;
	res[0]=0;
	for(register int i=1;i<fd;i++)
	{
		r=0;
		for(register int j=1;j<i;j++)
		{
			r+=(li)f[j]*res[i-j]%MOD;
		}
		res[i]=((li)i*f[i]%MOD-r%MOD+MOD)%MOD;
	}
	for(register int i=1;i<fd;i++)
	{
		res[i]=(li)res[i]*invx[i]%MOD;
	}
}
inline void ln(ll fd,ll *f,ll *res)
{
    static ll pinv[MAXN],der[MAXN];
    if(fd<=1024)
    {
    	return lnBF(fd,f,res);
	}
    inv(fd,f,pinv),deriv(fd,f,der),conv(fd,pinv,der,der),integ(fd,der,res);
    for(register int i=0;i<fd;i++)
    {
        der[i]=pinv[i]=0;
    }
}
inline void expBF(ll fd,ll *f,ll *res)
{
	li r;
	res[0]=1;
	for(register int i=1;i<fd;i++)
	{
		r=0,f[i]=(li)f[i]*i%MOD;
		for(register int j=0;j<i;j++)
		{
			r+=(li)f[j+1]*res[i-j-1]%MOD;
		}
		res[i]=r%MOD*invx[i]%MOD;
	}
	for(register int i=1;i<fd;i++)
	{
		f[i]=(li)f[i]*invx[i]%MOD;
	}
}
inline void exp(ll fd,ll *f,ll *res)
{
    static ll texp[MAXN];
	if(fd<=1024)
    {
    	return expBF(fd,f,res);
	}
	if(fd==1)
    {
        return (void)(res[0]=1);
    }
    exp((fd+1)>>1,f,res),ln(fd,res,texp),texp[0]=(f[0]+1-texp[0]+MOD)%MOD;
    for(register int i=1;i<fd;i++)
    {
        texp[i]=(f[i]-texp[i]+MOD)%MOD;
    }
    conv(fd,texp,res,res);
}
int main()
{
	n=read(),kk=read(),fd=min(n,kk)+1;
	f[0]=g[0]=1,f[1]=3,g[1]=MOD-3,setupOmg(65536);
	for(register int i=2;i<fd;i++)
	{
		c=((li)(6*i-9)*f[i-1]+(li)(i-3)*f[i-2])%MOD;
		f[i]=(li)(MOD-c)*(invl=qpow(i,MOD-2))%MOD;
		c=((li)(6*i-3)*g[i-1]+(li)(i-1)*g[i-2])%MOD;
		g[i]=(li)(MOD-c)*invl%MOD;
	}
	f[0]++,f[1]++,f[0]>>=1,f[1]>>=1,invx[1]=1;
	for(register int i=2;i<fd;i++)
	{
		f[i]=f[i]&1?(f[i]+MOD)>>1:f[i]>>1;
		invx[i]=(li)(MOD-MOD/i)*invx[MOD%i]%MOD;
	}
	ln(fd,f,h);
	for(register int i=0;i<fd;i++)
	{
		h[i]=(li)h[i]*(n+1)%MOD,f[i]=0;
	}
	exp(fd,h,f),conv(fd,f,g,h);
	for(register int i=1;i<fd;i++)
	{
		printf("%d ",h[i]);
	}
	for(register int i=fd;i<=kk;i++)
	{
		printf("%d ",0);
	}
}
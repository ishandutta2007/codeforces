#include<cstdio>
#include<algorithm>
#include<cmath>
#pragma GCC optimize("O2,O3,Ofast,unroll-loops")
using namespace std;
typedef int ll;
typedef long long int li;
typedef unsigned long long int ull;
const ll MAXN=262151,MOD=998244353,G=3,INVG=332748118;
ll n,ptot;
li m;
ll fact[MAXN>>1],finv[MAXN>>1],f[MAXN>>1],f0[MAXN>>1],g[MAXN>>1];
ll rev[MAXN],omgs[MAXN],invo[MAXN],np[MAXN>>1],prime[MAXN>>1],pw[MAXN>>1];
inline li read()
{
    register li num=0;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num;
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
inline void setup(ll cnt)
{
	fact[0]=fact[1]=finv[0]=1;
	for(register int i=2;i<=cnt;i++)
	{
		fact[i]=(li)fact[i-1]*i%MOD;
	}
	finv[cnt]=qpow(fact[cnt],MOD-2);
	for(register int i=cnt-1;i;i--)
	{
		finv[i]=(li)finv[i+1]*(i+1)%MOD;
	}
}
inline void sieve(ll limit)
{
	np[1]=pw[1]=1;
	for(register int i=2;i<=limit;i++)
	{
		if(!np[i])
		{
			prime[++ptot]=i,pw[i]=qpow(i,MOD-1-m);
		}
		for(register int j=1;i*prime[j]<=limit;j++)
		{
			np[i*prime[j]]=1,pw[i*prime[j]]=(li)pw[i]*pw[prime[j]]%MOD;
			if(i%prime[j]==0)
			{
				break;
			}
		}
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
int main()
{
	setup(n=read()),setupOmg(262144),m=read()%(MOD-1),sieve(n+1);
	for(register int i=0;i<=n;i++)
	{
		f[i]=finv[i],f0[n-i]=(li)fact[i]*read()%MOD;
	}
	conv(n+1,f,f0,f);
	for(register int i=0;i<=n;i++)
	{
		g[i]=(li)finv[i]*f[n-i]%MOD*pw[i+1]%MOD;
	}
	for(register int i=0;i<=n;i++)
	{
		f[i]=i&1?(MOD-finv[i])%MOD:finv[i],f0[i]=(li)fact[n-i]*g[n-i]%MOD;
	}
	conv(n+1,f,f0,f);
	for(register int i=0;i<=n;i++)
	{
		printf("%d ",(li)finv[i]*f[n-i]%MOD);
	}
}
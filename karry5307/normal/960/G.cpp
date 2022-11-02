#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=8e5+51,MOD=998244353,G=3,INVG=332748118;
ll cnt,l,r;
ll rev[MAXN],fact[MAXN],finv[MAXN];
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
    li res=1;
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
    fact[0]=fact[1]=finv[0]=1;
	if(!cnt)
	{
		return;
	}
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
inline ll comb(ll n,ll m)
{
	if(!n||!m||n>m)
	{
		return 0;
	}
	return (li)fact[m]*finv[n]%MOD*finv[m-n]%MOD;
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
                ll t=(li)omg*p[j+cur]%MOD,t2=p[j];
                p[j+cur]=(t2-t+MOD)%MOD,p[j]=(t2+t)%MOD;
                omg=(li)omg*res%MOD;
            }
        }
    }
    if(inv==-1)
    {
        ll invl=qpow(cnt,MOD-2);
        for(register int i=0;i<=cnt;i++)
        {
            cp[i]=(li)cp[i]*invl%MOD;
        }
    }
}
vector<ll> tmpf[MAXN<<2];
inline void dnc(ll l,ll r,ll node)
{
	static ll tmp[MAXN],tmp2[MAXN];
	if(l==r)
	{
		tmpf[node].push_back(l),tmpf[node].push_back(1);
		return;
	}
	ll mid=(l+r)>>1,d,d2,cnt=1,limit=-1;
	dnc(l,mid,node<<1),dnc(mid+1,r,(node<<1)|1);
	d=tmpf[node<<1].size(),d2=tmpf[(node<<1)|1].size();
	for(register int i=0;i<d;i++)
	{
		tmp[i]=tmpf[node<<1][i];
	}
	for(register int i=0;i<d2;i++)
	{
		tmp2[i]=tmpf[(node<<1)|1][i];
	}
	while(cnt<(d+d2))
	{
		cnt<<=1,limit++;
	}
	for(register int i=0;i<cnt;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<limit);
	}
	NTT(tmp,cnt,1),NTT(tmp2,cnt,1);
	for(register int i=0;i<cnt;i++)
	{
		tmp[i]=(li)tmp[i]*tmp2[i]%MOD;
	}
	NTT(tmp,cnt,-1);
	for(register int i=0;i<d+d2;i++)
	{
		tmpf[node].push_back(tmp[i]);
	}
	for(register int i=0;i<cnt;i++)
	{
		tmp[i]=tmp2[i]=0;
	}
}
int main()
{
    cnt=read(),l=read(),r=read();
	if(!l||!r||l+r-2>cnt-1)
	{
		puts("0");
		return 0;
	}
	if(cnt==1)
	{
		puts("1");
		return 0;
	}
	setup(l+r-2),dnc(0,cnt-2,1);
	printf("%d\n",(li)tmpf[1][l+r-2]*comb(l-1,l+r-2)%MOD);
	
}
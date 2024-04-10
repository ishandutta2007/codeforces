#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
#define pb emplace_back
#define popc __builtin_popcount
using namespace std;
typedef int ll;
typedef long long int li;
typedef vector<ll> vi;
const ll MAXN=65541,MOD=998244353;
map<vi,ll>mp;
ll n,kk,c,xorv,tot,fct,d,tp;
ll x[MAXN],invl[MAXN],finv[MAXN],f[MAXN],cnt[MAXN<<1];
ll st[201],sm[201],tmp[21],tmp2[21],tmp3[21];
li tmp4[21];
vi v[MAXN];
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
inline void ln(ll fd,ll *f,ll *res)
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
		res[i]=(li)res[i]*invl[i]%MOD;
	}
}
inline void exp(ll fd,ll *f,ll *res)
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
		res[i]=r%MOD*invl[i]%MOD;
	}
}
int main()
{
	n=read(),kk=read(),c=read(),invl[0]=invl[1]=finv[0]=finv[1]=fct=1;
	for(register int i=2;i<65536;i++)
	{
		invl[i]=(MOD-(li)(MOD/i)*invl[MOD%i]%MOD)%MOD;
		finv[i]=(li)finv[i-1]*invl[i]%MOD;
	}
	for(register int i=1;i<=n;i++)
	{
		xorv^=(x[i]=read());
		for(register int j=0;j<=kk;j++)
		{
			v[i].pb(x[i]^(x[i]-j));
		}
		mp[v[i]]++;
	}
	for(auto i:mp)
	{
		v[++tot]=i.first,sm[tot]=i.second;
	}
	for(register int i=2;i<=kk;i++)
	{
		fct=(li)fct*i%MOD;
	}
	for(register int s=0;s<(1<<c);s++)
	{
		for(register int i=1;i<=tot;i++)
		{
			d=0;
			for(register int j=0;j<=kk;j++)
			{
				d|=((popc(s&v[i][j])&1)<<j);
			}
			!cnt[d]?st[++tp]=d:1,cnt[d]+=sm[i];
		}
		memset(tmp,0,sizeof(tmp)),tmp[0]=1;
		for(register int i=1;i<=tp;i++)
		{
			for(register int j=0;j<=kk;j++)
			{
				tmp2[j]=(st[i]&(1<<j))?MOD-finv[j]:finv[j];
			}
			ln(kk+1,tmp2,tmp3);
			for(register int j=0;j<=kk;j++)
			{
				tmp3[j]=(li)tmp3[j]*cnt[st[i]]%MOD;
			}
			exp(kk+1,tmp3,tmp2),memset(tmp4,0,sizeof(tmp4));
			for(register int j=0;j<=kk;j++)
			{
				for(register int k=0;k<=kk-j;k++)
				{
					tmp4[j+k]+=(li)tmp2[j]*tmp[k];
				}
			}
			for(register int j=0;j<=kk;j++)
			{
				tmp[j]=tmp4[j]%MOD;
			}
			cnt[st[i]]=0;
		}
		tp=0,f[s]=(li)tmp[kk]*fct%MOD;
	}
	for(register int i=1;i<(1<<c);i<<=1)
	{
		for(register int p=0;p<(1<<c);p+=i<<1)
		{
			for(register int j=p;j<p+i;j++)
			{
				d=f[j],f[j]=(f[j]+f[j+i])%MOD,f[j+i]=(d-f[j+i]+MOD)%MOD;
			}
		}
	}
	d=(li)qpow(1<<c,MOD-2)*qpow(n,MOD-1-kk)%MOD;
	for(register int i=0;i<(1<<c);i++)
	{
		printf("%d ",(li)f[i^xorv]*d%MOD);
	}
}
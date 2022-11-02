#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=6e5+51;
set<ll>res;
set<ll>::iterator it;
ll MOD,G,INVG;
ll fd,cnt,limit,inv2,v,p,q,r,s,sum,cur;
ll f[MAXN],g[MAXN],rev[MAXN],tmp[MAXN],delta[MAXN],delta2[MAXN],h[MAXN];
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
inline ll qmul(ll x,ll y)
{
	return (x*y-(ll)((long double)x*y/MOD)*MOD+MOD)%MOD;
}
inline ll qpow(ll base,ll exponent)
{
    ll res=1;
    while(exponent)
    {
        if(exponent&1)
        {
            res=qmul(res,base)%MOD;
        }
        base=qmul(base,base)%MOD,exponent>>=1;
    }
    return res;
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
                ll t=qmul(omg,p[j+cur]%MOD),t2=p[j];
                p[j+cur]=(t2-t+MOD)%MOD,p[j]=(t2+t)%MOD;
                omg=qmul(omg,res);
            }
        }
    }
    if(inv==-1)
    {
        ll invl=qpow(cnt,MOD-2);
        for(register int i=0;i<=cnt;i++)
        {
            cp[i]=qmul(cp[i],invl)%MOD;
        }
    }
}
inline void setup()
{
	ll lcm,flg;
	cnt=1,limit=-1;
	while(cnt<=(fd<<1))
	{
		cnt<<=1,limit++;
	}
	lcm=fd/__gcd(fd,cnt)*cnt,MOD=lcm+1;
	while(MOD<1e5)
	{
		MOD+=lcm;
	}
	while(1)
	{
		flg=1;
		for(register int i=2;i<=sqrt(MOD);i++)
		{
			if(MOD%i==0)
			{
				flg=0;
				break;
			}
		}
		if(flg)
		{
			break;
		}
		MOD+=lcm;
	}
	for(G=2;;G++)
	{
		flg=1;
		for(register int i=2;i<=sqrt(MOD);i++)
		{
			if((MOD-1)%i==0)
			{
				if(qpow(G,i)==1||qpow(G,(MOD-1)/i)==1)
				{
					flg=0;
					break;
				}
			}
		}
		if(flg)
		{
			break;
		}
	}
	INVG=qpow(G,MOD-2);
	for(register int i=0;i<cnt;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<limit);
	}
}
inline ll comb(ll x)
{
	return x*(x-1)/2%fd;
}
inline void Bluestein(ll fd,ll *cp,ll inv)
{
	static ll tmp[MAXN],tmp2[MAXN];
	ll g=qpow(inv==1?G:INVG,(MOD-1)/fd);
	for(register int i=0;i<fd<<1;i++)
	{
		tmp[(fd<<1)-1-i]=qpow(g,comb(i));
	}
	for(register int i=fd<<1;i<cnt;i++)
	{
		tmp[i]=0;
	}
	for(register int i=0;i<fd;i++)
	{
		tmp2[i]=qmul(cp[i],qpow(g,(fd-comb(i))%fd));
	}
	for(register int i=fd;i<cnt;i++)
	{
		tmp2[i]=0;
	}
	NTT(tmp,cnt,1),NTT(tmp2,cnt,1);
	for(register int i=0;i<cnt;i++)
	{
		tmp[i]=qmul(tmp[i],tmp2[i]);
	}
	NTT(tmp,cnt,-1);
	for(register int i=0;i<fd;i++)
	{
		cp[i]=qmul(tmp[(fd<<1)-1-i],qpow(g,(fd-comb(i))%fd));
	}
	if(inv==-1)
	{
		ll invl=qpow(fd,MOD-2);
		for(register int i=0;i<fd;i++)
		{
			cp[i]=qmul(cp[i],invl)%MOD; 
		}
	}
}
int main()
{
	fd=read();
	for(register int i=0;i<fd;i++)
	{
		f[i]=read();
	}
	for(register int i=0;i<fd;i++)
	{
		g[i]=read();
	}
	setup(),inv2=qpow(MOD-2,MOD-2),tmp[0]=f[0];
	for(register int i=1,j=fd-1;i<fd;i++,j--)
	{
		tmp[j]=f[i];
	}
	for(register int i=0;i<fd;i++)
	{
		delta[i]=qmul((g[(i+1)%fd]-g[i]+MOD)%MOD,inv2);
	}
	Bluestein(fd,tmp,1),Bluestein(fd,delta,1);
	for(register int i=0;i<fd;i++)
	{
		delta2[i]=qmul(delta[i],qpow(tmp[i],MOD-2));
	}
	Bluestein(fd,delta2,-1),r=-g[0];
	for(register int i=0;i<fd;i++)
	{
		v=delta2[i]<MOD-delta2[i]?delta2[i]:delta2[i]-MOD;
		if(abs(v)>50000)
		{
			return puts("0"),0;
		}
		h[i]=v;
	}
	for(register int i=0;i<fd;i++)
	{
		p++,q+=2*(sum-f[i]),r+=(sum-f[i])*(sum-f[i]);
		sum+=h[i];
	}
	if(sum!=0)
	{
		return puts("0"),0;
	}
	if(q*q-4*p*r>=0)
	{
		s=(ll)(sqrt(q*q-4*p*r)+0.5);
		if(s*s!=q*q-4*p*r)
		{
			return puts("0"),0;
		}
		if((-q+s)%(2*p)==0)
		{
			res.insert((-q+s)/(2*p));
		}
		if((-q-s)%(2*p)==0)
		{
			res.insert((-q-s)/(2*p));
		}
	}
	printf("%d\n",res.size());
	for(it=res.begin();it!=res.end();++it)
	{
		cur=*it;
		for(register int i=0;i<fd;i++)
		{
			printf("%lld ",cur),cur+=h[i];
		}
		puts("");
	}
}
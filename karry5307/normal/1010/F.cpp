#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=262151,MOD=998244353,G=3,INVG=332748118;
struct Edge{
	ll to,prev;
};
struct Polynomial{
	vector<ll>cof;
	inline void assign(ll *l,ll *r)
	{
		cof.assign(l,r);
	}
	inline ll sz()
	{
		return cof.size();
	}
	inline void op()
	{
		for(register int i=0;i<cof.size();i++)
		{
			printf("%d ",cof[i]);
		}
		puts("");
	}
};
typedef pair<Polynomial,Polynomial> pp;
Edge ed[MAXN<<1];
Polynomial p;
vector<Polynomial>v[MAXN];
ll cnt,tot,from,to,x,res,c=1;
ll rev[MAXN],last[MAXN],sz[MAXN],sum[MAXN],ch[MAXN][2];
ll tmp[MAXN],tmp2[MAXN];
inline li read()
{
    register li num=0,neg=1;
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
inline void addEdge(ll from,ll to)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	last[from]=tot;
}
inline void dfs(ll node,ll fa)
{
	sz[node]=1;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=fa)
		{
			ch[node][(bool)ch[node][0]]=ed[i].to;
			dfs(ed[i].to,node),sz[node]+=sz[ed[i].to];
		}
	}
	if(sz[ch[node][0]]<sz[ch[node][1]])
	{
		swap(ch[node][0],ch[node][1]);
	}
}
inline Polynomial operator <<(Polynomial poly,ll x)
{
	Polynomial res=poly;
	for(register int i=0;i<x;i++)
	{
		res.cof.insert(res.cof.begin(),0);
	}
	return res;
}
inline Polynomial operator +(Polynomial poly,ll x)
{
	Polynomial res=poly;
	res.cof[0]=(res.cof[0]+x)%MOD;
	return res;
}
inline Polynomial operator -(Polynomial poly,ll x)
{
	Polynomial res=poly;
	res.cof[0]=(res.cof[0]-x+MOD)%MOD;
	return res;
}
inline Polynomial operator +(Polynomial x,Polynomial y)
{
	Polynomial res;
	res.cof.assign(max(x.sz(),y.sz()),0);
	for(register int i=0;i<x.sz();i++)
	{
		res.cof[i]=x.cof[i];
	}
	for(register int i=0;i<y.sz();i++)
	{
		res.cof[i]=(res.cof[i]+y.cof[i])%MOD;
	}
	return res;
}
inline ll qpow(ll base,ll exponent)
{
    li res=1;
    while(exponent)
    {
        if(exponent&1)
        {
            res=1ll*res*base%MOD;
        }
        base=1ll*base*base%MOD,exponent>>=1;
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
inline Polynomial operator *(Polynomial x,Polynomial y)
{
	Polynomial res;
	ll sz=x.sz(),szz=y.sz(),cnt=1,limit=-1;
	while(cnt<(sz+szz))
	{
		cnt<<=1,limit++;
	}
	for(register int i=0;i<cnt;i++)
	{
		rev[i]=(rev[i>>1]>>1)|((i&1)<<limit);
		tmp[i]=(i<sz?x.cof[i]:0),tmp2[i]=(i<szz?y.cof[i]:0);
	}
	NTT(tmp,cnt,1),NTT(tmp2,cnt,1);
	for(register int i=0;i<cnt;i++)
	{
		tmp[i]=(li)tmp[i]*tmp2[i]%MOD;
	}
	NTT(tmp,cnt,-1),res.assign(tmp,tmp+sz+szz-1);
	return res;
}
inline pp calc(ll l,ll r,ll x)
{
	if(l==r)
	{
		Polynomial poly=v[x][l];
		return make_pair(poly+1,poly);
	}
	ll mid=(l+r)>>1;
	pp l0=calc(l,mid,x),r0=calc(mid+1,r,x);
	return make_pair((l0.first-1)*r0.second+r0.first,l0.second*r0.second);
}
inline Polynomial calc(ll x,ll top)
{
	if(ch[x][0])
	{
		calc(ch[x][0],top);
	}
	if(ch[x][1])
	{
		v[top].push_back(calc(ch[x][1],ch[x][1])<<1);
	}
	else
	{
		Polynomial poly;
		poly.cof={0,1},v[top].push_back(poly);
	}
	if(x==top)
	{
		return calc(0,v[top].size()-1,top).first;
	}
	else
	{
		Polynomial poly;
		return poly;
	}
}
int main()
{
	cnt=read(),x=read()%MOD;
	for(register int i=0;i<cnt-1;i++)
	{
		from=read(),to=read();
		addEdge(from,to),addEdge(to,from);
	}
	dfs(1,0),p=calc(1,1);
	for(register int i=1;i<=cnt;i++)
	{
		res=(res+(li)c*p.cof[i]%MOD)%MOD;
		c=(li)c*qpow(i,MOD-2)%MOD*(x+i)%MOD;
	}
	printf("%d\n",res);
}
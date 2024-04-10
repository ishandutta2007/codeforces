#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=5e5+51; 
struct BIT{
	ll sz;
	ll num[MAXN];
	inline void add(ll pos,ll val)
	{
		for(;pos<=sz;pos+=pos&-pos)
		{
			num[pos]+=val;
		}
	}
	inline ll query(ll pos)
	{
		ll res=0;
		for(;pos;pos-=pos&-pos)
		{
			res+=num[pos];
		}
		return res;
	}
};
BIT bit;
map<ll,ll>mp;
ll n,t,tot,res;
ll x[MAXN];
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
int main()
{
	n=read(),t=read(),mp[0]=mp[t]=1;
	for(register int i=1;i<=n;i++)
	{
		x[i]=read()+x[i-1],mp[x[i]]=mp[x[i]+t]=1;
	}
	for(register map<ll,ll>::iterator it=mp.begin();it!=mp.end();++it)
	{
		(*it).second=++tot;
	}
	bit.sz=tot,bit.add(mp[t],1);
	for(register int i=1;i<=n;i++)
	{
		res+=i-bit.query(mp[x[i]]),bit.add(mp[x[i]+t],1);
	}
	printf("%lld\n",res);
}
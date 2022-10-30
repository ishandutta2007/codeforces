#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e6+51;
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
unordered_map<ll,ll>mp;
ll n;
li res;
ll x[MAXN],pr[MAXN],sf[MAXN];
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
	bit.sz=n=read();
	for(register int i=1;i<=n;i++)
	{
		pr[i]=++mp[x[i]=read()];	
	}	
	mp.clear();
	for(register int i=n;i;i--)
	{
		res+=bit.query(pr[i]-1),bit.add(sf[i]=++mp[x[i]],1);
	}
	printf("%lld\n",res);
}
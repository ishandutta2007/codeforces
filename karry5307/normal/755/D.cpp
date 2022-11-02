#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=1e6+51;
struct BIT{
	ll sz;
	ll num[MAXN];
	inline void add(ll pos)
	{
		for(;pos<=sz;pos+=pos&-pos)
		{
			num[pos]++;
		}
	}
	inline li query(ll pos)
	{
		li res=0;
		for(;pos;pos-=pos&-pos)
		{
			res+=num[pos];
		}
		return res;
	}
};
BIT bit;
ll n,kk,syk,ak;
li res;
ll diff[MAXN];
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
inline li query(ll l,ll r)
{
	return bit.query(r)-bit.query(l-1)+(l>r?bit.query(n):0);
}
int main()
{
	bit.sz=n=read(),kk=read(),kk=min(kk,n-kk),syk=res=1;
	for(register int i=1;i<=n;i++)
	{
		ak=(syk-1+kk)%n+1,res+=query(syk+1,ak-1)+1;
		bit.add(syk),bit.add(ak),printf("%lld ",res),syk=ak;
	}
}
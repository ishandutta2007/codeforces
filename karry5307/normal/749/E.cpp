#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double db;
const ll MAXN=4e5+51;
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
BIT bit,bit2;
ll cnt,q;
db res,p;
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
	bit.sz=bit2.sz=cnt=read();
	for(register int i=1;i<=cnt;i++)
	{
		x[i]=read();
	}
	for(register ll i=1;i<=cnt;i++)
	{
		res+=(db)i*(cnt-i)*(cnt-i+1)/2/cnt/(cnt+1);
	}
	for(register ll i=cnt;i;i--)
	{
		q=bit.query(x[i]-1);
		p-=(db)q*((2*i+2*cnt*i)-(cnt*cnt+cnt))/cnt/(cnt+1);
		p+=(db)(2*i)/cnt/(cnt+1)*bit2.query(x[i]-1);
		bit.add(x[i],1),bit2.add(x[i],i);
	}
	cout<<fixed<<setprecision(20)<<p+res;
}
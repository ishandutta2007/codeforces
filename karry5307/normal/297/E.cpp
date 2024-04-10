#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
struct Segment{
	ll x,y,id;
	inline bool operator <(const Segment &rhs)const
	{
		return x<rhs.x;
	}
	inline bool operator >(const Segment &rhs)const
	{
		return y>rhs.y;
	}
};
struct BIT{
	li x[MAXN];
	inline void add(ll pos,ll val);
	inline li query(ll pos);
};
Segment seg[MAXN];
BIT bit;
ll n,x,y;
li res,res2;
ll l[MAXN],r[MAXN];
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
inline void BIT::add(ll pos,ll val)
{
	for(;pos<=2*n;pos+=pos&-pos)
	{
		x[pos]+=val;
	}
}
inline li BIT::query(ll pos)
{
	li res=0;
	for(;pos;pos-=pos&-pos)
	{
		res+=x[pos];
	}
	return res;
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x=read(),y=read(),x>y?swap(x,y):(void)1,seg[i]=(Segment){x,y,i};
	}
	sort(seg+1,seg+n+1);
	for(register int i=1;i<=n;i++)
	{
		l[seg[i].id]=bit.query(seg[i].x-1)+bit.query(2*n)-bit.query(seg[i].y);
		bit.add(seg[i].y,1);	
	}
	memset(bit.x,0,sizeof(bit.x)),res=(li)n*(n-1)*(n-2)/6;
	for(register int i=n;i;i--)
	{
		r[seg[i].id]=bit.query(seg[i].y-1),bit.add(seg[i].y,1);
	}
	memset(bit.x,0,sizeof(bit.x)),sort(seg+1,seg+n+1,greater<Segment>());
	for(register int i=1;i<=n;i++)
	{
		l[seg[i].id]+=bit.query(2*n)-bit.query(seg[i].y),bit.add(seg[i].x,1);
	}
	for(register int i=1;i<=n;i++)
	{
		res-=(li)l[i]*r[i],res2+=(li)(l[i]+r[i])*(n-l[i]-r[i]-1);
	}
	printf("%lld\n",res-res2/2);
}
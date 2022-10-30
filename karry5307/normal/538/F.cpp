#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
struct Item{
	ll val,id;
	inline bool operator <(const Item &rhs)const
	{
		return val<rhs.val;
	}
};
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
Item x[MAXN];
ll n,cur,v;
ll res[MAXN];
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
		x[i]=(Item){read(),i};
	}
	sort(x+1,x+n+1);
	for(register int i=1;i<=n;)
	{
		cur=i;
		while(cur<=n&&x[cur].val==x[i].val)
		{
			cur++;
		}
		for(register int j=i;j<cur;j++)
		{
			v=x[j].id;
			for(register int k=1;k<=n-1&&k*(v-1)+2<=n;k++)
			{
				res[k]+=bit.query(min(n,k*v+1))-bit.query(k*(v-1)+1);
			}
		}
		for(register int j=i;j<cur;j++)
		{
			bit.add(x[j].id,1);
		}
		i=cur;
	}
	for(register int i=1;i<=n-1;i++)
	{
		printf("%d ",res[i]);
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
struct Item{
	ll l,r;
	inline bool operator <(const Item &rhs)const
	{
		return this->l<rhs.l;
	}
	inline bool operator >(const Item &rhs)const
	{
		return this->r>rhs.r;
	}
};
Item item[MAXN];
ll test,cnt,l,r,mid;
li p;
ll xx[MAXN];
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
inline bool check(ll x)
{
	li cost=0;
	ll gt=0,lt=0,tot=0,ptr=1,ptr2;
	for(register int i=1;i<=cnt;i++)
	{
		if(item[i].r<x)
		{
			cost+=item[i].l,lt++;
			continue;
		}
		else
		{
			if(item[i].l>x)
			{
				cost+=item[i].l,gt++;
				continue;
			}
			else
			{
				xx[++tot]=i;
			}
		}
	}
	ptr2=tot;
	while(ptr<ptr2)
	{
		if(lt<gt)
		{
			cost+=item[xx[ptr++]].l,lt++;
		}
		else
		{
			cost+=x,ptr2--,gt++;
		}
	}
	return cost+x<=p;
}
inline void solve()
{
	cnt=read(),p=read();
	for(register int i=1;i<=cnt;i++)
	{
		item[i].l=read(),item[i].r=read();
	}
	sort(item+1,item+cnt+1,greater<Item>()),r=item[(cnt+1)>>1].r;
	sort(item+1,item+cnt+1),l=item[(cnt+1)>>1].l;
	while(l<=r)
	{
		mid=(l+r)>>1;
		check(mid)?l=mid+1:r=mid-1;
	}
	printf("%d\n",l-1);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
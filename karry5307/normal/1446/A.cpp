#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
struct Item{
	ll val,id;
	inline bool operator <(const Item &rhs)const
	{
		return val<rhs.val;
	}
};
Item it[MAXN];
vector<ll>v;
ll test,n,cap,sm;
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
inline void solve()
{
	n=read(),cap=read(),sm=0,v.clear();
	for(register int i=1;i<=n;i++)
	{
		it[i]=(Item){read(),i};
	}
	sort(it+1,it+n+1);
	for(register int i=1;i<=n;i++)
	{
		if(it[i].val>=(cap+1)/2&&it[i].val<=cap)
		{
			return (void)printf("1\n%d\n",it[i].id);
		}
		if(it[i].val<(cap+1)/2)
		{
			sm+=it[i].val,v.push_back(it[i].id);
			if(sm>=(cap+1)/2)
			{
				printf("%d\n",v.size());
				for(register int i:v)
				{
					printf("%d ",i);
				}
				return (void)puts("");
			 } 
		}
	}
	puts("-1");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
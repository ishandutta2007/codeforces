#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
struct Item{
	ll x,id;
	inline bool operator <(const Item &rhs)const
	{
		return x<rhs.x;
	}
};
Item it[MAXN];
ll n,x,kk;
ll col[MAXN],res[MAXN];
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
	n=read(),kk=read();
	if(n<kk)
	{
		return puts("NO"),0;
	}
	for(register int i=1;i<=n;i++)
	{
		if(++col[x=read()]>kk)
		{
			return puts("NO"),0;
		}
		it[i]=(Item){x,i};
	}
	puts("YES"),sort(it+1,it+n+1);
	for(register int i=1;i<=n;i++)
	{
		res[it[i].id]=(i-1)%kk+1;
	}
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",res[i]);
	}
}
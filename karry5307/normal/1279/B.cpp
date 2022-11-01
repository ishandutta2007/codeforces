#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1e5+51;
ll test,cnt,p,l,mid,r,res;
ll x[MAXN],prefix[MAXN],maxn[MAXN],id[MAXN];
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
inline ll check(ll mid)
{
	return prefix[mid]-maxn[mid]<=p;
}
inline void solve()
{
	cnt=read(),p=read();
	for(register int i=1;i<=cnt;i++)
	{
		x[i]=read(),prefix[i]=prefix[i-1]+x[i],maxn[i]=max(maxn[i-1],x[i]);
		id[i]=id[i-1];
		if(maxn[i]!=maxn[i-1])
		{
			id[i]=i;
		}
	}
	l=1,r=cnt,res=0;
	if(prefix[cnt]<=p)
	{
		puts("0");
		return;
	}
	while(l<=r)
	{
		mid=(l+r)>>1;
		check(mid)?res=id[mid],l=mid+1:r=mid-1;
	}
	printf("%lld\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
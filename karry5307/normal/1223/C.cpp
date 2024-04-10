#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll test,cnt,p,x,q,y,kk,l,r,res,mid;
ll t[MAXN],wt[MAXN];
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
inline bool check(ll mid)
{
	ll res=0;
	for(register int i=1;i<=mid;i++)
	{
		wt[i]=0;
		if(i%p==0)
		{
			wt[i]+=x;
		}
		if(i%q==0)
		{
			wt[i]+=y;
		}
	}
	sort(wt+1,wt+mid+1,greater<ll>());
	for(register int i=1;i<=mid;i++)
	{
		res+=wt[i]*t[i];
	}
	return res>=kk;
}
inline void solve()
{
	cnt=read(),l=1,r=cnt,res=-1;
	for(register int i=1;i<=cnt;i++)
	{
		t[i]=read()/100;
	}
	sort(t+1,t+cnt+1,greater<ll>());
	x=read(),p=read(),y=read(),q=read(),kk=read();
	while(l<=r)
	{
		mid=(l+r)>>1;
		check(mid)?r=mid-1,res=mid:l=mid+1;
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
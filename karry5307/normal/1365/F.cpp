#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef pair<ll,ll> pii;
const ll MAXN=2e5+51;
ll test,n;
ll x[MAXN],y[MAXN];
map<pii,ll>mp;
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
inline pii calc(ll x,ll y)
{
	ll t=min(x,y),t2=max(x,y);
	return (pii){t,t2};
}
inline void solve()
{
	n=read(),mp.clear();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	for(register int i=1;i<=n;i++)
	{
		y[i]=read();
	}
	for(register int i=1,j=n;i<=j;i++,j--)
	{
		mp[calc(x[i],x[j])]++;
	}
	for(register int i=1,j=n;i<=j;i++,j--)
	{
		if(--mp[calc(y[i],y[j])]<0)
		{
			return (void)puts("No");
		}
	}
	if((n&1)&&(y[(n+1)>>1]!=x[(n+1)>>1]))
	{
		return (void)puts("No");
	}
	puts("Yes");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
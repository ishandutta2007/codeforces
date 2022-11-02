#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
unordered_map<ll,ll>mp;
ll test,n,qcnt,c;
ll x[MAXN],prefix[MAXN];
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
inline void calc(ll l,ll r)
{
	mp[prefix[r]-prefix[l-1]]=1;
	if(x[l]==x[r])
	{
		return;
	}
	ll mid=upper_bound(x+1,x+n+1,(x[l]+x[r])>>1)-x-1;
	calc(l,mid),calc(mid+1,r);
}
inline void solve()
{
	n=read(),qcnt=read(),mp.clear();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	sort(x+1,x+n+1);
	for(register int i=1;i<=n;i++)
	{
		prefix[i]=prefix[i-1]+x[i];
	}
	calc(1,n);
	for(register int i=1;i<=qcnt;i++)
	{
		puts(mp[read()]?"Yes":"No");
	}
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
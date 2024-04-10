#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
const ll MAXN=2e5+51;
map<ll,ll>mp;
ll test,n,res,totd,sm;
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
inline void solve()
{
	n=read(),mp.clear(),sm=0,res=2e18,totd=0;
	for(register int i=1;i<=n;i++)
	{
		mp[read()]++;
	}
	for(auto i:mp)
	{
		sm+=(x[++totd]=i.second);
	}
	sort(x+1,x+totd+1);
	for(register int i=1;i<=totd;i++)
	{
		res=min(res,sm-(totd-i+1)*x[i]);
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
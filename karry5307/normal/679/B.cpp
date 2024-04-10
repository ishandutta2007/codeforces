#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef pair<ll,ll> pii;
const ll MAXN=2e5+51;
ll n;
pii res;
ll pw[MAXN];
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
inline void dfs(ll r,ll cur,ll v)
{
	if(!r)
	{
		return (void)(res=max(res,(pii){cur,v}));
	}
	ll c=upper_bound(pw+1,pw+100001,r)-pw-1;
	dfs(r-pw[c],cur+1,v+pw[c]),c?dfs(pw[c]-1-pw[c-1],cur+1,v+pw[c-1]):(void)1;
}
int main()
{
	n=read();
	for(register int i=1;i<=100000;i++)
	{
		pw[i]=(ll)i*i*i;
	}
	dfs(n,0,0),printf("%lld %lld\n",res.first,res.second);
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
typedef pair<ll,ll> pii;
const ll MAXN=2e5+51;
unordered_map<ll,vector<pii> >mp;
ll test,n,v,l,r,res,cur;
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
	n=read(),res=0x3f3f3f3f,x[n+1]=0,mp.clear();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	for(register int i=1;i<=n+1;i++)
	{
		x[i]!=x[i-1]?mp[x[i-1]].push_back((pii){l,r}),l=i:1,r=i;
	}
	for(auto i:mp)
	{
		if(!i.first)
		{
			continue;
		}
		cur=i.second.size()+1;
		i.second[0].first==1?cur--:1,i.second.back().second==n?cur--:1;
		res=min(res,cur);
	}
	printf("%d\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
map<ll,ll>mp,mp2;
ll test,n,x;
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
	n=read(),mp.clear(),mp2.clear();
	for(register int i=1;i<=n;i++)
	{
		mp[x=read()]++,mp2[x]=i;
	}
	for(auto i:mp)
	{
		if(i.second==1)
		{
			return (void)printf("%d\n",mp2[i.first]);
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
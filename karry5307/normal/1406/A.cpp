#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
bitset<151>s,t;
map<ll,ll>mp;
ll test,n;
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
	n=read(),s.set(),t.set(),mp.clear();
	for(register int i=1;i<=n;i++)
	{
		mp[read()]++;
	}
	for(auto i:mp)
	{
		i.second>1?s[i.first]=t[i.first]=0:s[i.first]=0;
	}
	printf("%d\n",s._Find_first()+t._Find_first());
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
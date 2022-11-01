#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
vector<ll>v;
ll test,n,cur;
ll x[MAXN],y[MAXN];
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
	n=read(),cur=0,v.clear();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	for(register int i=1;i<=n;i++)
	{
		if(!(y[i]=read()))
		{
			v.push_back(x[i]);
		}
	}
	sort(v.begin(),v.end(),greater<ll>());
	for(register int i=1;i<=n;i++)
	{
		if(!y[i])
		{
			x[i]=v[cur++];
		}
	}
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",x[i]),x[i]=y[i]=0;
	}
	puts("");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
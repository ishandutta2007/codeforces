#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
priority_queue<ll>q;
ll test,n,m,x,sm,res;
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
	n=read(),m=read(),sm=0,res=0;
	while(!q.empty())
	{
		q.pop();
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=m;j++)
		{
			x=read(),q.push(-2*x),sm+=x;
		}
	}
	res=sm;
	while(q.size()>=2)
	{
		sm+=q.top(),q.pop(),sm+=q.top(),q.pop(),res=max(res,sm);
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
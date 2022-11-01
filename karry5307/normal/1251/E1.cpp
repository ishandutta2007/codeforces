#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
vector<ll>v[MAXN];
priority_queue<ll,vector<ll>,greater<ll> >pq;
ll test,cnt,p,q;
li res;
ll x[MAXN],cost[MAXN];
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
	p=cnt=read(),res=q=0;
	for(register int i=0;i<cnt;i++)
	{
		x[i]=read(),cost[i]=read();
		v[x[i]].push_back(cost[i]);
	}
	for(register int i=cnt-1;i>=0;i--)
	{
		p-=v[i].size();
		for(register int j:v[i])
		{
			pq.push(j);
		}
		while(p+q<i)
		{
			q++,res+=pq.top(),pq.pop();
		}
	}
	printf("%lld\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
		for(register int j=0;j<cnt;j++)
		{
			v[j].clear();
		}
		while(!pq.empty())
		{
			pq.pop();
		}
	}
}
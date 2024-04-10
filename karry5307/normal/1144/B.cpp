#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
priority_queue<ll>q[2];
ll n,x,sm;
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
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x=read(),sm+=x,q[x&1].push(x); 
	}
	for(register int i=1;!q[0].empty()&&!q[1].empty();i++)
	{
		sm-=q[0].top()+q[1].top(),q[0].pop(),q[1].pop();
	}
	sm-=max(q[0].empty()?0:q[0].top(),q[1].empty()?0:q[1].top());
	printf("%lld\n",sm);
}
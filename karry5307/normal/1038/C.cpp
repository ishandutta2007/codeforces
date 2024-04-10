#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll n;
ll c[2];
priority_queue<ll>q[2];
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
		q[0].push(read());
	}
	for(register int i=1;i<=n;i++)
	{
		q[1].push(read());
	}
	for(register int i=1,j=0;i<=2*n;i++,j^=1)
	{
		if(q[j].empty()||(!q[j^1].empty()&&q[j].top()<q[j^1].top()))
		{
			q[j^1].pop();
			continue;
		}
		if(q[j^1].empty()||(!q[j].empty()&&q[j].top()>=q[j^1].top()))
		{
			c[j]+=q[j].top(),q[j].pop();
			continue;
		}
	}
	printf("%lld\n",c[0]-c[1]);
}
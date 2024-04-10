#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1;
ll test,p,q,r,s,t;
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
	p=read(),q=read(),r=read(),s=read(),t=read();
	if((ll)(ceil(1.0*p/r))+(ll)(ceil(1.0*q/s))>t)
	{
		return (void)(puts("-1"));
	}
	printf("%lld %lld\n",(ll)(ceil(1.0*p/r)),(ll)(ceil(1.0*q/s)));
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
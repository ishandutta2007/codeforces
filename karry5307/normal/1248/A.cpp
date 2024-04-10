#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll test,cnt;
ll p[2],q[2];
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
	p[0]=q[0]=p[1]=q[1]=0;
	cnt=read();
	for(register int i=0;i<cnt;i++)
	{
		p[read()&1]++;
	}
	cnt=read();
	for(register int i=0;i<cnt;i++)
	{
		q[read()&1]++;
	}
	printf("%lld\n",p[0]*q[0]+p[1]*q[1]);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=2e5+51;
ll test;
ll x,y,days,t;
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
	x=read(),y=read(),days=0x3f3f3f3f;
	for(register int i=0;i<=x;i++)
	{
		t=i+(ll)ceil(1.0*y/(i+1));
		if(days<t)
		{
			break;
		}
		days=t;
	}
	puts(days<=x?"YES":"NO");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
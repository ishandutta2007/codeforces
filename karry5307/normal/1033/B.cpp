#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll test,x,y;
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
	x=read(),y=read();
	if(x-y!=1)
	{
		return (void)puts("NO");
	}
	for(register int i=2;i<=sqrt(x+y);i++)
	{
		if((x+y)%i==0)
		{
			return (void)puts("NO");
		}
	}
	puts("YES");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}	
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll test,r,g,b,w;
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
	r=read(),g=read(),b=read(),w=read();
	if((r&1)+(g&1)+(b&1)+(w&1)<=1)
	{
		return (void)puts("Yes");
	}
	if(!r||!g||!b)
	{
		return (void)puts("No");
	}
	return (void)puts((r&1)+(g&1)+(b&1)+(w&1)==2?"No":"Yes");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1;
ll test;
ll x[3];
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
	x[0]=read(),x[1]=read(),x[2]=read(),sort(x,x+3);
	if(x[2]-x[1]-x[0]>1)
	{
		puts("No");
	}
	else
	{
		puts("Yes");
	}
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
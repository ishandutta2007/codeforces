#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e5+51;
ll test,x;
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
	x=read();
	if(x&1)
	{
		printf("7");
		for(register int i=0;i<((x-3)>>1);i++)
		{
			printf("1");
		}
		puts("");
	}
	else
	{
		for(register int i=0;i<x>>1;i++)
		{
			printf("1");
		}
		puts("");
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
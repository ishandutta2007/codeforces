#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=2e5+51;
ll test,cnt,maxn,minn;
ll perm[MAXN],rp[MAXN];
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
	cnt=read(),maxn=-0x3f3f3f3f,minn=0x3f3f3f3f;
	for(register int i=1;i<=cnt;i++)
	{
		rp[perm[i]=read()]=i;
	}
	for(register int i=1;i<=cnt;i++)
	{
		maxn=max(maxn,rp[i]),minn=min(minn,rp[i]);
		putchar(maxn-minn==i-1?'1':'0');
	}
	puts("");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
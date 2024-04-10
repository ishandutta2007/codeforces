#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1;
ll test,cnt,k1,k2,x,win;
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
	cnt=read(),k1=read(),k2=read();
	for(register int i=0;i<k1;i++)
	{
		if(read()==cnt)
		{
			win=1;
		}
	}
	for(register int i=0;i<k2;i++)
	{
		if(read()==cnt)
		{
			win=2;
		}
	}
	puts(win==1?"YES":"NO");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
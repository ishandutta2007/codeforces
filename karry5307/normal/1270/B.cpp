#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=2e5+51;
ll test,cnt;
ll x[MAXN];
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
	cnt=read();
	for(register int i=0;i<cnt;i++)
	{
		x[i]=read();
	}
	for(register int i=0;i<cnt-1;i++)
	{
		if(abs(x[i]-x[i+1])>1)
		{
			puts("Yes");
			printf("%d %d\n",i+1,i+2);
			return;
		}
	}
	puts("No");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
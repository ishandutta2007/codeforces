#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1e5+51;
ll test,cnt,x,odd,even,sm;
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
	cnt=read(),even=0,odd=0,sm=0;
	for(register int i=0;i<cnt;i++)
	{
		x=read(),odd+=x&1;
	}
	if(odd==cnt&&(cnt&1)||odd&&(cnt-odd))
	{
		puts("YES");
		return; 
	}
	puts("NO");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
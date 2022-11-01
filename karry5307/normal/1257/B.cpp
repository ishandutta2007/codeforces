#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
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
	if(x==y)
	{
		return (void)(puts("YES"));
	}
	if(x==1)
	{
		return (void)(puts("NO"));
	}
	x-=x&1,puts(x==2?(y>3?"NO":"YES"):"YES");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
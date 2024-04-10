#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
ll test,u,d,l,r,x,y,xl,yl,xr,yr;
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
	l=read(),r=read(),d=read(),u=read();
	x=read(),y=read(),xl=read(),yl=read(),xr=read(),yr=read();
	if((u||d)&&yl==yr)
	{
		return (void)puts("No");
	}
	if((l||r)&&xl==xr)
	{
		return (void)puts("No");
	}
	y+=(u-d),x+=(r-l);
	if(xl<=x&&x<=xr&&yl<=y&&y<=yr)
	{
		puts("Yes");
		return;
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
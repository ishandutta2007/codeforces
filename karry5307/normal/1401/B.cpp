#include<bits/stdc++.h>
using namespace std;
typedef int ll; 
typedef long long int li;
const ll MAXN=2e5+51;
ll test,x0,x1,x2,y0,y1,y2,syk;
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
	x0=read(),x1=read(),x2=read(),y0=read(),y1=read(),y2=read();
	syk=min(x0,y2),x0-=syk,y2-=syk,syk=min(x1,y0),x1-=syk,y0-=syk;
	syk=min(x2,y1),x2-=syk,y1-=syk,printf("%d\n",2*syk-2*min(x1,y2));
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
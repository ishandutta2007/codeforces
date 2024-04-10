#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=1;
ll test,x,y,z,res;
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
	x=read(),y=read(),z=read(),res=0;
	if(z>=(y<<1))
	{
		return (void)(printf("%d\n",y*3));
	}
	y-=(z>>1),res+=(z>>1)*3;
	printf("%d\n",y>=(x<<1)?res+x*3:res+(y>>1)*3);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
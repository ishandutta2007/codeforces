#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n;
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
	n=read();
	if(n==1||n==2||n==4)
	{
		return (void)puts("-1");
	}
	if(n%3==0)
	{
		return (void)printf("%d 0 0\n",n/3);
	}
	if(n%3==1)
	{
		return (void)printf("%d 0 1\n",(n-7)/3);
	}
	if(n%3==2)
	{
		return (void)printf("%d 1 0\n",(n-5)/3);
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
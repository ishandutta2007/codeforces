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
	if(n==1)
	{
		return (void)puts("1");
	}
	if(n==2)
	{
		return (void)puts("2\n1 2");
	}
	puts("2"),printf("%d %d\n%d %d\n",n-2,n,n-1,n-1);
	for(register int i=n-3;i>=1;i--)
	{
		printf("%d %d\n",i,i+2);	
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
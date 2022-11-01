#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e3+51; 
ll test,n,u,v,w;
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
	u=read(),v=read(),w=read(),n=read();
	if((u+v+w+n)%3)
	{
		return (void)puts("No");
	}
	n=(u+v+w+n)/3,puts(n>=u&&n>=v&&n>=w?"Yes":"No");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}